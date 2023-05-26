#include "chrissamshell.h"

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
 * cssep - disintegrate user's input characters;
 * @input: stringg characters from user's inputs
 * Return: user input strings as commandss. 
 */
char **cssep(char *input)
{
	char **commands;
	char *command;
	int i;
	int buffsize = BUFSIZE;

	if (input[0] == ' ' && input[_strlen(input)] == ' ')
		exit(0);
	if (input == NULL)
		return (NULL);
	commands = malloc(sizeof(char *) * buffsize);
	if (!commands)
	{
		free(commands);
		perror("hsh");
		return (NULL);
	}
	command = _strtok(input, ";&");
	for (i = 0; command; i++)
	{
		commands[i] = command;
		command = _strtok(NULL, ";&");
	}
	commands[i] = NULL;

	return (commands);
}

