#include "shell.h"

/**
 * tokenize - take string and parse it into tokens
 * @line: string to be tokenized
 *
 * Return: array of strings of tokens
 */
char **tokenize(char *line)
{
	int len = 0;
	int capacity = 15;
	char *delim, *token, **tokens = malloc(capacity * sizeof(char *));

	if (!tokens)
	{
		_perror("ERROR token malloc failed");
		exit(1);
	}

	delim = " \t\r\n";
	token = strtok(line, delim);

	while (token != NULL)
	{
		tokens[len] = token;
		len++;

		if (len >= capacity)
		{
			capacity = (int) (capacity * 1.5);
			tokens = realloc(tokens, capacity * sizeof(char *));
		}

		token = strtok(NULL, delim);
	}

	tokens[len] = NULL;
	return (tokens);
}

/**
 * read_line - read line from stdin
 *
 * Return: strings read
 */
char *read_line()
{
	char *line = NULL;
	size_t buf = 0;

	if (getline(&line, &buf, stdin) == -1)
	{
		free(line);
		exit(1);
	}
	return (line);
}
