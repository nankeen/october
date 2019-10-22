#ifndef VGA_H
#define VGA_H

#define VGA_ADDRESS 0xB8000
#define BUFSIZE 2200

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

#endif
