#include <kernel/tty.h>

#ifdef __arch_arm

void ker_main()
{
  tty_puts("October OS booting");
}

void ker_init(uint32_t r0, uint32_t r1, uint32_t atags)
{
  (void) r0;
  (void) r1;
  (void) atags;

  tty_init(115200, UART1);
  ker_main();
}

#endif
