#ifndef KERNEL_H
#define KERNEL_H

typedef unsigned char uint8;
typedef unsigned short uint16;
typedef unsigned int uint32;

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

#endif

#ifndef V_BUF_COL
#define V_BUF_COL 80
#endif

#ifndef V_BUF_ROW
#define V_BUF_ROW 25
#endif

void
oct_v_write(char *dst, const char * src, char attr_byte, long len)
{
  // TODO: Implement checks so len < (V_BUF_ROW * V_BUF_COL)
  for (int i = 0; i < len && src[i] != '\0'; i++)
  {
    dst[2*i] = src[i];
    dst[2*i+1] = attr_byte;
  }
}

void
oct_main()
{

  // 25 rows with 80 columns and each with 2 elements (character byte and attribute byte)
  char *v_buf = (char *)VGA_ADDRESS;

  // Clear v_buf
  for (int i = 0; i < V_BUF_ROW * V_BUF_COL * 2; i+=2)
  {
    // Character byte
    v_buf[i] = ' ';
    // Attribute byte set
    v_buf[i + 1] = 0x00;
  }

  oct_v_write(v_buf, "October OS Booting...", GREEN | BLACK << 8, 100);
}
