#include<string.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#define BUFFER_SIZE 1024
int main()
{
	char *line = NULL;
	size_t capacity = 0;
	ssize_t chars_read;
	char buffer[BUFFER_SIZE];
	ssize_t bytes_read;

	while ((chars_read = getline(&line, &capacity, stdin)) != -1)
	{	
		write(STDIN_FILENO, line, chars_read);

	}
        fseek(stdin, 0, SEEK_SET);

	while ((bytes_read = read(STDIN_FILENO, buffer, BUFFER_SIZE)) > 0)
        {
		write(STDIN_FILENO, buffer, bytes_read);
		if (strcmp(line, "exit") == 0 || strcmp(line, "quit") == 0)
		{
					break;
																							}
        }

	free(line);

        return 0;
}

