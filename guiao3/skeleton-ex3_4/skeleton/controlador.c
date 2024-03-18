#include <stdio.h>
#include "mysystem.h"

// criar um filho para cada comando
// ciclo for  e fork
void controller(int N, char **commands)
{
	int fork_ret, status;
	int pids[N];
	for (int i = 0; i < N; i++)
	{

		fork_ret = fork();

		if (fork_ret == 0)
		{
			int counter = 0;
			int res = 1;
			while (res > 0)
			{
				res = mysystem(commands[i]);
				counter++;
			}
			// filho dizer coisas ao pai , mas não há comunicação ao contrario => fragilidade , usar pipes com nome
			_exit(counter);
		}
		else
		{
			pids[i] = fork_ret;
		}
	}

	for (int i = 0; i < N; i++)
	{
		waitpid(pids[i], &status, 0);

		if (WIFEXITED(status))
		{
			// WXITSTATUS(status) so da até 255 , depois recomeça em 0 => fragilidade da solução
			printf("Command %s executed  %d times \n", commands[i], WEXITSTATUS(status));
		}
		else
		{
			printf("Monitor for command %d exited abnormally\n", commands[i]);
		}
	}
}

int main(int argc, char *argv[])
{

	char *commands[argc - 1];
	int N = 0;
	for (int i = 1; i < argc; i++)
	{
		commands[N] = strdup(argv[i]);
		printf("command[%d] = %s\n", N, commands[N]);
		N++;
	}

	controller(N, commands);

	return 0;
}