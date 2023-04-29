#include "shell.h"

/**
 * main - Entry point
 * @argc: number of arguments passed to the program
 * @argv: arguments vector
 * @env: string array passed as enviroment
 * Return: Always EXIT_SUCCESS
 */

int main(int argc, char **argv)
{
	if (argc == 1)
		prompt(argv);
	return (EXIT_SUCCESS);
}
