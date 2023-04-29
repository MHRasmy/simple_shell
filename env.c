#include "shell.h"

/**
 * set_env - function to set an environment variable
 * @name: name of the environment variable
 * @value: value to be assigned to the environment variable
 * Return: 0 on success, -1 on failure
 */
int set_env(char *name, char *value)
{
	char *env_var;
	int len;

	len = strlen(name) + strlen(value) + 2;
	env_var = malloc(len);
	if (env_var == NULL)
		return (-1);
	snprintf(env_var, len, "%s=%s", name, value);
	if (putenv(env_var) != 0)
		return (-1);
	return (0);
}

/**
 * unset_env - function to unset an environment variable
 * @name: name of the environment variable
 * Return: 0 on success, -1 on failure
 */
int unset_env(char *name)
{
	if (unsetenv(name) != 0)
		return (-1);
	return (0);
}
