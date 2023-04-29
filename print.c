#include "shell.h"

/**
 * _print - writes a string in the standar output
 * @string: pointer to string
 * Return: no. bytes writen or .
 * On error, -1 is returned, and errno is set appropriately.
 */
int _print(char *string)
{
	return (write(STDOUT_FILENO, string, _strlen(string)));
}
/**
 * _perror - writes a string in the standar error
 * @string: pointer to string
 * Return: no. bytes writen or .
 * On error, -1 is returned, and errno is set appropriately.
 */
int _perror(char *err)
{
	return (write(STDERR_FILENO, err, _strlen(err)));
}
