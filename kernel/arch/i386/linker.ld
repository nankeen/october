OUTPUT_FORMAT(elf32-i386)
ENTRY(_start)
SECTIONS
{
	/* we need 1MB of space atleast */
	. = 1M;
  ker_start = .;

  	/* text section */
	.text BLOCK(4K) : ALIGN(4K)
	{
		*(.multiboot)
		*(.text)
	}

	/* read only data section */
	.rodata BLOCK(4K) : ALIGN(4K)
	{
		*(.rodata)
	}

	/* data section */
	.data BLOCK(4K) : ALIGN(4K)
	{
		*(.data)
	}

	/* bss section */
	.bss BLOCK(4K) : ALIGN(4K)
	{
		*(COMMON)
		*(.bss)
	}
  
  ker_end = .;
}
