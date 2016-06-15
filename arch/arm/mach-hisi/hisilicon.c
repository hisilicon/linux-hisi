/*
 * (Hisilicon's SoC based) flattened device tree enabled machine
 *
 * Copyright (c) 2012-2013 Hisilicon Ltd.
 * Copyright (c) 2012-2013 Linaro Ltd.
 *
 * Author: Haojian Zhuang <haojian.zhuang@linaro.org>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
*/

#include <linux/clocksource.h>
#include <linux/irqchip.h>
#include <linux/of_fdt.h>

#include <asm/mach/arch.h>
#include <asm/mach/map.h>

#define HI3620_SYSCTRL_PHYS_BASE		0xfc802000
#define HI3620_SYSCTRL_VIRT_BASE		0xfe802000

/*
 * This table is only for optimization. Since ioremap() could always share
 * the same mapping if it's defined as static IO mapping.
 *
 * Without this table, system could also work. The cost is some virtual address
 * spaces wasted since ioremap() may be called multi times for the same
 * IO space.
 */
static struct map_desc hi3620_io_desc[] __initdata = {
	{
		/* sysctrl */
		.pfn		= __phys_to_pfn(HI3620_SYSCTRL_PHYS_BASE),
		.virtual	= HI3620_SYSCTRL_VIRT_BASE,
		.length		= 0x1000,
		.type		= MT_DEVICE,
	},
};

static void __init hisilicon_map_io(void)
{
	unsigned long root = of_get_flat_dt_root();
	debug_ll_io_init();
	if (of_flat_dt_is_compatible(root, "hisilicon,hi3620-hi4511"))
		iotable_init(hi3620_io_desc, ARRAY_SIZE(hi3620_io_desc));
}

static const char *const hisilicon_compat[] __initconst = {
	"hisilicon,hi3519",
	"hisilicon,hi3620-hi4511",
	"hisilicon,hip01",
	"hisilicon,hip01-ca9x2",
	"hisilicon,hip04-d01",
	"hisilicon,hix5hd2",
	NULL,
};

DT_MACHINE_START(HISILICON_DT, "HiSilicon Soc")
	.dt_compat	= hisilicon_compat,
	.map_io		= hisilicon_map_io,
MACHINE_END
