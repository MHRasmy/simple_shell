#include "shell.h"

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
 * Return: Nothing
 */
void env_shell(void)
{
	int i = 0;

	while (environ[i] != NULL)
	{
		_print(environ[i]);
		_print("\n");
		i++;
	}
}
