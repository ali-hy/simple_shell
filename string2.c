#include "string.h"

/**
 * starts_with - checks if a string starts with a substring
 * @str: string to check in
 * @prefix: substring to check for
 * Return: 1 if str starts with prefix, 0 if not
 */
int starts_with(const char *str, const char *prefix)
{
	while (*prefix != '\0')
	{
		if (*str != *prefix)
			return (0);
		str++;
		prefix++;
	}

	return (1);
}

/**
 * split - makes an array of strings from the original string (doesn't modify
 * original)
 * @str: string to split
 * @delim: string of allowed delimiters
 * Return: NULL-terminated array of strings
 */
char **split(const char *str, const char *delim)
{
	char **res = NULL, *s_copy = copy(str), *tok_start = NULL;
	size_t token_count = 0;

	tok_start = strtok(s_copy, delim);
	while (tok_start != NULL)
	{
		push((void ***)&res, &token_count, (void *)tok_start);
		tok_start = strtok(NULL, delim);
	}
	push((void ***)&res, &token_count, (void *)tok_start);
	token_count--;

	return (res);
}
