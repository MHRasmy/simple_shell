#include "shell.h"

/**
 * prompt - function to interpret commands without arguments
 * @argv: arguments vector
 * Return: void
 */
void prompt(char **argv __attribute__((unused)))
{
	char line[INPUT_LEN];
	int is_terminal = isatty(STDIN_FILENO);

	while (1)
	{
		if (is_terminal)
			_print(PROMPT);
		if (fgets(line, INPUT_LEN, stdin) == NULL)
			break;
		file_prompt(line, argv);
	}
}
