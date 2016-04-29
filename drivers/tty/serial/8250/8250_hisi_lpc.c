/*
 */
#include <linux/console.h>
#include <linux/delay.h>
#include <linux/module.h>
#include <linux/init.h>
#include <linux/io.h>
#include <linux/serial_8250.h>
#include <linux/serial_core.h>
#include <linux/serial_reg.h>

/*
 * This is earlycon driver of hisi low pin count uart
*/
#define EARLY_LPC_CMD_SAMEADDR_SING		(0x00000008)
#define EARLY_LPC_CMD_TYPE_IO			(0x00000000)

#define EARLY_LPC_CMD_WRITE			(0x00000001)
#define EARLY_LPC_CMD_READ			(0x00000000)

#define EARLY_LPC_REG_START			(0x00)
#define EARLY_LPC_REG_OP_STA			(0x04)
#define EARLY_LPC_REG_IQR_ST			(0x08)

#define EARLY_LPC_IRQ_CLEAR			(0x02)
#define EARLY_LPC_IRQ_OCCURRED			(0x02)
#define EARLY_LPC_STATUS_DILE			(0x01)
#define EARLY_LPC_OP_FINISHED			(0x02)

#define EARLY_LPC_REG_OP_LEN			(0x10)
#define EARLY_LPC_REG_CMD			(0x14)
#define EARLY_LPC_REG_ADDR			(0x20)
#define EARLY_LPC_REG_WDATA			(0x24)
#define EARLY_LPC_REG_RDATA			(0x28)

#define EARLY_LPC_TIMEOUT (20)
unsigned int __init hisi_early_lpc_out(unsigned char __iomem *lpc_base,
				      u8 data, unsigned long addr)
{
	unsigned int lpc_cmd_value;
	unsigned int retry = 0;

	writel(EARLY_LPC_IRQ_CLEAR, lpc_base + EARLY_LPC_REG_IQR_ST);
	retry = 0;
	while (!(readl(lpc_base + EARLY_LPC_REG_OP_STA) &
		EARLY_LPC_STATUS_DILE)) {
		udelay(1);
		retry++;
		if (retry >= EARLY_LPC_TIMEOUT)
			return -ETIME;
	}

	/* set lpc master write cycle type and slv access mode */
	lpc_cmd_value = EARLY_LPC_CMD_WRITE | EARLY_LPC_CMD_TYPE_IO |
			EARLY_LPC_CMD_SAMEADDR_SING;
	writel(lpc_cmd_value, lpc_base + EARLY_LPC_REG_CMD);
	/* set lpc op len */
	writel(1, lpc_base + EARLY_LPC_REG_OP_LEN);
	/* write 1 byte */
	writel(data, lpc_base + EARLY_LPC_REG_WDATA);
	/* set lpc addr config */
	writel(addr, lpc_base + EARLY_LPC_REG_ADDR);
	/* set lpc start work */
	writel(0x01, lpc_base + EARLY_LPC_REG_START);
	retry = 0;
	while (!(readl(lpc_base + EARLY_LPC_REG_IQR_ST) &
		EARLY_LPC_IRQ_OCCURRED)) {
		udelay(1);
		retry++;
		if (retry >= EARLY_LPC_TIMEOUT)
			return -ETIME;

	}

	writel(EARLY_LPC_IRQ_CLEAR, lpc_base + EARLY_LPC_REG_IQR_ST);

	if (readl(lpc_base + EARLY_LPC_REG_OP_STA) & EARLY_LPC_OP_FINISHED)
		return 0;

	return -EIO;

}
u8 __init hisi_early_lpc_in(unsigned char __iomem *lpc_base, unsigned int addr)
{
	unsigned int retry = 0;
	unsigned int lpc_cmd_value;

	writel(EARLY_LPC_IRQ_CLEAR, lpc_base + EARLY_LPC_REG_IQR_ST);

	retry = 0;
	while (!(readl(lpc_base + EARLY_LPC_REG_OP_STA) &
		EARLY_LPC_STATUS_DILE)) {
		udelay(1);
		retry++;
		if (retry >= EARLY_LPC_TIMEOUT)
			return -ETIME;

	}

	/* set lpc master read, cycle type and slv access mode */
	lpc_cmd_value = EARLY_LPC_CMD_READ | EARLY_LPC_CMD_TYPE_IO |
			EARLY_LPC_CMD_SAMEADDR_SING;
	writel(lpc_cmd_value, lpc_base + EARLY_LPC_REG_CMD);
	/* set lpc op len */
	writel(1, lpc_base + EARLY_LPC_REG_OP_LEN);
	/* set lpc addr config */
	writel(addr, lpc_base + EARLY_LPC_REG_ADDR);
	/* set lpc start work */
	writel(0x01, lpc_base + EARLY_LPC_REG_START);

	while (!(readl(lpc_base + EARLY_LPC_REG_IQR_ST) &
		EARLY_LPC_IRQ_OCCURRED)) {
		udelay(1);
		retry++;
		if (retry >= EARLY_LPC_TIMEOUT)
			/*dev_err(lpc_dev->dev, "lpc read, time out\n");*/
			return -ETIME;

	}

	writel(EARLY_LPC_IRQ_CLEAR, lpc_base + EARLY_LPC_REG_IQR_ST);

	/* Get read data */
	if ((readl(lpc_base + EARLY_LPC_REG_OP_STA) & EARLY_LPC_OP_FINISHED))
		return readb(lpc_base + EARLY_LPC_REG_RDATA);

	return 0;
}

