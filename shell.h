#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/wait.h>
#include <string.h>
#include <stdbool.h>

#define PROMPT "#cisfun$ "
#define MAX_CMD 10
/**
 * struct builtin - struct to hold built-in command
 * name and function pointer
 * @name: name of the built-in command
 * @func: pointer to the function that implements the built-in command
 */
typedef struct builtin
{
    char *name;
    void (*func)(char **args);
} builtin_t;

/* initializes an array of built-in commands */
/*
builtin_t *init_builtins(void);
*/
/* builtins array */
extern builtin_t builtins[];

/* buitlins functions */
int builtins_size();
void my_exit(char **args);
void _cd(char **args);

/* functions */
int mul(int num1, int num2);
void prompt(char **argv, char **env);
void execute_command(char **args, char **env);

/* parsing input */
char** tokenize(char *line);
char* read_line();

/* string functions */
int _strlen(char *s);
int _strcmp(char *s1, char *s2);
int _puts(char *str);

/* print functions */
int _print(char *string);
int _perror(char *err);

/* free functions */
void _free(char **buf);
#endif
