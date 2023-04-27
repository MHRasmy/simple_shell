#include "shell.h"

/**
 * prompt - function to interpret commands without arguments
 * @argv: arguments vector
 * @env: string array passed as environment
 * Return: void
 */
void prompt(char **argv __attribute__((unused)), char **env)
{
	char *line = NULL, **args;
	size_t len = 0;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			printf("%s", PROMPT);

		if (getline(&line, &len, stdin) == -1)
			break;

		if (line[strlen(line) - 1] == '\n')
			line[strlen(line) - 1] = '\0';

		args = parse_input(line);
		if (strcmp(args[0], "exit") == 0)
			exit_shell(args);
		execute_command(args, env);

		free(args);
	}

	free(line);
}

/**
 * exit_shell - Exit the shell
 * @av: Array of arguments
 * Return: Nothing
 */
void exit_shell(char **av)
{
	free(av);
	exit(EXIT_SUCCESS);
}
