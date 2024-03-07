#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>

int main()
{
    pid_t pid;
    int status;
    pid = fork();
    if (pid == 0)
    {
        _exit(0);
    }
    else
    {
        pid_t filho = wait(&status);
        printf("Filho %d terminou com o status %d\n", filho, status);
    }
}