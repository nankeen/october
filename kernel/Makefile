.PHONY: all clean install run

HOSTARCH=arm
HOSTARCH_DIR=arch/$(HOSTARCH)

export BUILD_DIR=./build

export AR=arm-none-eabi-ar
export AS=arm-none-eabi-as
export CC=arm-none-eabi-gcc
export CPP=arm-none-eabi-g++
export LD=arm-none-eabi-ld

export SRC_DIR=.
export INCLUDE=-I $(SRC_DIR)/include
export CFLAGS=-mcpu=cortex-a7 -MMD -mgeneral-regs-only -fpic -ffreestanding -std=gnu99 -Wall -Wextra -Werror -g3 -D__arch_$(HOSTARCH)
export LIBS=-nostdlib -nostartfiles
export LDFLAGS=

$(BUILD_DIR)/%_c.o: $(SRC_DIR)/%.c
	mkdir -p $(@D)
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(BUILD_DIR)/%_s.o: $(SRC_DIR)/%.s
	mkdir -p $(@D)
	$(CC) $(INCLUDE) $(CFLAGS) -MMD -c $< -o $@

C_FILES = $(shell find $(SRC_DIR) -type f -regex ".*\.c")
ASM_FILES = $(shell find $(SRC_DIR) -type f -regex ".*\.s")
OBJ_FILES = $(C_FILES:$(SRC_DIR)/%.c=$(BUILD_DIR)/%_c.o)
OBJ_FILES += $(ASM_FILES:$(SRC_DIR)/%.s=$(BUILD_DIR)/%_s.o)

DEP_FILES = $(OBJ_FILES:%.o=%.d)
	-include $(DEP_FILES)

all: kernel.elf

kernel.elf: $(OBJ_FILES)
	echo $(C_FILES)
	$(CC) -T $(HOSTARCH_DIR)/linker.ld -o $@  $(OBJ_FILES) $(CFLAGS) $(LDFLAGS) $(LIBS)

clean:
	rm -r $(BUILD_DIR) kernel.elf

# UART1: qemu-system-arm -m 256 -M raspi2 -serial null -serial stdio -kernel kernel.elf
# UART0: qemu-system-arm -m 256 -M raspi2 -serial stdio -kernel kernel.elf
run: kernel.elf
	qemu-system-arm -m 256 -M raspi2 -serial null -serial stdio -kernel kernel.elf
