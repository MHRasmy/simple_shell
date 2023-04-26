#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/wait.h>

#define PROMPT "#cisfun$ "

int mul(int num1, int num2);
void prompt(char **argv, char **env);

#endif
