#include "mysystem.h"

// recebe um comando por argumento
// returna -1 se o fork falhar
// caso contrario retorna o valor do comando executado
int mysystem(const char *command)
{

	int res = -1;

	pid_t pid = fork();
	if (pid == 0)
	{
		char *argm[128];
		int i = 0;
		char *token = strtok(command, " ");
		while (token != NULL)
		{
			argm[i] = token;
			printf("%s\n", token);
			token = strtok(NULL, " ");
			i++;
		}
		argm[i] = NULL;
		execvp(command, argm);
		_exit(EXIT_FAILURE);
	}
	else if (pid < 0)
	{
		perror("Error no fork");
		exit(EXIT_FAILURE);
	}
	else
	{
		int status = 0;
		int wait_pid = wait(&status);
		if (WIFEXITED(status))
		{
			// printf("Child process ended with status %d\n", WEXITSTATUS(status));
			return res;
		}
	}
}