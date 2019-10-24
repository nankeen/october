#ifndef TERMINAL_H
#define TERMINAL_H

#include <stddef.h>
#include <stdint.h>
#include <vga.h>

void tty_init(void);
void tty_putat(char c, uint8_t color, size_t x, size_t y);
void tty_write(const char* data, size_t size);
void tty_write_str(const char* data);

#endif
