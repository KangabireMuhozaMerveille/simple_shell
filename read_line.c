#include "shell.h"

/**
 * read_line - This is used to
 * reads the input string.
 *
 * @i_eof: return value of
 * the getline function
 * Return: input string
 */
char *read_line(int *i_eof)
{
	char *input = NULL;
	size_t bufsize = 0;

	*i_eof = getline(&input, &bufsize, stdin);

	return (input);
}
