#include "main.h"

/**
 * _errno - get current error num and increment it by 1
 * @update: 1 to update errnum, 0 to not update
 * Return: current error num
 */
int _errno(int update)
{
	static int errnum = 1;
	int temp = errnum;

	errnum += update;

	return (temp);
}

/**
 * print_err - print an error to stderr
 * @command: command where error happend
 * @error: error messsage content
 * Return: length of printed error
 */
int print_err(const char *command, const char *error)
{
	char *err = NULL, *temp = NULL, *temp_num = NULL;
	size_t length;
	int res = 0;

	temp = concat(prog_args(NULL)[0], ": ");
	temp_num = ultos(_errno(0));
	err = concat(temp, temp_num);
	free(temp);
	free(temp_num);

	temp = err;
	err = concat(temp, ": ");
	free(temp);

	temp = err;
	err = concat(temp, command);
	free(temp);

	temp = err;
	err = concat(temp, ": ");
	free(temp);

	temp = err;
	err = concat(temp, error);
	free(temp);

	temp = err;
	err = concat(temp, "\n");
	free(temp);

	length = len(err);
	res = write(STDERR_FILENO, err, length);
	free(err);
	return (res);
}
