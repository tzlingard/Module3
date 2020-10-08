CFLAGS=-Wall -pedantic -std=c11 -I. -g
all: queue.o

queue.o:	queue.c queue.h
		gcc $(CFLAGS) -c queue.c

clean:
		rm -f *.o
