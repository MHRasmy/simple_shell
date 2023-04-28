#include "shell.h"

char* read_line()
{
	char *line = NULL, *err = "getline ERROR";
	size_t buf = 0;

	if (getline(&line, &buf, stdin) == -1)
		_perror(err);
	return line;
}
/**
 * parse_input - function to parse input
 * @line: input to be parsed
 * Return: parsed input as array of strings
 */
char **parse_input(char *line)
{
	char *delim = " ";
	int n = 0;
	char **av = malloc(sizeof(char *) * MAX_CMD);

	if (!av)
		perror("Failed to allocate memory");

	av[n] = strtok(line, delim);

	while (av[n])
		av[++n] = strtok(NULL, delim);

	return (av);
}
