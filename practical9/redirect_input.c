
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main(void)
{
    int fd = open("input.txt", O_RDONLY);

    if (fd == -1)
    {
        perror("open");
        return EXIT_FAILURE;
    }

    if (dup2(fd, STDIN_FILENO) == -1)
    {
        perror("dup2");
        close(fd);
        return EXIT_FAILURE;
    }

    close(fd);

    char buffer[256];

    printf("Reading from input.txt:\n");

    while (fgets(buffer, sizeof(buffer), stdin) != NULL)
    {
        printf("%s", buffer);
    }

    return EXIT_SUCCESS;
}

