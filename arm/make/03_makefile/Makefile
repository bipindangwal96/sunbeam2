CC=gcc
CFLAGS=-DPI=3.14 -O1 -m32
LDFLAGS=-lm

all: main.out

main.out: add.o subtract.o multiply.o main.o
	$(CC) $(CFLAGS) $(LDFLAGS) -o main.out add.o subtract.o multiply.o main.o

add.o: add.c
	$(CC) $(CFLAGS) -c add.c

subtract.o: subtract.c
	$(CC) $(CFLAGS) -c subtract.c

multiply.o: multiply.c
	$(CC) $(CFLAGS) -c multiply.c

main.o: main.c
	$(CC) $(CFLAGS) -c main.c

clean:
	rm -f main.out add.o subtract.o multiply.o main.o

.PHONY: clean all

