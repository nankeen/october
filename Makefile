CFLAGS=-Wall -Wextra -Werror -m32 -nostdlib -nostdinc -fno-builtin -fno-stack-protector -nostartfiles -nodefaultlibs -ffreestanding
LDFLAGS=-T link-default.ld -melf_i386


kernel.bin: kernel_asm.o kernel_c.o
	ld $(LDFLAGS) $^ -o kernel.bin

octoberOS.iso: kernel.bin grub.cfg
	mkdir -p isodir/boot/grub
	cp kernel.bin isodir/boot/kernel.bin
	cp grub.cfg isodir/boot/grub/grub.cfg
	grub-mkrescue -o octoberOS.iso isodir

kernel_asm.o: kernel.s
	nasm -f elf32 $^ -o kernel_asm.o

kernel_c.o: kernel.c
	gcc $(CFLAGS) -c $^ -o kernel_c.o

clean:
	rm -rf *.o