#ifndef COMMAND_H
#define COMMAND_H

/**
 * enum cmd_type - type of a cmd struct
 * @BUILTIN: ...
 * @EXE_FILE: ...
 * @MULTI: ...
 * @MULTI_AND: ...
 * @MULTI_OR: ...
 */
typedef enum cmd_type
{
	BUILTIN,
	EXE_FILE,
	MULTI,
	MULTI_AND,
	MULTI_OR
} cmd_type;

/**
 * struct cmd - describes a command
 * @type: type of command (enum COMMAND_TYPE)
 */
struct cmd
{
	cmd_type type;
};

/**
 * cmd - type for struct cmd
 */
typedef struct cmd cmd;

/**
 * struct builtin_cmd - describes a builtin command
 * @type: ...
 * @builtin_func: function to call to execute builtin
 */
struct builtin_cmd
{
	cmd_type type;
	int (*builtin_func)(char **args);
};

/**
 * struct file_cmd - describes an executable command
 * @type: ...
 * @pathname: path to file
 */
struct file_cmd
{
	cmd_type type;
	char *pathname;
};

/**
 * struct multi_cmd - describes multiple commands
 * @type: ...
 * @left: command on the left
 * @right: command on the right
 */
struct multi_cmd
{
	cmd_type type;
	cmd *left;
	cmd *right;
};

/**
 * builtin_cmd - type for struct builtin_cmd
 */
typedef struct builtin_cmd builtin_cmd;

/**
 * file_cmd - type for struct file_cmd
 */
typedef struct file_cmd file_cmd;

/**
 * multi_cmd - type for multiple commands
 */
typedef struct multi_cmd multi_cmd;

/* MAKECOMMAND */
cmd *make_builtincmd(void (*callback)(char **));
cmd *make_execmd(char *);
cmd *make_multicmd(char *);

#endif /* COMMAND_H */
