#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

int main()
{
    pid_t child1, child2;
    int status;

    child1 = fork();

    if (child1 < 0)
    {
        perror("Fork failed");
        return 1;
    }

    if (child1 == 0)
    {
        printf("Child 1 started. PID: %d\n", getpid());
        sleep(2);
        printf("Child 1 completed.\n");
        exit(10);
    }

    child2 = fork();

    if (child2 < 0)
    {
        perror("Fork failed");
        return 1;
    }

    if (child2 == 0)
    {
        printf("Child 2 started. PID: %d\n", getpid());
        sleep(4);
        printf("Child 2 completed.\n");
        exit(20);
    }

    printf("Parent waiting for Child 1 using waitpid().\n");

    waitpid(child1, &status, 0);

    if (WIFEXITED(status))
    {
        printf("Child 1 exited with status: %d\n",
               WEXITSTATUS(status));
    }

    printf("Parent waiting for remaining child using wait().\n");

    wait(&status);

    if (WIFEXITED(status))
    {
        printf("Remaining child exited with status: %d\n",
               WEXITSTATUS(status));
    }

    printf("Parent process completed.\n");

    return 0;
}
