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

	for (int i = 0; i < builtins_size(); i++)
	{
		if (strcmp(args[0], builtins[i].name) == 0)
		{
			builtins[i].func(args);
			return (0);
		}
	}

	pid = fork();

	if (pid == -1)
	{
		_perror("failed to fork\n");
		return (1);
	}

	if (pid == 0)
	{
		execve(args[0], args, env);
		_perror("failed to execute command\n");
	}
	else
		wait(NULL);

	return (0);
}
