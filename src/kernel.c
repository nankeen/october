#include "vga.h"

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
    v_buf[i + 1] = BLACK;
  }

  oct_v_write(v_buf, "October OS Booting...", GREEN | BLACK << 8, 100);
}
