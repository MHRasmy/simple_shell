#include "shell.h"

/**
 * init_builtins - initializes an array of built-in commands
 *
 * Return: the size
 */
int builtins_size()
{
	return sizeof(builtins) / sizeof(struct builtin);
}

/**
 * my_exit - exit
 */
void my_exit(void)
{
	exit(0);
}

/**
 * _cd - changes the current working directory
 * @args: An array of strings containing the destination directory
 * Return: void
 */
void _cd(char **args)
{
	if (!args[0])
		_perror("cd: missing argument\n");
	else
	{
		if (chdir(args[1]) != 0)
			_perror("cd");
	}
}

/**
 * env_shell - print the current environment
 * @env: Array of environment variables
 * Return: Nothing
 */
void env_shell(void)
{
	char **environ;
	int i = 0;

	while (environ[i] != NULL)
	{
		_print(environ[i]);
		_print("\n");
		i++;
	}
}
