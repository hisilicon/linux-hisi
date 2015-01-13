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

#include <linux/clk-provider.h>
#include <linux/clocksource.h>
#include <linux/irqchip.h>
#include <linux/delay.h>
#include <linux/of_address.h>
#include <linux/of_platform.h>

#include <asm/mach/arch.h>
#include <asm/mach/map.h>

#define HI3620_SYSCTRL_PHYS_BASE		0xfc802000
#define HI3620_SYSCTRL_VIRT_BASE		0xfe802000

static void __iomem *gb3 = NULL; 

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

static void __init hi3620_map_io(void)
{
	debug_ll_io_init();
	iotable_init(hi3620_io_desc, ARRAY_SIZE(hi3620_io_desc));
}

static const char *hi3xxx_compat[] __initconst = {
	"hisilicon,hi3620-hi4511",
	NULL,
};

static void __init hip04_init_machine(void)
{
	unsigned int data, mask;
	of_platform_populate(NULL, of_default_bus_match_table, NULL, NULL);

	gb3 = ioremap(0xe4003000, 0x1000);
	if (!gb3) {
		pr_err("failed to map GB3\n");
		return;
	}
	mask = 0xffdfffff;
	/* read GPIO3_SWPORT_DDR */
	data = readl_relaxed(gb3 + 4);
	if (!(data & ~mask)) {
		/* switch GPIO direction from IN to OUT */
		writel_relaxed(data | ~mask, gb3 + 4);
	}
	data = readl_relaxed(gb3);
	/* write high to GPIO117 to disable watchdog */
	writel_relaxed(data | ~mask, gb3);
}

static void hip04_restart(enum reboot_mode mode, const char *cmd)
{
	unsigned int data, mask;

	if (!gb3) {
		pr_err("GB3 isn't initialized\n");
		return;
	}
	mask = 0xffdfffff;
	/* read GPIO3_SWPORT_DDR */
	data = readl_relaxed(gb3 + 4);
	if (!(data & ~mask)) {
		/* switch GPIO direction from IN to OUT */
		writel_relaxed(data | ~mask, gb3 + 4);
	}
	data = readl_relaxed(gb3);
	/* write low to GPIO117 */
	writel_relaxed(data & mask, gb3);
	udelay(100);
	/* write high to GPIO117 to disable watchdog */
	writel_relaxed(data | ~mask, gb3);
	udelay(100);
	/* write low to GPIO117 */
	writel_relaxed(data & mask, gb3);
	udelay(100);
}

DT_MACHINE_START(HI3620, "Hisilicon Hi3620 (Flattened Device Tree)")
	.map_io		= hi3620_map_io,
	.dt_compat	= hi3xxx_compat,
MACHINE_END

static const char *hix5hd2_compat[] __initconst = {
	"hisilicon,hix5hd2",
	NULL,
};

DT_MACHINE_START(HIX5HD2_DT, "Hisilicon HIX5HD2 (Flattened Device Tree)")
	.dt_compat	= hix5hd2_compat,
MACHINE_END

static const char *hip04_compat[] __initconst = {
	"hisilicon,hip04-d01",
	NULL,
};

DT_MACHINE_START(HIP04, "Hisilicon HiP04 (Flattened Device Tree)")
	.dt_compat	= hip04_compat,
	.init_machine	= hip04_init_machine,
	.restart	= hip04_restart,
MACHINE_END
