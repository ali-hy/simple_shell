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
#define IN_BUFFER_SIZE 128

#include "string.h"
#include "command.h"

/* GLOBAL */
/**
 * enum access_options - options for global var functions
 * @SET_VARIABLE: use to set a global
 * @GET_VARIABLE: uset to get a variable without updating global
 */
enum access_options
{
	SET_VARIABLE,
	GET_VARIABLE
};
int exit_status(enum access_options, int);
char **_env(enum access_options access_option, char **value);
char **prog_args(char **value);
void my_exit(int code);

/* FLOW */
void init_program(int ac, char **argv, char **env);
int should_exit(cmd *command, int exit_code);

/* TEST */
void test(void);

/* MEMORY */
int my_free(void **ptr);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);

/* INPUT */
char **get_input(int fd, char **temp);
int get_line(char **lineptr, int *n, int fd);
int get_in_fd(char *filename);

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
char *find_in_PATH(const char *command, char **temp);
int can_access(const char *command, const char *pathname);

/* GETCOMMAND */
cmd *getcommand(const char *command, char **temp);

/* RUNCOMMAND */
int runcommand(cmd *command, char **args);
int run_exe(file_cmd *command, char **args);
int run_builtin(builtin_cmd *command, char **args);
int run_multi(multi_cmd *command, char **args);

/* ERRORS */
int _errno(int update);
int print_err(const char *command, const char *error);

/* ENV */
void init_env(char **env);
void free_env_end(void);
int get_env(const char *varname);

/* BUILTIN */
/**
 * struct builtin_f - command-function pair
 * @command: command that calls builtin
 * @func: func to call, returns exit status
 */
struct builtin_f
{
	char *command;
	int (*func)(char **args);
};
typedef struct builtin_f builtin_f;
cmd *find_builtin(const char *command);

int exit_builtin(char **args);
int env_builtin(char **args);

/* SPECIAL CHARS */
char *resolve_special(char *s);

#endif /* MAIN_H */