u8 __init hisilpc_8250_early_in(struct uart_port *port, int offset)
{
	return hisi_early_lpc_in(port->membase, port->iobase + offset);
}

void __init hisilpc_8250_early_out(struct uart_port *port,
					  int offset, int value)
{
	hisi_early_lpc_out(port->membase, value, port->iobase + offset);
}

#define BOTH_EMPTY (UART_LSR_TEMT | UART_LSR_THRE)

static void __init wait_for_xmitr(struct uart_port *port)
{
	unsigned int status;

	for (;;) {
		status = hisilpc_8250_early_in(port, UART_LSR);
		if ((status & BOTH_EMPTY) == BOTH_EMPTY)
			return;
		cpu_relax();
	}
}

static void __init serial_putc(struct uart_port *port, int c)
{
	wait_for_xmitr(port);
	hisilpc_8250_early_out(port, UART_TX, c);
}

static void __init early_hisilpc_8250_write(struct console *console,
					const char *s, unsigned int count)
{
	struct earlycon_device *device = console->data;
	struct uart_port *port = &device->port;
	unsigned int ier;

	/* Save the IER and disable interrupts preserving the UUE bit */
	ier = hisilpc_8250_early_in(port, UART_IER);
	if (ier)
		hisilpc_8250_early_out(port, UART_IER, ier & UART_IER_UUE);

	uart_console_write(port, s, count, serial_putc);

	/* Wait for transmitter to become empty and restore the IER */
	wait_for_xmitr(port);

	if (ier)
		hisilpc_8250_early_out(port, UART_IER, ier);
}

static void __init init_port(struct earlycon_device *device)
{
	struct uart_port *port = &device->port;
	unsigned int divisor;
	unsigned char c;
	unsigned int ier;

	hisilpc_8250_early_out(port, UART_LCR, 0x3);	/* 8n1 */
	ier = hisilpc_8250_early_in(port, UART_IER);
	hisilpc_8250_early_out(port, UART_IER, ier & UART_IER_UUE); /* no int */
	hisilpc_8250_early_out(port, UART_FCR, 0);	/* no fifo */
	hisilpc_8250_early_out(port, UART_MCR, 0x3);	/* DTR + RTS */

	divisor = DIV_ROUND_CLOSEST(port->uartclk, 16 * device->baud);
	c = hisilpc_8250_early_in(port, UART_LCR);
	hisilpc_8250_early_out(port, UART_LCR, c | UART_LCR_DLAB);
	hisilpc_8250_early_out(port, UART_DLL, divisor & 0xff);
	hisilpc_8250_early_out(port, UART_DLM, (divisor >> 8) & 0xff);
	hisilpc_8250_early_out(port, UART_LCR, c & ~UART_LCR_DLAB);
}


static int __init early_hisilpc8250_setup(struct earlycon_device *device,
					 const char *options)
{
	char *p;
	int ret;

	if (!(device->port.membase || device->port.iobase))
		return -ENODEV;

	if (device->options) {
		ret = kstrtoul(device->options, 0,
				      (unsigned long *)&device->baud);
		/*wed asume that baudrate must specified,
		*value 0 means uart have been configed
		*/
		p = strchr(device->options, ',');
		if (p)
			p++;
		else
			return -EINVAL;

		ret = kstrtoul(p, 0, (unsigned long *)&device->port.iobase);
		if (ret)
			return ret;
	} else {
		device->port.iobase = 0x2f8;
		device->baud = 0;
	}

	if (0 == device->port.iobase)
		return -EFAULT;

	if (!device->baud) {
		struct uart_port *port = &device->port;
		unsigned int ier;

		/* assume the device was initialized, only mask interrupts */
		ier = hisilpc_8250_early_in(port, UART_IER);
		hisilpc_8250_early_out(port, UART_IER, ier & UART_IER_UUE);
	} else
		init_port(device);

	device->con->write = early_hisilpc_8250_write;
	return 0;
}
EARLYCON_DECLARE(hisilpcuart, early_hisilpc8250_setup);


#define PORT(_base, _irq)				\
	{						\
		.iobase		= _base,		\
		.irq		= _irq,			\
		.uartclk	= 1843200,		\
		.iotype		= UPIO_PORT,		\
		.flags		= UPF_BOOT_AUTOCONF,	\
	}

static struct plat_serial8250_port hisi_8250_data[] = {
	PORT(0x2f8, 0),
	{ },
};

static struct platform_device hisi_lpc_uart = {
	.name			= "serial8250",
	.id			= PLAT8250_DEV_HISI_LPC,
	.dev			= {
		.platform_data	= hisi_8250_data,
	},
};

static int __init hisi_lpc_uart_init(void)
{
	return platform_device_register(&hisi_lpc_uart);
}

module_init(hisi_lpc_uart_init);

MODULE_AUTHOR("Rongrong Zou");
MODULE_DESCRIPTION("8250 serial probe module for Hisilicon LPC UART");
MODULE_LICENSE("GPL");
MODULE_VERSION("v1.0");
