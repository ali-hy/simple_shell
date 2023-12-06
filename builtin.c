#include "main.h"

/**
 * exit_builtin - exits program
 * @args: args containing exit code
 * Return: -1 if failed, nothing if not failed
 */
int exit_builtin(char **args)
{
	int code = exit_status(GET_VARIABLE, 0);
	char *err;

	if (args[1] != NULL)
		code = _stoui(args[1]);

	if (code < 0)
	{
		err = concat("Illegal number: ", args[1]);
		print_err("exit", err);
		free(err);
		return (2);
	}
	exit_status(SET_VARIABLE, code);

	return (-1);
}

/**
 * env_builtin - print env
 * @args: command arguments
 * Return: return (0 on success)
 */
int env_builtin(char **args)
{
	int i;
	char **env = _env(GET_VARIABLE, 0);

	UNUSED(args);
	for (i = 0; env[i] != NULL; i++)
	{
		put_s(env[i]);
		put_c('\n');
	}

	return (0);
}

/**
 * find_builtin - get a command structure for a builtin command
 * @command: command to find a builtin for
 * Return: builtin command structure
 */
cmd *find_builtin(const char *command)
{
	int i;
	int (*func)(char **args) = NULL;
	builtin_cmd *res = NULL;
	builtin_f builtins[] = {
		{"exit", exit_builtin},
		{"env", env_builtin},
		{NULL, NULL}};

	for (i = 0; builtins[i].command != NULL; i++)
	{
		if (_strcmp(command, builtins[i].command) == 0)
		{
			func = builtins[i].func;
			break;
		}
	}

	if (func == NULL)
		return (NULL);

	res = malloc(sizeof(builtin_cmd));

	res->type = BUILTIN;
	res->builtin_func = func;

	return ((cmd *)res);
}
