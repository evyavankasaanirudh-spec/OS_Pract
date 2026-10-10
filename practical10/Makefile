
CC = gcc
CFLAGS = -Wall -Wextra -g

all: mmap_file read_write_file

mmap_file: mmap_file.c
	$(CC) $(CFLAGS) -o mmap_file mmap_file.c

read_write_file: read_write_file.c
	$(CC) $(CFLAGS) -o read_write_file read_write_file.c

clean:
	rm -f mmap_file read_write_file

.PHONY: all clean

