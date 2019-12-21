#include <kernel/tty.h>

void tty_init()
{
#ifdef __arch_aarch32
	mmio_write(UART0_CR, 0x00000000);

	mmio_write(GPPUD, 0x00000000);
	delay(150);

	mmio_write(GPPUDCLK0, (1 << 14) | (1 << 15));
	delay(150);

	mmio_write(GPPUDCLK0, 0x00000000);

	mmio_write(UART0_ICR, 0x7FF);

	// Sets baud rate to 115200
	mmio_write(UART0_IBRD, 1);
	mmio_write(UART0_FBRD, 40);

	mmio_write(UART0_LCRH, (1 << 4) | (1 << 5) | (1 << 6));

	mmio_write(UART0_IMSC, (1 << 1) | (1 << 4) | (1 << 5) | (1 << 6) |
					(1 << 7) | (1 << 8) | (1 << 9) | (1 << 10));

	mmio_write(UART0_CR, (1 << 0) | (1 << 8) | (1 << 9));
#endif
}

void tty_putc(unsigned char c)
{
#ifdef __arch_aarch32
	// Check FIFO and wait
	while ( mmio_read(UART0_FR) & (1 << 5) ) { }
	mmio_write(UART0_DR, c);
#endif
}

void tty_write(const char* data, size_t size)
{
	for (size_t i=0; i < size; i++) {
		tty_putc(data[i]);
	}
}

void tty_puts(const char* str)
{
	for (size_t i = 0; str[i] != '\0'; i ++) {
		tty_putc((unsigned char)str[i]);
	}
}
