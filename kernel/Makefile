HOSTARCH = i386
ARCHDIR = arch/$(HOSTARCH)
PROJDIRS = .

SRCFILES := $(shell find $(PROJDIRS) -type f -name "*.c") $(shell find $(PROJDIRS) -type f -name "*.s")
HDRFILES := $(shell find $(PROJDIRS) -type f -name "*.h")
OBJFILES := $(patsubst %.c,%.o,$(SRCFILES))

ALLFILES := $(SRCFILES) $(HDRFILES) $(AUXFILES)

INC_DIRS = include/
WARNINGS := -Wall -Wextra -pedantic -Wshadow -Wpointer-arith -Wcast-align \
            -Wwrite-strings -Wmissing-prototypes -Wmissing-declarations \
            -Wredundant-decls -Wnested-externs -Winline -Wno-long-long \
            -Wconversion -Wstrict-prototypes
CFLAGS := -g $(WARNINGS) -I$(INC_DIRS) -I$(ARCHDIR) -m32 -ffreestanding -nostdlib
LDFLAGS = -T link-default.ld -melf_i386


.PHONY: all clean dist check testdrivers todolist

all: kernel.bin

kernel.bin: $(OBJFILES) $(ARCHDIR)/linker.ld
	$(CC) -T $(ARCHDIR)/linker.ld -o $@ $(CFLAGS) $(OBJFILES)

.c.o:
	$(CC) -MD -c $< -o $@ $(CFLAGS) $(CPPFLAGS)

.s.o:
	$(CC) -MD -c $< -o $@ $(CFLAGS) $(CPPFLAGS)

clean:
	rm -f kernel.bin
	rm -f $(OBJS) *.o */*.o */*/*.o
	rm -f $(OBJS:.o=.d) *.d */*.d */*/*.d

-include $(OBJS:.o=.d)
