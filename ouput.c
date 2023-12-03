#include "main.h"

/**
 * ultos - convert unsigned long to string
 * @ul: unsigned long integer
 * Return: string that represents the unsigned long
 */
char *ultos(unsigned long ul)
{
	unsigned long curr = ul;
	int i, base = 10, length = 0;
	char *map = "0123456789abcdef";
	char *res;

	while (curr != 0)
	{
		curr /= base;
		length++;
	}

	if (length == 0)
		length = 1;

	res = malloc(length + 1);
	if (res == NULL)
		return (NULL);

	res[length] = '\0';
	curr = ul;
	for (i = length - 1; i >= 0; i--)
	{
		res[i] = map[curr % base];
		curr /= base;
	}

	return (res);
}

/**
 * put_s - print a string
 * @str: string to print
 * Return: length of string printed
 */
size_t put_s(const char *str)
{
	size_t length = len(str);

	return (write(STDOUT_FILENO, str, length));
}

/**
 * put_c - print a character to stdout
 * @c: character to print
 * Return: 1 if printed, -1 on fail
 */
int put_c(char c)
{
	return (write(STDOUT_FILENO, &c, 1));
}
