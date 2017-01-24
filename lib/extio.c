/*
 * Copyright (C) 2016 Hisilicon Limited, All Rights Reserved.
 * Author: Zhichang Yuan <yuanzhichang@hisilicon.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <linux/io.h>
#include <linux/spinlock.h>

static LIST_HEAD(extio_dev_list);
static DEFINE_RWLOCK(extio_list_lock);

void register_extio(struct extio_node *node)
{
	write_lock(&extio_list_lock);
	list_add_tail(&node->list, &extio_dev_list);
	write_unlock(&extio_list_lock);
}

static struct extio_node *find_extio_token(unsigned long addr)
{
	struct extio_node *extio_entry;

	read_lock(&extio_list_lock);
	list_for_each_entry(extio_entry, &extio_dev_list, list) {
		if ((addr < extio_entry->io_start + extio_entry->range_size) &&
			(addr >= extio_entry->io_start))
			break;
	}
	read_unlock(&extio_list_lock);
	return (&extio_entry->list == &extio_dev_list) ? NULL : extio_entry;
}

struct extio_node *extio_find_node(struct fwnode_handle *node)
{
	struct extio_node *entry;

	read_lock(&extio_list_lock);
	list_for_each_entry(entry, &extio_dev_list, list) {
		if (entry->fwnode == node)
			break;
	}
	read_unlock(&extio_list_lock);

	return (&entry->list == &extio_dev_list) ? NULL : entry;
}

unsigned long extio_translate(struct fwnode_handle *node,
		unsigned long bus_addr)
{
	struct extio_node *entry;
	unsigned long port_id = -1;

	read_lock(&extio_list_lock);
	list_for_each_entry(entry, &extio_dev_list, list) {
		if (entry->fwnode == node &&
			bus_addr >= entry->bus_start &&
			bus_addr - entry->bus_start < entry->range_size)
			port_id = entry->io_start + bus_addr -
					entry->bus_start;
	}
	read_unlock(&extio_list_lock);

	return port_id;
}

static inline bool acpi_extio_supported_resource(struct acpi_resource *res)
{
	switch (res->type) {
	case ACPI_RESOURCE_TYPE_ADDRESS16:
	case ACPI_RESOURCE_TYPE_ADDRESS32:
	case ACPI_RESOURCE_TYPE_ADDRESS64:
		return true;
	}
	return false;
}

static acpi_status acpi_count_extiores(struct acpi_resource *res,
					   void *data)
{
	int *res_cnt = data;

	if (acpi_extio_supported_resource(res) &&
		!acpi_dev_filter_resource_type(res, IORESOURCE_IO))
		(*res_cnt)++;

	return AE_OK;
}

static acpi_status acpi_read_one_extiores(struct acpi_resource *res,
		void *data)
{
	struct acpi_resource **resource = data;

	if (acpi_extio_supported_resource(res) &&
		!acpi_dev_filter_resource_type(res, IORESOURCE_IO)) {
		memcpy((*resource), res, sizeof(struct acpi_resource));
		(*resource)->length = sizeof(struct acpi_resource);
		(*resource)->type = res->type;
		(*resource)++;
	}

	return AE_OK;
}

static acpi_status
acpi_build_extiores_template(struct acpi_device *adev,
			struct acpi_buffer *buffer)
{
	acpi_handle handle = adev->handle;
	struct acpi_resource *resource;
	acpi_status status;
	int res_cnt = 0;

	status = acpi_walk_resources(handle, METHOD_NAME__PRS,
				     acpi_count_extiores, &res_cnt);
	if (ACPI_FAILURE(status) || !res_cnt) {
		dev_err(&adev->dev, "can't evaluate _CRS: %d\n", status);
		return -EINVAL;
	}

	buffer->length = sizeof(struct acpi_resource) * (res_cnt + 1) + 1;
	buffer->pointer = kzalloc(buffer->length - 1, GFP_KERNEL);
	if (!buffer->pointer)
		return -ENOMEM;

	resource = (struct acpi_resource *)buffer->pointer;
	status = acpi_walk_resources(handle, METHOD_NAME__PRS,
				     acpi_read_one_extiores, &resource);
	if (ACPI_FAILURE(status)) {
		kfree(buffer->pointer);
		dev_err(&adev->dev, "can't evaluate _PRS: %d\n", status);
		return -EINVAL;
	}

	resource->type = ACPI_RESOURCE_TYPE_END_TAG;
	resource->length = sizeof(struct acpi_resource);

	return 0;
}

static int acpi_translate_extiores(struct acpi_device *adev,
		struct acpi_device *host, struct acpi_buffer *buffer)
{
	int res_cnt = (buffer->length - 1) / sizeof(struct acpi_resource) - 1;
	struct acpi_resource *resource = buffer->pointer;
	struct acpi_resource_address64 addr;
	unsigned long sys_port;
	struct device *dev = &adev->dev;

	/* only one I/O resource now */
	if (res_cnt != 1) {
		dev_err(dev, "encode %d resources whose type is(%d)!\n",
			res_cnt, resource->type);
		return -EINVAL;
	}

	if (ACPI_FAILURE(acpi_resource_to_address64(resource, &addr))) {
		dev_err(dev, "convert acpi resource(%d) as addr64 FAIL!\n",
			resource->type);
		return -EFAULT;
	}

	/* For indirect-IO, addr length must be fixed. (>0, 0, 0) */
	if (!addr.address.address_length || addr.min_address_fixed ||
		addr.max_address_fixed) {
		dev_warn(dev, "variable I/O resource is invalid!\n");
		return -EINVAL;
	}

	sys_port = extio_translate(&host->fwnode, addr.address.minimum);
	if (sys_port == -1) {
		dev_err(dev, "translate bus-addr(0x%llx) fail!\n",
			addr.address.minimum);
		return -EFAULT;
	}

	switch (resource->type) {
	case ACPI_RESOURCE_TYPE_ADDRESS16:
	{
		struct acpi_resource_address16 *out_res;

		out_res = &resource->data.address16;
		out_res->address.minimum = sys_port;
		out_res->address.maximum = sys_port +
			addr.address.address_length - 1;

		dev_info(dev, "_SRS 16IO: [0x%x - 0x%x]\n",
			out_res->address.minimum,
			out_res->address.maximum);

		break;
	}

	case ACPI_RESOURCE_TYPE_ADDRESS32:
	{
		struct acpi_resource_address32 *out_res;

		out_res = &resource->data.address32;
		out_res->address.minimum = sys_port;
		out_res->address.maximum = sys_port +
			addr.address.address_length - 1;

		dev_info(dev, "_SRS 32IO: [0x%x - 0x%x]\n",
			out_res->address.minimum,
			out_res->address.maximum);

		break;
	}

	case ACPI_RESOURCE_TYPE_ADDRESS64:
	{
		struct acpi_resource_address64 *out_res;

		out_res = &resource->data.address64;
		out_res->address.minimum = sys_port;
		out_res->address.maximum = sys_port +
			addr.address.address_length - 1;

		dev_info(dev, "_SRS 64IO: [0x%llx - 0x%llx]\n",
			out_res->address.minimum,
			out_res->address.maximum);

		break;
	}

	default:
		return -EINVAL;

	}

	return 0;
}

