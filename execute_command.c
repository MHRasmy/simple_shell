#include "shell.h"

/**
 * execute_command - function to execute command
 * @args: arguments
 * @env: environment variables
 * Return: 0 on success and 1 on failure
 */
int execute_command(char **args, char **env)
{
	pid_t pid;

	if (access(args[0], F_OK) == -1)
	{
		perror("command not found");
		return (1);
	}

	pid = fork();

	if (pid == -1)
	{
		perror("failed to fork");
		return (1);
	}

	if (pid == 0)
	{
		if (execve(args[0], args, env) == -1)
			perror("failed to execute command");
	}
	else
		wait(NULL);

	return (0);
}
