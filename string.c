#include "shell.h"

char** tokenize(char *line)
{
	int len = 0;
	int capacity = 15;
	char **tokens = malloc(capacity * sizeof(char*));

	char *delim = " \t\r\n";
	char *token = strtok(line, delim;

	while (token != NULL) {
		tokens[len] = token;
		len++;

		if (len >= capacity) {
			capacity = (int) (capacity * 1.5);
			tokens = realloc(tokens, capacity * sizeof(char*));
		}

		token = strtok(NULL, delim);
	}

	tokens[len] = NULL;
	return tokens;
}

/**
 * _strlen - returns the length of a string
 * @s: the string whose length to check
 *
 * Return: integer length of string
 */
int _strlen(char *s)
{
	int i = 0;

	if (!s)
		return (0);

	while (*s++)
		i++;
	return (i);
}

/**
 * _strcmp - comparison of two strangs.
 * @s1: the first strang
 * @s2: the second strang
 *
 * Return: -ve if s1 < s2, +ve if s1 > s2, 0 if equal
 */
int _strcmp(char *s1, char *s2)
{
	while (*s1 && *s2)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	if (*s1 == *s2)
		return (0);
	else
		return (*s1 < *s2 ? -1 : 1);
}

/**
 * _puts - print a string
 * @str: string to be printed
 *
 * Return: no. printed characters
 */
int _puts(char *str)
{
	int i;

	if (!(str))
		return (0);
	for (i = 0; str[i]; i++)
		write(STDOUT_FILENO, &str[i], 1);
	return (i);
}
