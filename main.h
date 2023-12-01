#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <sys/fcntl.h>

#define UNUSED(x) (void)(x)

#include "string.h"
#include "command.h"

/* INPUT */
int get_input(int *fd);
int get_line(char **lineptr, size_t *n, int *fd);
int count_tokens(char *line);
char **line_to_tokens(char *line);

/* OUTPUT */
int putstr(const char *str);
int putc(char c);
int prompt(void);

/* RUNCOMMAND */
int runcommand(cmd command, char **env);
int run_exec(file_cmd command, char **env);
int run_builtin(builtin_cmd command);
int run_multi(multi_cmd command, char **env);

/* ERRORS */
int print_err(const char *str);

/* SPECIAL CHARS */
char *resolve_special(char *s);

#endif /* MAIN_H */
