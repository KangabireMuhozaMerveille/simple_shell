#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <limits.h>

/**
 * struct data_shell - Data structure to hold environment variables
 * @args: Array of strings containing command arguments
 * @environ: Array of strings containing environment variables
 * @status: Status code of the shell
 * @datash: Pointer to the data_shell struct (used for internal purposes)
 * @prompt: Pointer to the shell prompt
 * @pid: Process ID of the shell
 * @cwd: Pointer to the current working directory
 * @home_dir: Pointer to the home directory
 * Description: This struct holds various data related to the shell
 *              and environment variables used by the shell.
 */
typedef struct data_shell
{
	char **args;
	char **environ;
	int status;
	struct data_shell *datash;
		char *prompt;
		int pid;
		char *cwd;
		char *home_dir;

} data_shell;
typedef struct builtin
{
	const char *name;
	int (*f)(data_shell *datash);
} builtin_t;
extern char **environ;
/* Utility Functions */
char *_strdup(const char *str);
char *_getenv(const char *name, char **environ);
size_t _strlen(const char *str);
void set_env(const char *name, const char *value, struct data_shell *datash);
void get_error(struct data_shell *datash, int exit_status);

/* Shell Functions */
void cd_dot(struct data_shell *datash);
void cd_to(struct data_shell *datash);
void cd_previous(struct data_shell *datash);
void cd_to_home(struct data_shell *datash);
void get_error(struct data_shell *datash, int code);
char *_strdup(const char *str);
void rev_string(char *s);
int exec_line(struct data_shell *datash);
int (*get_builtin(char *cmd))(data_shell *);
int cmd_exec(struct data_shell *datash);
#endif /* SHELL_H */

