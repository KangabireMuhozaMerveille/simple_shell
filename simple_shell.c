#!/bin/bash
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

#define BUFFER_SIZE 1024

int main(void)
{
	char command[100];

	while (1)
	{
		printf(":) ");
		fflush(stdout);
      
		if (fgets(command, sizeof(command), stdin) == NULL)
			break; 

		command[strcspn(command, "\n")] = '\0';

		if (strcmp(command, "env") == 0)
		{
			extern char **environ;
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
		else
		{
	  
			char *args[BUFFER_SIZE];
			int arg_count = 0;
			char *token = strtok(command, " ");
			while (token != NULL && arg_count < BUFFER_SIZE - 1)
			{
				args[arg_count++] = token;
				token = strtok(NULL, " ");
			}
			args[arg_count] = NULL;

			if (arg_count > 0)
			{
				pid_t pid = fork();
				if (pid < 0)
				{
					perror("Fork error");
				}
				else if (pid == 0)
				{
					execvp(args[0], args);
					perror("Execution error");
					exit(1);
				}
				else
				{
					wait(NULL);
				}
			}
		}
    
	}
	return 0;
}

