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
 * cs_cmdd - commands in defined path from user input executed
 * @cmdd: front-end commands passes from arrary to stringgs
 * @input: frees input from user.
 * @c:execute not found from ChrisSamShell.
 * @argv: program start afer args || ChrisSamShell)
 * Return: wrong innput -1; 0 if exceuted; 1 if NULL.
 */
int cs_cmdd(char **cmdd, char *input, int c, char **argv)
{
	int wstatus;
	pid_t pid;

	if (*cmdd == NULL)
		return (EXIT_FAILURE);
	pid = fork();
	if (pid == -1)
	{
		perror("Error");
		return (-1);
	}
	if (pid == 0)
	{
		if (_strncmp(*cmdd, "./", 2) != 0 && _strncmp(*cmdd, "/", 1) != 0)
			path_cmd(cmdd);
		if (access(cmdd[0], R_OK) != 0)
		{
			print_error(cmdd[0], c, argv);
			free_all(cmdd, input);
			exit(127);
		}
		if (execve(*cmdd, cmdd, environ) == -1)
			return (2);
		else
			return (0);
	}
	wait(&wstatus);
	if (WIFEXITED(wstatus))
	{
		if (WEXITSTATUS(wstatus) == 0)
			return (0);
		else if (WEXITSTATUS(wstatus) == 2)
			return (2);
		else if (WEXITSTATUS(wstatus) == 127)
			return (127);
	}
	return (127);
}

/**
 * cs_sigg - Configures ^C not to terminate our shell
 * @sig: Incoming Signal
 */
void cs_sigg(int sigg)
{
	if (sigg == SIGINT)
	{
		PRINT("\n$ ");
	}
}

