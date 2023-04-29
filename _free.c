#include "shell.h"

/**
 * _free - free buffer array
 * @buf: pointer to array of strings
 *
 * Return: void
 */
void _free(char **buf)
{
	int i = 0;

	if (buf)
	{
		for (i = 0; buf[i]; i++)
			free(buf[i]);
		free(buf);
	}
}
