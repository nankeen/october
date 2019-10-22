bits 32

section .multiboot
  ; multiboot
  align   4
  dd      0x1BADB002          ; multiboot magic
  dd      0x00000000          ; multiboot flags
  dd      -0x1BADB002         ; mutliboot checksum

section .text
global _start
extern oct_main
extern kmain

_start:
  mov     esp, stack_start
  call    kmain
  cli                         ; disable interrupts to prevent race conditions
hlt_loop:
  hlt
  jmp     hlt_loop

KERNEL_STACK_SIZE equ 0x4000  ; size of stack in bytes
section .bss
resb      KERNEL_STACK_SIZE   ; Reserve 16k for the stack
stack_start:
