#include "shell.h"

/** tokenize - take string and parse it into tokens
 * @line: string to be tokenized
 *
 * Return: array of strings of tokens
 */
char** tokenize(char *line)
{
	int len = 0;
	int capacity = 15;
	char *delim, *token, **tokens = malloc(capacity * sizeof(char*));

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
			tokens = realloc(tokens, capacity * sizeof(char*));
		}

		token = strtok(NULL, delim);
	}

	tokens[len] = NULL;
	return tokens;
}

/**
 * read_line - read line from stdin
 * 
 * Return: strings read
 */
char* read_line()
{
	int capacity = 1024;
	int pos = 0;
	char *buffer = (char *)malloc(sizeof(char) * capacity);
	int ch;

	if (buffer == NULL) {
		_perror("Allocation error\n");
		exit(1);
	}

	while (1) {
		ch = getchar();
		if (ch == EOF || ch == '\n')
		{
			buffer[pos] = '\0';
			return buffer;
		} else {
			buffer[pos] = ch;
		}
		pos++;

		if (pos >= capacity)
		{
			capacity += 1024;
			buffer = (char *)realloc(buffer, capacity);

			if (buffer == NULL)
			{
				_perror("Rellocation error\n");
				exit(1);
			}
		}
	}
}
