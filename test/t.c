#include <stdio.h>
#include <unistd.h>

int main(void)
{
        char *argv[] = {"/bin/betty", "main.c", NULL};
        int val = execve(argv[0], argv, NULL);
        if (val == -1)
               perror("ERROR");

        printf("Done");
        return (0);
}
