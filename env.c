#include "main.h"

/**
 * get_env - gets one environment variable from
 * @varname: name of environment variable
 * Return: index of environment variable, -1 if variable not found
 */
int get_env(const char *varname)
{
	int i;
	char *target = concat(varname, "="), **env = _env(GET_VARIABLE, NULL);

	if (target[1] == '\0')
	{
		free(target);
		return (-1);
	}

	for (i = 0; env[i] != NULL; i++)
		if (starts_with(env[i], target))
		{
			free(target);
			return (i);
		}

	free(target);
	return (-1);
}

/**
 * init_env - copy program env into heap
 * @env: env passed into main
 */
void init_env(char **env)
{
	char **res = NULL;
	int size = 0, i = 0;

	while (env[size] != NULL)
		size++;

	res = malloc(sizeof(char **) * (size + 1));

	for (i = 0; i <= size; i++)
		res[i] = copy(env[i]);

	_env(SET_VARIABLE, res);
}

/**
 * free_env_end - free env at end of the program
 */
void free_env_end(void)
{
	int i = 0;
	char **env = _env(GET_VARIABLE, NULL);

	if (env == NULL)
		return;

	for (i = 0; env[i] != NULL; i++)
	{
		if (env[i])
			free(env[i]);
	}

	_env(SET_VARIABLE, NULL);
}
