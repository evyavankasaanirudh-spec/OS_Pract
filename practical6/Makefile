CC = gcc
CFLAGS = -Wall -Wextra

all: fifo_server fifo_client signal_handler

fifo_server: fifo_server.c
	$(CC) $(CFLAGS) -o fifo_server fifo_server.c

fifo_client: fifo_client.c
	$(CC) $(CFLAGS) -o fifo_client fifo_client.c

signal_handler: signal_handler.c
	$(CC) $(CFLAGS) -o signal_handler signal_handler.c

run-server: fifo_server
	./fifo_server

run-client: fifo_client
	./fifo_client

run-signal: signal_handler
	./signal_handler

clean:
	rm -f fifo_server fifo_client signal_handler
	rm -f /tmp/server_fifo /tmp/client_*_fifo
