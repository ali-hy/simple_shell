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
 * @argv: program args
 * @command: command where error happend
 * @error: error messsage content
 * Return: length of printed error
 */
int print_err(char **argv, const char *command, const char *error)
{
	char *err = NULL, *temp = NULL;
	size_t length;

	temp = concat(argv[0], ": ");
	err = concat(temp, ultos(_errno(0)));
	free(temp);

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
	return (write(STDERR_FILENO, err, length));
}