/*
 * update/set the current I/O resource of the designated device node.
 * after this calling, the enumeration can be started as the I/O resource
 * had been translated to logicial I/O from bus-local I/O.
 *
 * @adev: the device node to be updated the I/O resource;
 * @host: the device node where 'adev' is attached, which can be not
 *	the parent of 'adev';
 *
 * return 0 when successful, negative is for failure.
 */
int acpi_set_extio_resource(struct acpi_device *adev,
		struct acpi_device *host)
{
	struct device *dev = &adev->dev;
	struct acpi_buffer buffer;
	acpi_status status;
	int ret;

	if (!host)
		return -EINVAL;

	/* check the device state */
	if (!adev->status.present) {
		dev_info(dev, "ACPI: device is not present!\n");
		return 0;
	}
	/* whether the child had been enumerated? */
	if (acpi_device_enumerated(adev)) {
		dev_info(dev, "ACPI: had been enumerated!\n");
		return 0;
	}

	/* read the _PRS and convert as acpi_buffer */
	status = acpi_build_extiores_template(adev, &buffer);
	if (ACPI_FAILURE(status)) {
		dev_warn(dev, "Failure evaluating %s\n",
				METHOD_NAME__PRS);
		return -ENODEV;
	}

	/* translate the I/O resources */
	ret = acpi_translate_extiores(adev, host, &buffer);
	if (ret) {
		kfree(buffer.pointer);
		dev_err(dev, "Translate I/O range FAIL!\n");
		return ret;
	}

