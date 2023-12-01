#include "main.h"

/**
 * len - get string length
 * @s: string
 * Return: length of s
 */
int len(const char *s)
{
	int i = 0;

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
