#include<string.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#define BUFFER_SIZE 1024

int main()
{
	int fd;
        const char* message = ":)";
	ssize_t bytes_written;

	fd = STDOUT_FILENO;

	if (isatty(fd))
   	{
		bytes_written = write(fd, message, strlen(message));

		if (bytes_written == -1)
		{
			perror("ERROR");
			return (1);
		}
	}
}
