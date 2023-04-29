#include "shell.h"

/**
 * run_commands_from_file - execute command from a file
 * @filename: pointer to string of file name
 * Return: void
 */
void run_commands_from_file(const char *filename, char **argv)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t nread;
	FILE *fp = fopen(filename, "r");

	if (!fp)
	{
		perror("fopen");
		exit(EXIT_FAILURE);
	}

	while ((nread = getline(&line, &len, fp)) != -1)
	{
		file_prompt(line, argv);
		free(line);
		line = NULL;
		len = 0;
	}

	free(line);
	fclose(fp);
}

/**
 * prompt - function to interpret commands without arguments
 * @line: command line
 * Return: void
 */
void file_prompt(char *line, char **argv)
{
	char **tokens, prev, *l, *cmt;
	int if_quote;

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
			if (prev == ' ')
			{
				cmt = l;
				break;
			}
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
