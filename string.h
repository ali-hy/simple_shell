#ifndef MY_STRING_H
#define MY_STRING_H

#include <string.h>

/* STRING */
char *copy(const char *s);
size_t len(const char *s);
char *concat(const char *s1, const char *s2);
int _strcmp(const char *s1, const char *s2);
char *_strtok(char *s, char delim);

/* STRING_2 */
int push(void ***arr, size_t *length, void *ptr);
int starts_with(const char *str, const char *prefix);
char **split(const char *str, const char *delim);

#endif /* MY_STRING_H */
