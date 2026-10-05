CC = gcc
CFLAGS = -Wall -Wextra -g

all: dynamic_memory cow_demo

dynamic_memory: dynamic_memory.c
	$(CC) $(CFLAGS) -o dynamic_memory dynamic_memory.c

cow_demo: cow_demo.c
	$(CC) $(CFLAGS) -o cow_demo cow_demo.c

run-memory: dynamic_memory
	./dynamic_memory

run-cow: cow_demo
	./cow_demo

valgrind: dynamic_memory
	valgrind --leak-check=full --show-leak-kinds=all ./dynamic_memory

clean:
	rm -f dynamic_memory cow_demo
