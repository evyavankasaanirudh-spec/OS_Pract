CC = gcc
CFLAGS = -Wall -g

prog1: prog1.c
	gcc $(CFLAGS) -o prog1 prog1.c

clean:
	rm -f prog1

