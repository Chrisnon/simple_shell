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
 * check_builtin - Checks for parse commands.
 * @cmd: commandd to be checked.
 * Return: 0, on success; -1 if fails.
 */
int check_builtin(char **cmd)
{
	builtin fun[] = {
		{"cd", NULL},
		{"help", NULL},
		{"echo", NULL},
		{"env", NULL},
		{"history", NULL},
		{NULL, NULL}
	};
	int i = 0;

	if (*cmd == NULL)
	{
		return (-1);
	}
	while ((fun + i)->command)
	{
		if (_strcmp(cmd[0], (fun + i)->command) == 0)
			return (0);
		i++;
	}
	return (-1);
}

/**
 * handle_builtin - Holds predefined built-ins user commands.
 * @cmd: Arr of parsed commnds.
 * @st: State of arr.
 * Return: 0 on success and -i if fails.
 */
int handle_builtin(char **cmd, int st)
{
	builtin built_in[] = {
		{"cd", change_dir},
		{"env", dis_env},
		{"help", display_help},
		{"echo", echo_bul},
		{"history", history_dis},
		{NULL, NULL}
	};
	int i = 0;

	while ((built_in + i)->command)
	{
		if (_strcmp(cmd[0], (built_in + i)->command) == 0)
		{
			return ((built_in + i)->function(cmd, st));
		}
		i++;
	}
	return (-1);
}

/**
 * exit_bul - exitt state for blt-in commnads.
 * @cmd: Arra of parse commands.
 * @input: free user's inputs.
 * @argv: Args starting programm || ChrisSamShell
 * @c: count ChrisSamShell executes.
 * @stat: Exitt statr
 */
void exit_bul(char **cmd, char *input, char **argv, int c, int stat)
{
	int status, i = 0;

	if (cmd[1] == NULL)
	{
		free(input);
		free(cmd);
		exit(stat);
	}
	while (cmd[1][i])
	{
		if (_isalpha(cmd[1][i++]) != 0)
		{
			_prerror(argv, c, cmd);
			free(input);
			free(cmd);
			exit(2);
		}
		else
		{
			status = _atoi(cmd[1]);
			if (status == 2)
			{
				_prerror(argv, c, cmd);
				free(input);
				free(cmd);
				exit(status);
			}
			free(input);
			free(cmd);
			exit(status);

		}
	}
}
