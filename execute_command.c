#include "shell.h"

/**
 * execute_command - function to execute command
 * @args: arguments
 * @env: environment variables
 * Return: 0 on success and 1 on failure
 */
void execute_command(char **args, char **env __attribute__((unused)), char *arg)
{
	int i = 0;
	pid_t pid;
	int status;
	char *path;

	for (i = 0; i < builtins_size(); i++)
	{
		if (_strcmp(args[0], builtins[i].name) == 0)
		{
			builtins[i].func(args);
			return;
		}
	}

	pid = fork();

	path = search_path(args[0]);
	if (access(path, X_OK) == 0)
	{
		if (pid == 0)
		{
			if (execve(path, args, env) < 0)
			{
				_perror(arg);
				_perror(": No such file or directory\n");
				exit(1);
			}
		}
		else if (pid > 0)
		{
			waitpid(pid, &status, WUNTRACED);
		}
		else if (pid < 0)
			_perror("failed to fork\n");
	}
	free(path);
}

char* search_path(char *filename) {
	char *path, *path_env, *full_path;
	if (filename[0] == '/')
	{
		if (access(filename, F_OK) == 0)
			return realpath(filename, NULL);
		else
			return NULL;
	}

	path_env = malloc(MAX_PATH_LEN * sizeof(char));
	snprintf(path_env, MAX_PATH_LEN, "/bin:%s", getenv("PATH"));
	path = strtok(path_env, ":");
	full_path = malloc(MAX_PATH_LEN * sizeof(char));

	while (path != NULL)
	{
		snprintf(full_path, MAX_PATH_LEN, "%s/%s", path, filename);
		if (access(full_path, F_OK) == 0)
		{
			free(path_env);
			return realpath(full_path, NULL);
		}
		path = strtok(NULL, ":");
	}

	free(path_env);
	free(full_path);
	return NULL;
}
