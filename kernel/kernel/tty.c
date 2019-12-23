#include <kernel/tty.h>

static uart_select_t use_uart = UART0;

void tty_init(const uint32_t baud_rate, uart_select_t port)
{
#ifdef __arch_arm
  use_uart = port;
  // ===== BEGIN SET PIN STATES =====
  // Write required control signal to GPPUD to set pull up/down or neither
	mmio_write(GPPUD, 0);
  // Wait 150 cycles
	delay(150);
  // Clock control signals for GPIO pins 14 and 15
	mmio_write(GPPUDCLK0, (1 << 14) | (1 << 15));
	delay(150);
  // Remove control signal set previously
	mmio_write(GPPUDCLK0, 0);
  // ===== END SET PIN STATES =====

  // ===== BEGIN UART INIT =====
  if (use_uart == UART0) {
    // Clear for setup
    mmio_write(UART0_CR, 0);

    mmio_write(UART0_ICR, 0x7FF);

    uint32_t ibrd = UART_FCLK / (16 * baud_rate);
    uint32_t fbrd = ((UART_FCLK * 8 / baud_rate) + 1);
    // Sets baud rate to 115200
    mmio_write(UART0_IBRD, ibrd);
    mmio_write(UART0_FBRD, fbrd);

    // Line control
    // 4    - Enable FIFO
    // 5:6  - Word length 8 bits 
    mmio_write(UART0_LCRH, (1 << 4) | (1 << 5) | (1 << 6));

    mmio_write(UART0_IMSC, (1 << 1) | (1 << 4) | (1 << 5) | (1 << 6) |
            (1 << 7) | (1 << 8) | (1 << 9) | (1 << 10));

    // Enable UART0
    // 0  - Enable UART0
    // 8  - Enable transmit
    // 9  - Enable receive
    mmio_write(UART0_CR, (1 << 0) | (1 << 8) | (1 << 9));
  } else if (use_uart == UART1) {
    // Enable Auxiliary peripherals (UART)
    mmio_write(AUX_ENABLES, 1);
    // Disable unused features for now
    mmio_write(AUX_MU_CNTL_REG, 0);
    // Disable interrupt
    mmio_write(AUX_MU_IER_REG, 0);
    // Enable 8-bit line mode
    mmio_write(AUX_MU_LCR_REG, 3);
    // RTS high
    mmio_write(AUX_MU_MCR_REG, 0);

    // Set baudrate
    uint32_t baud_reg = SYSTEM_CLK_FREQ / (8 * baud_rate) - 1;
    mmio_write(AUX_MU_BAUD_REG, baud_reg);

    // Enable transmit and receive
    mmio_write(AUX_MU_CNTL_REG, 3);
  }
  // ===== END UART INIT =====
#endif
}

void tty_putc(unsigned char c)
{
#ifdef __arch_arm
  if (use_uart == UART0) {
    // Check FIFO and wait
    while (mmio_read(UART0_FR) & (1 << 5)) { }
    mmio_write(UART0_DR, c);
  } else if (use_uart == UART1) {
    while (!(mmio_read(AUX_MU_LSR_REG) & (1 << 5))) { }
    mmio_write(AUX_MU_IO_REG, c);
  }
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
