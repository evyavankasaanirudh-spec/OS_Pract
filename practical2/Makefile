CC = gcc
CFLAGS = -Wall -g

all: prog2

prog2: prog2.c
	$(CC) $(CFLAGS) prog2.c -o prog2

run: prog2
	./prog2 source.txt destination.txt

clean:
	rm -f prog2
