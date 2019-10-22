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
  for (int i, j = 0; j < len || src[j] == '\0'; j++, i+=2)
  {
    dst[i] = src[j];
    dst[i+1] = attr_byte;
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

  oct_v_write(v_buf, "October OS Booting...", 0xf0, -1);
}

void kmain(void)
{
	const char *str = "my first kernel";
	char *vidptr = (char*)0xb8000; 	//video mem begins here.
	unsigned int i = 0;
	unsigned int j = 0;

	/* this loops clears the screen
	* there are 25 lines each of 80 columns; each element takes 2 bytes */
	while(j < 80 * 25 * 2) {
		/* blank character */
		vidptr[j] = ' ';
		/* attribute-byte - light grey on black screen */
		vidptr[j+1] = 0x07; 		
		j = j + 2;
	}

	j = 0;

	/* this loop writes the string to video memory */
	while(str[j] != '\0') {
		/* the character's ascii */
		vidptr[i] = str[j];
		/* attribute-byte: give character black bg and light grey fg */
		vidptr[i+1] = 0x07;
		++j;
		i = i + 2;
	}
	return;
}