
CC = gcc
CFLAGS = -Wall -Wextra -O2

all: pc_semaphore deadlock_demo deadlock_prevention

pc_semaphore: pc_semaphore.c
	$(CC) $(CFLAGS) -o pc_semaphore pc_semaphore.c -pthread

deadlock_demo: deadlock_demo.c
	$(CC) -Wall -Wextra -g -o deadlock_demo deadlock_demo.c -pthread

deadlock_prevention: deadlock_prevention.c
	$(CC) $(CFLAGS) -o deadlock_prevention deadlock_prevention.c -pthread

clean:
	rm -f pc_semaphore deadlock_demo deadlock_prevention

.PHONY: all clean

