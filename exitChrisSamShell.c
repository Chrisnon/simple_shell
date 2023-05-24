#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

/*********************************************************
 * Project: ALX Simple Shell
 *
 *
 * Team/Group/Collaboration Project

 *
 *
 * Date: 15/05/2023
 *
 *
 * Authors:
 *        1. Samuel Atiemo
 *        2. Christian Obi
 *
 **********************************************************/

/**
 * main - reads user's input characters
 *
 * Return: 0
 */
int main(void)
{
	char *command;
	char *buffer;
	int status;

	printf("$ ");

	while (1)
	{
		buffer = malloc(1024);
		fgets(buffer, 1024, stdin);

		if (buffer[0] == '\n')
		{
			free(buffer);
			break;
		}

		command = strtok(buffer, "\n");

		if (strcmp(command, "exit") == 0)
		{
			free(buffer);
			exit(0);
		}

		status = system(command);

		if (status != 0)
		{
			printf("Error executing command: %s\n", command);
		}

		free(buffer);

		printf("$ ");
	}

	return (0);
}
