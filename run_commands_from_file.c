#include "shell.h"

/**
 * run_commands_from_file - execute command from a file
 * @filename: pointer to string of file name
 * @argv: @argv: array string of arguments
 * Return: void
 */
void run_commands_from_file(const char *filename, char **argv)
{
	char line[MAX_LINE_LENGTH];
	FILE *fp = fopen(filename, "r");

	if (!fp)
	{
		_perror(argv[0]);
		_perror(": 0: Can't open");
		_perror("\n");
		exit(127);
	}

	while (fgets(line, MAX_LINE_LENGTH, fp) != NULL)
	{
		file_prompt(line, argv);
	}

	fclose(fp);
}

/**
 * file_prompt - function to interpret commands without arguments
 * @line: command line
 * @argv: array string of arguments
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
			if (tokens[1] != NULL)
			{
				my_exit_status(tokens);
			}
			free(tokens);
			my_exit();
		}
		execute_command(tokens, argv[0]);
	}
	free(tokens);
}
