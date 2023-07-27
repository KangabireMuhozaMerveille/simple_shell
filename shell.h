#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <limits.h>

/* Data structure to hold environment variables */
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

#endif /* SHELL_H */

