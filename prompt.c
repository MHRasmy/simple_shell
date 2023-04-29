#include "shell.h"

/**
 * prompt - function to interpret commands without arguments
 * @argv: arguments vector
 * Return: void
 */
void prompt(char **argv __attribute__((unused)))
{
	char line[INPUT_LEN], **tokens, prev, *l, *cmt;
	int if_quote, is_terminal = isatty(STDIN_FILENO);

	while (1)
	{
		if (is_terminal)
			_print(PROMPT);
		if (fgets(line, INPUT_LEN, stdin) == NULL)
			break;
		prev = '\0';
		cmt = NULL;
		if_quote = 0;
		l = line;
		while (*l != '\0')
		{
			if (*l == '"' && prev != '\\')
				if_quote = !if_quote;
			else if (*l == '#' && prev != '\\' && !if_quote)
			{
				cmt = l;
				break;
			}
			prev = *l;
			l++;
		}
		if (cmt != NULL)
			*cmt = '\0';
		line[strcspn(line, "\n")] = '\0';
		tokens = tokenize(line);
		if (tokens[0] != NULL)
		{
			if (strcmp(tokens[0], "exit") == 0)
			{
				free(tokens);
				return;
			}
			execute_command(tokens, argv[0]);
		}
		free(tokens);
	}
}
