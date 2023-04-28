#include "shell.h"

/**
 * prompt - function to interpret commands without arguments
 * @argv: arguments vector
 * @env: string array passed as environment
 * Return: void
 */
void prompt(char **argv __attribute__((unused)), char **env)
{
	char *line, **tokens;
	while (1)
	{
		if (isatty(STDIN_FILENO))
			_print(PROMPT);
		line = read_line();
		tokens = tokenize(line);

		if (tokens[0] != NULL)
			execute_command(tokens, env, argv[0]);
		free(tokens);
		free(line);
	}
}
