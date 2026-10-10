
CC = gcc
CFLAGS = -Wall -Wextra -O2
DEBUGFLAGS = -Wall -Wextra -g

all: copy_lowlevel copy_stdio redirect_output redirect_input

copy_lowlevel: copy_lowlevel.c
	$(CC) $(CFLAGS) -o copy_lowlevel copy_lowlevel.c

copy_stdio: copy_stdio.c
	$(CC) $(CFLAGS) -o copy_stdio copy_stdio.c

redirect_output: redirect_output.c
	$(CC) $(DEBUGFLAGS) -o redirect_output redirect_output.c

redirect_input: redirect_input.c
	$(CC) $(DEBUGFLAGS) -o redirect_input redirect_input.c

clean:
	rm -f copy_lowlevel copy_stdio redirect_output redirect_input

.PHONY: all clean

