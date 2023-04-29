#include "shell.h"

/**
 * main - Entry point
 * @argc: number of arguments passed to the program
 * @argv: arguments vector
 * Return: Always EXIT_SUCCESS
 */

int main(int argc, char **argv)
{
	if (argc == 1)
		prompt(argv);
	if (argc == 2)
		run_commands_from_file(argv[1], argv);
	return (EXIT_SUCCESS);
}
