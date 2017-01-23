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
