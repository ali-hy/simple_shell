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
		_errno(1);
	}

	return (old_value);
}
