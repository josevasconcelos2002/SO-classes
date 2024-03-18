#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>
#include <sys/wait.h>

void filho_to_pai()
{
    int pipefd[2];
    int ret = pipe(pipefd);
    if (ret == -1)
    {
        perror("erro ao criar pipe");
    }

    if (fork() == 0)
    {
        close(pipefd[0]);
        int j;
        for (j = 0; j < 100000; j++)
        {
            write(pipefd[1], &j, sizeof(int));
            printf("Escrevi: %d\n", j);
            // buffer fica cheio , e o pai fica a espera que o filho termine => bloqueia
        }
        close(pipefd[1]);
        _exit(0);
    }
    else
    {

        int i = 0;
        int status;
        close(pipefd[1]);

        // FIFO , lê o primeiro valor a ser escrito
        while (read(pipefd[0], &i, sizeof(int)) > 0)
        {
            printf("valor lido: %d\n", i);
        }

        printf("valor é: %d\n", i);

        wait(&status);
        // fechar extremos
        close(pipefd[0]);

        // codigo do pai
    }
}

void pai_to_filho()
{
    int pipefd[2];
    int ret = pipe(pipefd);
    if (ret == -1)
    {
        perror("erro ao criar pipe");
    }

    if (fork() == 0)
    {
        int i = 0;
        close(pipefd[1]);

        read(pipefd[0], &i, sizeof(int));

        close(pipefd[0]);

        printf("filho: %d\n", i);

        _exit(0);
    }
    else
    {
        // codigo do pai
        int status;
        close(pipefd[0]);
        int j = 10;
        write(pipefd[1], &j, sizeof(int));

        wait(&status);

        close(pipefd[1]);
    }
}

int main()
{
    // pai_to_filho();
    filho_to_pai();
    return 0;
}