	/* set current resource... */
	status = acpi_set_current_resources(adev->handle, &buffer);
	kfree(buffer.pointer);
	if (ACPI_FAILURE(status)) {
		dev_err(dev, "Error evaluating _SRS (0x%x)\n", status);
		ret = -EIO;
	}

	return ret;
}

#ifdef PCI_IOBASE

#define BUILD_EXTIO(bw, type)						\
type extio_in##bw(unsigned long addr)					\
{									\
	struct extio_node *extio_entry = find_extio_token(addr);	\
									\
	if (!extio_entry)						\
		return read##bw(PCI_IOBASE + addr);			\
	return extio_entry->ops->pfin ?					\
			extio_entry->ops->pfin(extio_entry->devpara,	\
			addr, sizeof(type)) : -1;			\
}									\
									\
void extio_out##bw(type value, unsigned long addr)			\
{									\
	struct extio_node *extio_entry = find_extio_token(addr);	\
									\
	if (!extio_entry)						\
		write##bw(value, PCI_IOBASE + addr);			\
	else if (extio_entry->ops->pfout)				\
		extio_entry->ops->pfout(extio_entry->devpara,		\
				addr, value, sizeof(type));		\
}									\
									\
void extio_ins##bw(unsigned long addr, void *buffer, unsigned int count)\
{									\
	struct extio_node *extio_entry = find_extio_token(addr);	\
									\
	if (!extio_entry)						\
		reads##bw(PCI_IOBASE + addr, buffer, count);		\
	else if (extio_entry->ops->pfins)				\
		extio_entry->ops->pfins(extio_entry->devpara,		\
				addr, buffer, sizeof(type), count);	\
}									\
									\
void extio_outs##bw(unsigned long addr, const void *buffer,		\
		    unsigned int count)					\
{									\
	struct extio_node *extio_entry = find_extio_token(addr);	\
									\
	if (!extio_entry)						\
		writes##bw(PCI_IOBASE + addr, buffer, count);		\
	else if (extio_entry->ops->pfouts)				\
		extio_entry->ops->pfouts(extio_entry->devpara,		\
				addr, buffer, sizeof(type), count);	\
}

BUILD_EXTIO(b, u8)

EXPORT_SYMBOL(extio_inb);
EXPORT_SYMBOL(extio_outb);
EXPORT_SYMBOL(extio_insb);
EXPORT_SYMBOL(extio_outsb);

BUILD_EXTIO(w, u16)

EXPORT_SYMBOL(extio_inw);
EXPORT_SYMBOL(extio_outw);
EXPORT_SYMBOL(extio_insw);
EXPORT_SYMBOL(extio_outsw);

BUILD_EXTIO(l, u32)

EXPORT_SYMBOL(extio_inl);
EXPORT_SYMBOL(extio_outl);
EXPORT_SYMBOL(extio_insl);
EXPORT_SYMBOL(extio_outsl);

#endif /* PCI_IOBASE */
