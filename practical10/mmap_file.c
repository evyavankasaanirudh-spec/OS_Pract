
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <string.h>

int main(void)
{
    int fd = open("data.txt", O_RDWR);

    if (fd == -1)
    {
        perror("open");
        return EXIT_FAILURE;
    }

    struct stat st;

    if (fstat(fd, &st) == -1)
    {
        perror("fstat");
        close(fd);
        return EXIT_FAILURE;
    }

    if (st.st_size == 0)
    {
        fprintf(stderr, "Error: data.txt is empty.\n");
        close(fd);
        return EXIT_FAILURE;
    }

    size_t size = (size_t)st.st_size;

    char *mapped = mmap(NULL, size, PROT_READ | PROT_WRITE,
                        MAP_SHARED, fd, 0);

    if (mapped == MAP_FAILED)
    {
        perror("mmap");
        close(fd);
        return EXIT_FAILURE;
    }

    printf("Original file contents:\n");
    fwrite(mapped, 1, size, stdout);
    printf("\n");

    if (size >= 5)
    {
        memcpy(mapped, "HELLO", 5);
    }
    else
    {
        fprintf(stderr, "File must contain at least 5 bytes.\n");
        munmap(mapped, size);
        close(fd);
        return EXIT_FAILURE;
    }

    if (msync(mapped, size, MS_SYNC) == -1)
    {
        perror("msync");
        munmap(mapped, size);
        close(fd);
        return EXIT_FAILURE;
    }

    if (munmap(mapped, size) == -1)
    {
        perror("munmap");
        close(fd);
        return EXIT_FAILURE;
    }

    close(fd);

    printf("File modified successfully using mmap().\n");

    return EXIT_SUCCESS;
}

