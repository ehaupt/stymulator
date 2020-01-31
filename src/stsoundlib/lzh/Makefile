CC ?= gcc
AR = ar cr
RM = rm -f

CFLAGS ?= -Wall

liblzh.a: lzhlib.o
	$(AR) liblzh.a lzhlib.o

lzhlib.o: lzhlib.cpp lzh.h
	$(CC) $(CFLAGS) -c lzhlib.cpp

clean:
	$(RM) *~ *.o *.a

dist:
