#include<stdio.h>
#include <stdlib.h>
#include<unistd.h>

extern char **environ;

int main()
{
	char command[100];

	while(1)
	{
		command[strlen(command) - 1] ='\0';

		if(strcmp(command, "env") == 0)
		{
			char **env = environ;
			while(*env)
			{
				printf("%s\n", *env);
				env++;
			}
			continue;
		}
	}
}
