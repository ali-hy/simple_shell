#ifndef COMMAND_H
#define COMMAND_H

typedef enum CMD_TYPE
{
	builtin,
	file,
	multi,
	multi_and,
	multi_or
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
 * struct builtin_cmd - describes a builtin command
 * @type: ...
 * @builtin_func: function to call to execute builtin
 */
struct builtin_cmd
{
	cmd_type type;
	void (*builtin_func)(int);
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
 * cmd - type for struct cmd
 */
typedef struct cmd cmd;

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

#endif /* COMMAND_H */
