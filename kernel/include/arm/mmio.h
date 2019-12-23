#ifndef GPIO_H
#define GPIO_H
#include <stddef.h>
#include <stdint.h>

#define SYSTEM_CLK_FREQ 250000000
#define UART_FCLK 48000000 // Assuming 48Mhz

void mmio_write(uint32_t reg, uint32_t data);
uint32_t mmio_read(uint32_t reg);
void delay(int32_t count);

enum
{
    // The GPIO registers base address.
    GPIO_BASE = 0x3F200000, // for raspi2 & 3, 0x20200000 for raspi1

    GPFSEL1   = (GPIO_BASE + 0x04),
    GPSET0    = (GPIO_BASE + 0x1c),
    GPCLR0    = (GPIO_BASE + 0x28),
    GPPUD     = (GPIO_BASE + 0x94),
    GPPUDCLK0 = (GPIO_BASE + 0x98),

    // The base address for PL011 UART.
    UART0_BASE = 0x3F201000, // for raspi2 & 3, 0x20201000 for raspi1

    UART0_DR      = (UART0_BASE + 0x00),
    UART0_RSRECR  = (UART0_BASE + 0x04),
    UART0_FR      = (UART0_BASE + 0x18),
    UART0_ILPR    = (UART0_BASE + 0x20),
    UART0_IBRD    = (UART0_BASE + 0x24),
    UART0_FBRD    = (UART0_BASE + 0x28),
    UART0_LCRH    = (UART0_BASE + 0x2C),
    UART0_CR      = (UART0_BASE + 0x30),
    UART0_IFLS    = (UART0_BASE + 0x34),
    UART0_IMSC    = (UART0_BASE + 0x38),
    UART0_RIS     = (UART0_BASE + 0x3C),
    UART0_MIS     = (UART0_BASE + 0x40),
    UART0_ICR     = (UART0_BASE + 0x44),
    UART0_DMACR   = (UART0_BASE + 0x48),
    UART0_ITCR    = (UART0_BASE + 0x80),
    UART0_ITIP    = (UART0_BASE + 0x84),
    UART0_ITOP    = (UART0_BASE + 0x88),
    UART0_TDR     = (UART0_BASE + 0x8C),

    // The base address for auxiliaries (UART1, SPI1, SPI2)
    AUX_BASE = 0x3F215000,

    AUX_IRQ           = (AUX_BASE + 0x00), // Interrupt Status
    AUX_ENABLES       = (AUX_BASE + 0x04), // Axiliary Enables
    AUX_MU_IO_REG     = (AUX_BASE + 0x40), // Mini UART I/O Data
    AUX_MU_IER_REG    = (AUX_BASE + 0x44), // Mini UART Interrupt Enable
    AUX_MU_IIR_REG    = (AUX_BASE + 0x48), // Mini UART Interrupt Identify
    AUX_MU_LCR_REG    = (AUX_BASE + 0x4C), // Mini UART Line Control
    AUX_MU_MCR_REG    = (AUX_BASE + 0x50), // Mini UART Modem Control
    AUX_MU_LSR_REG    = (AUX_BASE + 0x54), // Mini UART Line Status
    AUX_MU_MSR_REG    = (AUX_BASE + 0x58), // Mini UART Modem Status
    AUX_MU_SCRATCH    = (AUX_BASE + 0x5C), // Mini UART Scratch
    AUX_MU_CNTL_REG   = (AUX_BASE + 0x60), // Mini UART Extra Control
    AUX_MU_STAT_REG   = (AUX_BASE + 0x64), // Mini UART Extra Status
    AUX_MU_BAUD_REG   = (AUX_BASE + 0x68), // Mini UART Baudrate
};
#endif
