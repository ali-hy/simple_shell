#include "main.h"

/**
 * get_env - gets one environment variable from
 * @varname: name of environment variable
 * @env: process environment
 * Return: index of environment variable, -1 if variable not found
 */
int get_env(const char *varname, char **env)
{
	int i;
	char *target = concat(varname, "=");

	if (target[1] == '\0')
		return (-1);

	for (i = 0; env[i] != NULL; i++)
	{
		if (starts_with(env[i], varname))
			return (i);
	}

	return (-1);
}
