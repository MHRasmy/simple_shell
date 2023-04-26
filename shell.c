#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

/**
 * main - Entry point
 * Return : (0) for success, (1) for failure
 */

int main(void)
{
	char *cmd = NULL, *token = NULL;
	size_t buffersize = 0;
	char **args = NULL;
	char *delim = " ";
	//char *word = NULL;
	int n = 1;
	int exeval;
	int i;

	pid_t pid;

	args = malloc(sizeof(char *));

	if (args == NULL)
	{
		return (1);
	}

	printf("$ ");

	if (getline(&cmd, &buffersize, stdin) == -1)
	{
		return (1);
	}

	args[n - 1] = strtok(cmd, delim);
	while (args[n-1] != NULL)
	{
		args = realloc(args, ++n);
		args[n - 1] = strtok(NULL, delim);
	}

	pid = fork();

	if (pid == 0)
	{
		/* this is the child process */
		token = args[0];
		//if (strcmp(token, "betty") == 0)
		//{
			//args[0] = "/bin/ls";
			exeval = execve(args[0], args, NULL);
			if (exeval == -1)
			{
				perror("./shell: No such file or directory");
				exit(1);
			}
		//}
	}
	else if (pid < 0)
	{
		return (1);
	}
	else
	{
		/* this is the parent process */
		wait(NULL);
	}

	free(args);
	return (0);
}
