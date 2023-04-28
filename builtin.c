#include "shell.h"

/**
 * builtins - array of built-in commands
 */
builtin_t builtins[] = {
    {"exit", my_exit},
    {"cd", _cd},
};

int builtins_size()
{
    return sizeof(builtins) / sizeof(struct builtin);
}

void my_exit(char **args)
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
