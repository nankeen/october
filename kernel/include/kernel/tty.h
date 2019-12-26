#ifndef TERMINAL_H
#define TERMINAL_H

#include <stddef.h>
#include <stdint.h>
#ifdef __arch_i386
#include <i386/vga.h>
#endif
#ifdef __arch_arm
#include <arm/mmio.h>
#endif

typedef enum {
  UART0,
  UART1,
} uart_select_t;

void tty_init(const uint32_t baud_rate, uart_select_t port);
void tty_putc(unsigned char c);
void tty_write(const char* data, size_t size);
void tty_puts(const char *str);

#endif
