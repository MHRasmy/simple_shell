#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/wait.h>

#define PROMPT "#cisfun$ "


/**
 * main - Entry point
 * Return: Always EXIT_SUCCESS
 */

int main(void)
{
	char *line, **args;
	ssize_t nread;
	size_t len = 0;

	while (1)
	{
		printf(PROMPT);
		nread = getline(&line, &len, stdin);
		if (nread == -1)
		{
			printf("\n");
			break;
		}
		if (line[nread - 1] == '\n')
		{
			line[nread - 1] = '\0';
		}
		if (access(line, X_OK) == 0)
		{
			pid_t pid = fork();

			if (pid == 0)
			{
				args = malloc(2 * sizeof(char *));
				args[0] = line;
				args[1] = NULL;
				execve(line, args, NULL);
			}
			else if (pid < 0)
				perror("fork");
			else
				wait(NULL);
		}
		else
			printf("./shell: No such file or directory");
	}
	free(line);
	exit(EXIT_SUCCESS);
}
