
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main(void)
{
    int fd = open("output.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);

    if (fd == -1)
    {
        perror("open");
        return EXIT_FAILURE;
    }

    printf("Before redirection: displayed on terminal\n");
    fflush(stdout);

    if (dup2(fd, STDOUT_FILENO) == -1)
    {
        perror("dup2");
        close(fd);
        return EXIT_FAILURE;
    }

    close(fd);

    printf("This message is redirected to output.txt\n");
    printf("Standard output now points to the file.\n");

    return EXIT_SUCCESS;
}

