
CC = gcc
CFLAGS = -Wall -Wextra -g
PTHREAD = -pthread

all: race_counter safe_counter mutex_counter

race_counter: race_counter.c
	$(CC) $(CFLAGS) -o race_counter race_counter.c $(PTHREAD)

safe_counter: safe_counter.c
	$(CC) $(CFLAGS) -o safe_counter safe_counter.c $(PTHREAD)

mutex_counter: mutex_counter.c
	$(CC) -Wall -Wextra -O2 -pthread mutex_counter.c -o mutex_counter

clean:
	rm -f race_counter safe_counter mutex_counter

.PHONY: all clean

