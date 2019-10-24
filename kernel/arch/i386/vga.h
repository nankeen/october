#ifndef VGA_H
#define VGA_H

#include <stdint.h>

#define VGA_ADDRESS 0xB8000

enum vga_color {
    BLACK,
    BLUE,
    GREEN,
    CYAN,
    RED,
    MAGENTA,
    BROWN,
    GREY,
    DARK_GREY,
    BRIGHT_BLUE,
    BRIGHT_GREEN,
    BRIGHT_CYAN,
    BRIGHT_RED,
    BRIGHT_MAGENTA,
    YELLOW,
    WHITE,
};

#ifndef V_BUF_COL
#define V_BUF_COL 80
#endif

#ifndef V_BUF_ROW
#define V_BUF_ROW 25
#endif

uint8_t vga_color_attr(enum vga_color foreground, enum vga_color background);
uint16_t vga_entry(unsigned char character, uint8_t color);

#endif
