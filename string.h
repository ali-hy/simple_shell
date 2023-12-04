#ifndef MY_STRING_H
#define MY_STRING_H

#include <stdio.h>
#include <string.h>
#include <limits.h>

/* STRING */
char *copy(const char *s);
size_t len(const char *s);
char *concat(const char *s1, const char *s2);
int _strcmp(const char *s1, const char *s2);
char *_strtok(char *s, const char *delim);

/* STRING_2 */
int push(void ***arr, size_t *length, void *ptr);
int starts_with(const char *str, const char *prefix);
int copy_to(const char *source, char *dest);
char **split(const char *str, const char *delim);
int find_char(const char *str, char c);

/* STRING_3 */
int _stoui(const char *str);

#endif /* MY_STRING_H */
