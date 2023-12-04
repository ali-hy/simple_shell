#include "main.h"

/**
 * len - get string length
 * @s: string
 * Return: length of s
 */
size_t len(const char *s)
{
	size_t i = 0;

	if (s == NULL)
		return (0);

	while (s[i] != '\0')
		i++;

	return (i);
}

/**
 * copy - copy a string
 * @s: string to copy
 * Return: new string
 */
char *copy(const char *s)
{
	int i, length = len(s);
	char *res = malloc(length + 1);

	if (res == NULL || s == NULL)
		return (NULL);

	for (i = 0; i < length; i++)
	{
		res[i] = s[i];
	}

	res[i] = '\0';

	return (res);
}

/**
 * concat - concatinate two stings
 * @s1: first string
 * @s2: second string
 * Return: pointer to concatinated string
 */
char *concat(const char *s1, const char *s2)
{
	int i, l1 = len(s1), l2 = len(s2);
	int l_res = l1 + l2;
	char *res;

	if (s1 == NULL)
		return (copy(s2));

	if (s2 == NULL)
		return (copy(s1));

	res = malloc(l_res + 1);
	if (res == NULL)
		return (NULL);

	for (i = 0; i < l1; i++)
	{
		res[i] = s1[i];
	}

	for (; i < l_res; i++)
	{
		res[i] = s2[i - l1];
	}

	res[i] = '\0';
	return (res);
}

/**
 * _strcmp - compare two strings
 * @s1: string 1
 * @s2: string 2
 * Return: 0 if they're equal, -1 if s1 is less than s2, 1 if s1 is greater
 * than s2
 */
int _strcmp(const char *s1, const char *s2)
{
	int i;

	if (s1 == NULL)
	{
		if (s2 == NULL)
			return (0);
		else
			return (-s2[0]);
	}
	else if (s2 == NULL)
	{
		return (s1[0]);
	}

	for (i = 0; s1[i] != '\0' && s2[i] != '\0'; i++)
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
	}

	if (s1[i] != s2[i])
		return (s1[i] - s2[i]);

	return (0);
}

/**
 * _strtok - get a token from a string
 * @str: token start
 * @delim: string of delimiters
 * Return: token start
 */
char *_strtok(char *str, const char *delim)
{
	static char *start;
	int i = 0;
	char *res = NULL;

	if (str != NULL)
		start = str;

	/* skip any delimiters at the start */
	while (start[i] != '\0')
	{
		if (find_char(delim, start[i]) == -1)
			break;
		i++;
	}

	start += i;
	i = 0;

	/* skip until you reach a delimiter */
	while (start[i] != '\0')
	{
		if (find_char(delim, start[i]) != -1)
			break;

		i++;
	}

	if (i == 0)
		return (NULL);

	if (start[i] == '\0')
	{
		res = start;
		start += +1;
		return (res);
	}

	start[i] = '\0';
	res = start;
	start += i + 1;

	return (res);
}
