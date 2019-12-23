.PHONY: all clean install

#CFLAGS=-mcpu=cortex-a7 -fpic -ffreestanding

OBJS=\
		 mmio.o

all: libarch.a boot/boot.o

%.o: %.c
		$(CC) -c $< -o $@ $(CFLAGS) $(INCLUDE)

%.o: %.s
		$(CC) -c $< -o $@ $(CFLAGS) $(INCLUDE)

libarch.a: $(OBJS)
	$(AR) rcs $@ $(OBJS)

clean:
	rm $(OBJS)
	rm libarch.a
