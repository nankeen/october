#ifndef TERMINAL_H
#define TERMINAL_H

#include <stddef.h>
#include <stdint.h>
#ifdef __arch_i386
#include <i386/vga.h>
#endif
#ifdef __arch_aarch32
#include <aarch32/gpio.h>
#endif


void tty_init(void);
void tty_putc(unsigned char c);
void tty_write(const char* data, size_t size);
void tty_puts(const char *str);

#endif
