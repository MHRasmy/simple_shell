#include "shell.h"

/**
 * prompt - interpret commands without arguments
 * @argv: arguments vector
 * @env: string array passed as environment
 * Return: void
 */

void prompt(char **argv, char **env)
{
	char *line, *av[] = {NULL, NULL};
	ssize_t nread;
	size_t len = 0;

	while (1)
	{
		printf(PROMPT);
		nread = getline(&line, &len, stdin);
		if (nread == -1)
		{
			free(line);
			exit(EXIT_FAILURE);
		}
		if (line[nread - 1] == '\n')
		{
			line[nread - 1] = '\0';
		}
		av[0] = line;
		if (access(line, X_OK) == 0)
		{
			pid_t pid = fork();

			if (pid == 0)
			{
				execve(line, av, env);
			}
			else if (pid < 0)
			{
				free(line);
				exit(EXIT_FAILURE);
			}
			else
				wait(NULL);
		}
		else
			printf("%s: No such file or directory\n", argv[0]);
	}
	free(line);
	exit(EXIT_SUCCESS);
}
