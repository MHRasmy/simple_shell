#include "shell.h"

/**
 * init_builtins - initializes an array of built-in commands
 *
 * Return: the initialized array of built-in commands
 */
/*builtin_t *init_builtins(void)
  {
  */
builtin_t builtins[] = {
	{"cd", _cd},
};
/*	return builtins;
//}*/

int builtins_size()
{
	return sizeof(builtins) / sizeof(struct builtin);
}

void my_exit(void)
{
	exit(0);
}

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
	int i = 0;

	while (environ[i] != NULL)
	{
		_print(environ[i]);
		_print("\n");
		i++;
	}
}
