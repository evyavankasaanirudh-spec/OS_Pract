CC = gcc
CFLAGS = -Wall -g

all: wait_waitpid_demo

wait_waitpid_demo: wait_waitpid_demo.c
	$(CC) $(CFLAGS) wait_waitpid_demo.c -o wait_waitpid_demo

run: wait_waitpid_demo
	./wait_waitpid_demo

clean:
	rm -f wait_waitpid_demo
