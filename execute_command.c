#include "shell.h"

/**
 * execute_command - function to execute command
 * @args: arguments
 * @env: environment variables
 * Return: 0 on success and 1 on failure
 */
void execute_command(char **args, char **env __attribute__((unused)), char *arg)
{
	int i = 0;
	pid_t pid;

	for (i = 0; i < builtins_size(); i++)
	{
		if (_strcmp(args[0], builtins[i].name) == 0)
		{
			builtins[i].func(args);
			return;
		}
	}

	pid = fork();


	if (pid == 0)
	{
		execve(args[0], args, NULL);
		_perror(arg);
		_perror(": No such file or directory\n");
		exit(1);
	}
	else if (pid > 0)
	{
		wait(NULL);
	}
	else if (pid < 0)
		_perror("failed to fork\n");
}
