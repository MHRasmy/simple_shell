#include "shell.h"

/**
 * prompt - function to interpret commands without arguments
 * @argv: arguments vector
 * @env: string array passed as environment
 * Return: void
 */
void prompt(char **argv __attribute__((unused)), char **env)
{
	char line[INPUT_LEN], **tokens;
	int is_terminal = isatty(STDIN_FILENO);

	while (1)
	{
		if (is_terminal)
			_print(PROMPT);
		if (fgets(line, INPUT_LEN, stdin) == NULL)
			break;
		tokens = tokenize(line);

		if (tokens[0] != NULL)
		{
			if (strcmp(tokens[0], "env") == 0)
				env_shell();
			else if (strcmp(tokens[0], "exit") == 0)
				return;
			else
				execute_command(tokens, env, argv[0]);
		}
		free(tokens);
	}
}
