#include "main.h"

/**
 * init_program - initialize program global variables
 * @ac: arg count
 * @argv: program arg vector
 * @env: program environment
 */
void init_program(int ac, char **argv, char **env)
{
	UNUSED(ac);
	prog_args(argv);
	init_env(env);
}

/**
 * exit_status - set or get prev exit status
 * @access_option: determine whether to set the value or get it
 * @value: new value if access_option is to set
 * Return: the old value
 */
int exit_status(enum access_options access_option, int value)
{
	static int old_value;

	if (access_option == SET_VARIABLE)
	{
		old_value = value;
		if (value != 0)
			_errno(1);
	}

	return (old_value);
}

/**
 * prog_args - get program arguments
 * @value: set the argv if it's not NULL
 * Return: program args
 */
char **prog_args(char **value)
{
	static char **argv;

	if (argv == NULL)
		argv = value;

	return (argv);
}

/**
 * _env - process evnironment
 * @access_option: determines wheter to set or get the value
 * @value: value to set env to
 * Return: array of environment variables
 */
char **_env(enum access_options access_option, char **value)
{
	static char **env;

	if (access_option == SET_VARIABLE && env != value)
	{
		free(env);
		env = value;
	}

	return (env);
}

/**
 * my_exit - custom exit func
 * @code: exit code
 */
void my_exit(int code)
{
	free_env_end();
	exit(code);
}
