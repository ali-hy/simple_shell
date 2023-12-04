#include "string.h"

/**
 * _stoui - string to integer
 * @str: string to turn into an integer
 * Return: on success positive int, on fail -1
 */
int _stoui(const char *str)
{
	int result = 0;
	int digit;

	if (*str == '+')
		str++;

	while (*str == '0')
		str++;

	while (*str != '\0')
	{
		if (*str < '0' || *str > '9')
			return (-1);
		digit = *str - '0';

		if (result > (INT_MAX - digit) / 10)
			return (-1);

		result = result * 10 + digit;
		str++;
	}

	return (result);
}
