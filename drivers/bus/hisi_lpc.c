#include <linux/errno.h>
#include <linux/delay.h>
#include <linux/io.h>
#include <linux/module.h>
#include <linux/platform_device.h>
#include <linux/slab.h>
#include <linux/spinlock.h>
#include <linux/version.h>
#include <linux/of_platform.h>
#include <linux/iopoll.h>


#define LPC_REG_START            (0x00)
#define LPC_REG_OP_STATUS        (0x04)
#define LPC_REG_IRQ_ST           (0x08)
#define LPC_REG_OP_LEN           (0x10)
#define LPC_REG_CMD              (0x14)
#define LPC_REG_ADDR             (0x20)
#define LPC_REG_WDATA            (0x24)
#define LPC_REG_RDATA            (0x28)

#define LPC_CMD_SAMEADDR_SING    (0x00000008)
#define LPC_CMD_SAMEADDR_INC     (0x00000000)
#define LPC_CMD_TYPE_IO          (0x00000000)
#define LPC_CMD_TYPE_MEM         (0x00000002)
#define LPC_CMD_TYPE_FWH         (0x00000004)
#define LPC_CMD_WRITE            (0x00000001)
#define LPC_CMD_READ             (0x00000000)

#define LPC_IRQ_CLEAR            (0x02)
#define LPC_IRQ_OCCURRED         (0x02)
#define LPC_STATUS_DILE          (0x01)
#define LPC_OP_FINISHED          (0x02)
#define START_WORK               (0x01)


struct lpc_dev {
	spinlock_t lock;
	void __iomem  *regs;
	struct device *dev;
};

static struct lpc_dev *lpc_dev;

static int lpc_master_write(unsigned int addr, unsigned char *buf,
			    unsigned int len)
{
	unsigned int i;
	unsigned int lpc_cmd_value;
	unsigned int lpc_op_state_value;
	u32 tmp;

	/* para check */
	if (!buf || !len)
		return -EINVAL;

	writel(LPC_IRQ_CLEAR, lpc_dev->regs + LPC_REG_IRQ_ST);
	if (readl_poll_timeout_atomic(lpc_dev->regs + LPC_REG_OP_STATUS, tmp,
				     tmp & LPC_STATUS_DILE, 1, 2))
		return -ETIME;

	/* set lpc master write,cycle type and slv access mode */
	lpc_cmd_value = LPC_CMD_WRITE | LPC_CMD_SAMEADDR_SING | LPC_CMD_TYPE_IO;
	writel(lpc_cmd_value, lpc_dev->regs + LPC_REG_CMD);

	/* set lpc op len */
	writel(len, lpc_dev->regs + LPC_REG_OP_LEN);

	/* Set write data */
	for (i = 0; i < len; i++)
		writel(buf[i], lpc_dev->regs + LPC_REG_WDATA);

	/* set lpc addr config */
	writel(addr, lpc_dev->regs + LPC_REG_ADDR);

	/* set lpc start work */
	writel(START_WORK, lpc_dev->regs + LPC_REG_START);
	if (readl_poll_timeout_atomic(lpc_dev->regs + LPC_REG_IRQ_ST, tmp,
				     tmp & LPC_IRQ_OCCURRED, 1, 2))
		return -ETIME;
	writel(LPC_IRQ_CLEAR, lpc_dev->regs + LPC_REG_IRQ_ST);

	lpc_op_state_value = readl(lpc_dev->regs + LPC_REG_OP_STATUS);

	if (lpc_op_state_value & LPC_OP_FINISHED)
		return 0;

	return -EIO;
}

static int lpc_master_read(unsigned int addr, unsigned char *buf,
			   unsigned int len)
{
	unsigned int i;
	unsigned int lpc_cmd_value;
	unsigned int lpc_op_state_value;
	u32 tmp;

	/* para check */
	if (!buf || !len)
		return -EINVAL;
	writel(LPC_IRQ_CLEAR, lpc_dev->regs + LPC_REG_IRQ_ST);
	if (readl_poll_timeout_atomic(lpc_dev->regs + LPC_REG_OP_STATUS, tmp,
				     tmp & LPC_STATUS_DILE, 1, 2))
		return -ETIME;

	/* set lpc master read, cycle type and slv access mode */
	lpc_cmd_value = LPC_CMD_READ | LPC_CMD_SAMEADDR_SING | LPC_CMD_TYPE_IO;
	writel(lpc_cmd_value, lpc_dev->regs + LPC_REG_CMD);

	/* set lpc op len */
	writel(len, lpc_dev->regs + LPC_REG_OP_LEN);

	/* set lpc addr config */
	writel(addr, lpc_dev->regs + LPC_REG_ADDR);

	/* set lpc start work */
	writel(START_WORK, lpc_dev->regs + LPC_REG_START);
	if (readl_poll_timeout_atomic(lpc_dev->regs + LPC_REG_IRQ_ST, tmp,
				     tmp & LPC_IRQ_OCCURRED, 1, 2))
		return -ETIME;

	writel(LPC_IRQ_CLEAR, lpc_dev->regs + LPC_REG_IRQ_ST);

	lpc_op_state_value = readl(lpc_dev->regs + LPC_REG_OP_STATUS);
	/* Get read data */
	if (lpc_op_state_value & LPC_OP_FINISHED) {
		for (i = 0; i < len; i++)
			buf[i] = readl(lpc_dev->regs + LPC_REG_RDATA);

		return 0;
	}

	return -EIO;
}

static int lpc_indirect_pio(unsigned long port, bool dir, u32 size, void *data)
{
	unsigned long flags;
	int ret;


	spin_lock_irqsave(&lpc_dev->lock, flags);
	if (dir) {/* non-zero means read*/
		ret = lpc_master_read(port, data, size);
	} else {/*read*/
		ret = lpc_master_write(port, data, size);
	}

	spin_unlock_irqrestore(&lpc_dev->lock, flags);

	return ret;
}

static int lpc_probe(struct platform_device *pdev)
{
	struct resource *regs = NULL;

	lpc_dev = devm_kzalloc(&pdev->dev,
		sizeof(struct lpc_dev), GFP_KERNEL);
	if (!lpc_dev)
		return -ENOMEM;

	spin_lock_init(&lpc_dev->lock);
	regs = platform_get_resource(pdev, IORESOURCE_MEM, 0);
	lpc_dev->regs = devm_ioremap_resource(&pdev->dev, regs);
	if (IS_ERR(lpc_dev->regs))
		return PTR_ERR(lpc_dev->regs);

	lpc_dev->dev = &pdev->dev;
	platform_set_drvdata(pdev, lpc_dev);

	return arm64_set_isa_pio(lpc_indirect_pio);
}

static const struct of_device_id lpc_pltfm_match[] = {
	{
		.compatible = "hisilicon,low-pin-count",
	},
	{},
};

static struct platform_driver lpc_driver = {
	.driver = {
		.name           = "LPC",
		.of_match_table = lpc_pltfm_match,
	},
	.probe                = lpc_probe,
};
static int __init lpc_init_driver(void)
{
	return platform_driver_register(&lpc_driver);
}
arch_initcall(lpc_init_driver);

MODULE_LICENSE("GPL v2");
MODULE_AUTHOR("Rongrong Zou.");
MODULE_DESCRIPTION("LPC driver for hisilicon");
MODULE_VERSION("v1.0");
