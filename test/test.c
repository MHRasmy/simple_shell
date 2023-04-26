#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int main(void)
{
    char command[1024];
    char full_path[1024];
    char *args[] = {NULL};
    pid_t pid;

    while (1)
    {
        printf("#cisfun$ ");
        fgets(command, 1024, stdin);
        command[strcspn(command, "\n")] = '\0'; /* remove newline character */

        pid = fork();

        if (pid == -1)
        {
            perror("Error: fork failed");
            exit(1);
        }
        else if (pid == 0)
        {
            strcpy(full_path, "/bin/");
            strcat(full_path, command);
            execve(full_path, args, environ);
            perror("Error: execve failed");
            exit(1);
        }
        else
        {
            wait(NULL);
        }
    }

    return 0;
}

