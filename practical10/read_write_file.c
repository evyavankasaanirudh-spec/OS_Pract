
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

#define BUFFER_SIZE 4096

int main(void)
{
    int fd = open("data.txt", O_RDWR);

    if (fd == -1)
    {
        perror("open");
        return EXIT_FAILURE;
    }

    char buffer[BUFFER_SIZE];

    ssize_t bytes_read = read(fd, buffer, sizeof(buffer) - 1);

    if (bytes_read == -1)
    {
        perror("read");
        close(fd);
        return EXIT_FAILURE;
    }

    buffer[bytes_read] = '\0';

    printf("Original file contents:\n%s\n", buffer);

    if (bytes_read < 5)
    {
        fprintf(stderr, "Error: file must contain at least 5 bytes.\n");
        close(fd);
        return EXIT_FAILURE;
    }

    if (lseek(fd, 0, SEEK_SET) == -1)
    {
        perror("lseek");
        close(fd);
        return EXIT_FAILURE;
    }

    if (write(fd, "HELLO", 5) != 5)
    {
        perror("write");
        close(fd);
        return EXIT_FAILURE;
    }

    close(fd);

    printf("File modified successfully using read()/write().\n");

    return EXIT_SUCCESS;
}

