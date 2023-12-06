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
 * @res_str: a string where the copy of str (delimited with '\0') will be
 * placed
 * Return: NULL-terminated array of strings
 */
char **split(const char *str, const char *delim, char **res_str)
{
	char **res = NULL, *tok_start = NULL;
	size_t token_count = 0;

	if (str == NULL)
	{
		*res_str = NULL;
		return (NULL);
	}
	*res_str = copy(str);
	tok_start = _strtok((*res_str), delim);
	while (tok_start != NULL)
	{
		push((void ***)&res, &token_count, (void *)tok_start);
		tok_start = _strtok(NULL, delim);
	}
	push((void ***)&res, &token_count, (void *)tok_start);
	token_count--;

	return (res);
}

/**
 * copy_to - copy from a source string to destination string
 * @source: source string
 * @dest: destination string
 * Return: number of characters copied
 */
int copy_to(const char *source, char *dest)
{
	int i = 0;

	while (source[i] != '\0')
	{
		dest[i] = source[i];
		i++;
	}
	dest[i] = source[i];

	return (i - 1);
}

/**
 * find_char - find character in a string
 * @str: string to search in
 * @c: character to search for
 * Return: index of c in str, -1 if c isn't found in str
 */
int find_char(const char *str, char c)
{
	int i = 0;

	while (str[i] != '\0')
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (-1);
}
