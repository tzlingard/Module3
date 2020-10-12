CFLAGS=-Wall -pedantic -std=c11 -I. -g

all: hashtest

hash.o:	hash.c hash.h queue.h
	gcc $(CFLAGS) -c hash.c

hashtest.o:	hashtest.c hash.h queue.h
	gcc $(CFLAGS) -c hashtest.c

queue.o:	queue.c queue.h
	gcc $(CFLAGS) -c queue.c

hashtest: hash.o hashtest.o queue.o
	gcc $(CFLAGS) hash.o  hashtest.o queue.o -o hashtest

clean:
	rm -f *.o hashtest
