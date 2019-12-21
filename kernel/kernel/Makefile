.PHONY: all clean install

OBJS=\
		 main.o\
		 tty.o

all: $(OBJS)

%.o: %.c
		$(CC) -c $< -o $@ $(CFLAGS) $(INCLUDE) $(LIBS)

%.o: %.s
		$(CC) -c $< -o $@ $(CFLAGS)

all: libkernel.a

libkernel.a: $(OBJS)
		$(AR) rcs $@ $(OBJS)

clean:
		rm $(OBJS)
		rm libkernel.a
