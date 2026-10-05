CC = gcc
CFLAGS = -Wall -Wextra -g

all: prog7_linuxaddr memory_demo

prog7_linuxaddr: prog7_linuxaddr.c
	$(CC) $(CFLAGS) -o prog7_linuxaddr prog7_linuxaddr.c

memory_demo: memory_demo.c
	$(CC) $(CFLAGS) -o memory_demo memory_demo.c

run-address: prog7_linuxaddr
	./prog7_linuxaddr

run-memory: memory_demo
	./memory_demo

clean:
	rm -f prog7_linuxaddr memory_demo
