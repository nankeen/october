.PHONY: all clean install run

HOSTARCH=aarch32
HOSTARCH_DIR=arch/aarch32

export AR=arm-none-eabi-ar
export AS=arm-none-eabi-as
export CC=arm-none-eabi-gcc
export CPP=arm-none-eabi-g++

export PROJDIR=$(shell pwd)
export INCLUDE=-I $(PROJDIR)/include
export CFLAGS=-mcpu=arm1176jzf-s -fpic -ffreestanding -std=gnu99 -Wall -Wextra -Werror -g3 -D__arch_$(HOSTARCH)
export LIBS=-nostdlib -Larch/aarch32 -Lkernel
export LDFLAGS=-lkernel -larch 

OBJS=\
kernel/main.o \
$(HOSTARCH_DIR)/boot/boot.o

all: kernel.elf

kernel.elf:
	cd kernel && $(MAKE) && cd ../
	cd $(HOSTARCH_DIR) && $(MAKE) && cd ../../
	$(CC) -T $(HOSTARCH_DIR)/linker.ld -o $@ $(OBJS) $(CFLAGS) $(LDFLAGS) $(LIBS)

clean:
	rm kernel.elf
	cd kernel && $(MAKE) clean && cd ../
	cd $(HOSTARCH_DIR) && $(MAKE) clean && cd ../../

run: kernel.elf
	qemu-system-arm -m 256 -M raspi2 -serial stdio -kernel kernel.elf
