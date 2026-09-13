#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
    pid_t pid;

    printf("Parent process started.\n");
    printf("Parent PID: %d\n", getpid());

    pid = fork();

    if (pid < 0)
    {
        perror("Fork failed");
        return 1;
    }
    else if (pid == 0)
    {
        printf("\nChild process started.\n");
        printf("Child PID: %d\n", getpid());
        printf("Child's Parent PID: %d\n", getppid());

        sleep(2);

        printf("Child process completed.\n");
    }
    else
    {
        printf("\nParent is waiting for child.\n");
        wait(NULL);
        printf("Parent process completed.\n");
    }

    return 0;
}
