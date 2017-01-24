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

#ifndef __LINUX_EXTIO_H
#define __LINUX_EXTIO_H

#ifdef __KERNEL__

#include <linux/acpi.h>
#include <linux/fwnode.h>

struct extio_ops {
	u64 (*pfin)(void *devobj, unsigned long ptaddr,	size_t dlen);
	void (*pfout)(void *devobj, unsigned long ptaddr, u32 outval,
					size_t dlen);
	u64 (*pfins)(void *devobj, unsigned long ptaddr, void *inbuf,
				size_t dlen, unsigned int count);
	void (*pfouts)(void *devobj, unsigned long ptaddr,
				const void *outbuf, size_t dlen,
				unsigned int count);
};

struct extio_node {
	unsigned long bus_start;	/* bus start address */
	unsigned long io_start;	/* io port token corresponding to bus_start */
	size_t range_size;	/* size of the extio node operating range */
	struct fwnode_handle *fwnode;
	struct list_head list;
	struct extio_ops *ops;	/* ops operating on this node */
	void *devpara;	/* private parameter of the host device */
};

extern u8 extio_inb(unsigned long addr);
extern void extio_outb(u8 value, unsigned long addr);
extern void extio_outw(u16 value, unsigned long addr);
extern void extio_outl(u32 value, unsigned long addr);
extern u16 extio_inw(unsigned long addr);
extern u32 extio_inl(unsigned long addr);
extern void extio_outb(u8 value, unsigned long addr);
extern void extio_outw(u16 value, unsigned long addr);
extern void extio_outl(u32 value, unsigned long addr);
extern void extio_insb(unsigned long addr, void *buffer, unsigned int count);
extern void extio_insl(unsigned long addr, void *buffer, unsigned int count);
extern void extio_insw(unsigned long addr, void *buffer, unsigned int count);
extern void extio_outsb(unsigned long addr, const void *buffer,
			unsigned int count);
extern void extio_outsw(unsigned long addr, const void *buffer,
			unsigned int count);
extern void extio_outsl(unsigned long addr, const void *buffer,
			unsigned int count);

#ifdef CONFIG_INDIRECT_PIO
extern struct extio_node *extio_find_node(struct fwnode_handle *node);

extern unsigned long
extio_translate(struct fwnode_handle *node, unsigned long bus_addr);
#else
static inline struct extio_node *extio_find_node(struct fwnode_handle *node)
{
	return NULL;
}

static inline unsigned long
extio_translate(struct fwnode_handle *node, unsigned long bus_addr)
{
	return -1;
}
#endif
extern void register_extio(struct extio_node *node);

extern int acpi_set_extio_resource(struct acpi_device *adev,
		struct acpi_device *host);

#endif /* __KERNEL__ */
#endif /* __LINUX_EXTIO_H */
