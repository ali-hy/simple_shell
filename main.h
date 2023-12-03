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

/* GLOBAL */
enum access_options
{
	SET_VARIABLE,
	GET_VARIABLE
};
int exit_status(enum access_options, int);

/* INPUT */
char **get_input(int fd);
int get_line(char **lineptr, size_t *n, int *fd);
char **line_to_tokens(char *line);

/* ALIASES */
char resolve_aliases(char **aliases, char *line);
char add_alias(char **aliases, char *line);

/* OUTPUT */
size_t put_s(const char *str);
int put_c(char c);
char *ultos(unsigned long ul);

/* PATHS */
int is_path(const char *command);
int is_dir(const char *pathname);
char *path_concat(const char *s1, const char *s2);
char *find_in_PATH(const char *command, char **env);

/* GETCOMMAND */
cmd *getcommand(const char *command, char **argv, char ***env);

/* RUNCOMMAND */
int runcommand(cmd *command, char **args, char ***env);
int run_exe(file_cmd *command, char **args, char **env);
int run_builtin(builtin_cmd *command, char **args, char ***env);
int run_multi(multi_cmd *command, char **args, char ***env);

/* ERRORS */
int _errno(int update);
int print_err(char **argv, const char *command, const char *error);

/* ENV */
int get_env(const char *varname, char **env);

/* BUILTIN */
/**
 * struct builtin_f - command-function pair
 * @command: command that calls builtin
 * @func: func to call, returns exit status
 */
struct builtin_f
{
	char *command;
	int (*func)(char **args, char ***env);
};
typedef struct builtin_f builtin_f;
cmd *find_builtin(const char *command);

int exit_builtin(char **args, char ***env);
int env_builtin(char **args, char ***env);

/* SPECIAL CHARS */
char *resolve_special(char *s);

#endif /* MAIN_H */
