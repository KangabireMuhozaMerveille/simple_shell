#include "shell.h"
#include <errno.h>

/**
  * cd_to - changes to a directory
  * given by the user
  *
  * @datash: data relevant (directories)
  * Return: no return
  */
void cd_to(data_shell *datash)
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
 * cd_to_home - This is used to make
 * changes to home directory
 *
 * @datash: data relevant (environ)
 * Return: no return
 */
void cd_to_home(data_shell *datash)
{
	char *p_pwd, *home;
	char pwd[PATH_MAX];

	getcwd(pwd, sizeof(pwd));
	p_pwd = strdup(pwd);

	home = getenv("HOME");

	if (home == NULL)
	{
		setenv("OLDPWD", p_pwd, 1);
		free(p_pwd);
		return;
	}

	if (chdir(home) == -1)
	{
		errno = 2;
		printf("Error: %s\n", strerror(errno));
		free(p_pwd);
		return;
	}

	setenv("OLDPWD", p_pwd, 1);
	setenv("PWD", home, 1);
	free(p_pwd);
	datash->status = 0;
}
