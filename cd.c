#include "shell.h"

/**
 * cd_shell - This code
 * changes the current
 * working directory
 *
 * @datash: data relevant
 * Return: 1 on success
 */
int cd_shell(data_shell *datash)
{
	char *dir;
	int ishome, ishome2, isddash;

	dir = datash->args[1];

	if (dir != NULL)
	{
		ishome = strcmp("$HOME", dir);
		ishome2 = strcmp("~", dir);
		isddash = strcmp("--", dir);
	}

	if (dir == NULL || !ishome || !ishome2 || !isddash)
	{
		cd_to_home(datash);
		return (1);
	}

	if (strcmp("-", dir) == 0)
	{
		cd_previous(datash);
		return (1);
	}

	if (strcmp(".", dir) == 0 || strcmp("..", dir) == 0)
	{
		cd_dot(datash);
		return (1);
	}

	cd_to(datash);

	return (1);
}
