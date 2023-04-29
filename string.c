#include "shell.h"

/**
 * _strtok - Tokenizes a string based on a delimiter character
 *
 * @s: The string to tokenize
 * @d: The delimiter character
 *
 * Return: A pointer to the current token, or NULL if there are no more tokens
 */
char *_strtok(char *s, char d)
{
	char *input = NULL;
	char *result;
	int i = 0;

	if (s != NULL)
		input = s;

	if (input == NULL)
		return (NULL);

	result = malloc(strlen(input) + 1);

	for (; input[i] != '\0'; i++)
	{
		if (input[i] != d)
			result[i] = input[i];
		else
		{
			result[i] = '\0';
			input = input + i + 1;
			return (result);
		}
	}

	result[i] = '\0';
	input = NULL;

	return (result);
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
