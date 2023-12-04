#include "main.h"

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
