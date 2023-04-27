#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/wait.h>
#include <string.h>

#define PROMPT "#cisfun$ "
#define MAX_CMD 10

int mul(int num1, int num2);
void prompt(char **argv, char **env);
char **parse_input(char *line);
int execute_command(char **args, char **env);
void exit_shell(char **av);
void env_shell(char **env);

#endif
