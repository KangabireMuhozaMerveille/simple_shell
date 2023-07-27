#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <limits.h>
#include <errno.h>
#include "shell.h"

#define BUFFER_SIZE 1024
/**
 * main - This is the main function of the simple shell program.
 * It handles user input, executes commands, and interacts with the shell.
 * Return: The return value of the main function.
 */

int main(void)
{
	char command[BUFFER_SIZE];


	while (1)
	{
		printf(":) ");
		fflush(stdout);

		if (fgets(command, sizeof(command), stdin) == NULL)
		{
			printf("\n");
			break;
		}

		command[strcspn(command, "\n")] = '\0';
		if (strcmp(command, "env") == 0)
		{
			char **env = environ;

			while (*env)
			{
				printf("%s\n", *env);
				env++;
			}
		}
		else if (strcmp(command, "exit") == 0 || strcmp(command, "quit") == 0)
		{
			printf("Exiting the program.\n");
			break;
		}
	}
	return (0);
}
/**
    * cd_dot - Thisis used to make the
    * changes to the parent directory
    *
    * @datash: data relevant (environ)
    *
    * Return: no return
    */
void cd_dot(data_shell *datash)
{
	char pwd[PATH_MAX];
	char *dir, *cp_pwd, *cp_dir;

	getcwd(pwd, sizeof(pwd));
	dir = datash->args[1];
	if (chdir(dir) == -1)
	{
		errno = 2;
		printf("Error: %s\n", strerror(errno));
		return;
	}
	cp_pwd = strdup(pwd);
	setenv("OLDPWD", cp_pwd, 1);
	cp_dir = strdup(dir);
	setenv("PWD", cp_dir, 1);
	free(cp_pwd);
	free(cp_dir);
	datash->status = 0;
	chdir(dir);
}
/**
    * cd_previous - This makes changes
    * to the previous directory
    * @datash: data relevant (environ)
    * Return: no return
    */
void cd_previous(data_shell *datash)
{
	char pwd[PATH_MAX];
	char *p_pwd, *p_oldpwd, *cp_pwd, *cp_oldpwd;

	getcwd(pwd, sizeof(pwd));
	cp_pwd = strdup(pwd);

	p_oldpwd = getenv("OLDPWD");

	if (p_oldpwd == NULL)
		cp_oldpwd = cp_pwd;
	else
		cp_oldpwd = strdup(p_oldpwd);

	setenv("OLDPWD", cp_pwd, 1);

	if (chdir(cp_oldpwd) == -1)
		setenv("PWD", cp_pwd, 1);
	else
		setenv("PWD", cp_oldpwd, 1);

	p_pwd = getenv("PWD");

	write(STDOUT_FILENO, p_pwd, strlen(p_pwd));
	write(STDOUT_FILENO, "\n", 1);

	free(cp_pwd);
	if (p_oldpwd)
	free(cp_oldpwd);

	datash->status = 0;
}
