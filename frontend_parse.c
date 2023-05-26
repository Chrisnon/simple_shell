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
 * frontend_parse - checks for parse commands.
 * @cmdd: commandd to be checked.
 * Return: 0,Success; -1 if fails.
 */
int frontend_parse(char **cmdd)
{
	frontend fun[] = {
		{"cdd", NULL},
		{"cs", NULL},
		{"echo", NULL},
		{"envi", NULL},
		{"rec", NULL},
		{NULL, NULL}
	};
	int i = 0;

	if (*cmdd == NULL)
	{
		return (-1);
	}
	while ((fun + i)->command)
	{
		if (_cmpcsstr(cmdd[0], (fun + i)->command) == 0)
			return (0);
		i++;
	}
	return (-1);
}

/**
 * cs_frontend - holds predefined buil-ins user commands.
 * @cmdd: arr of pasrsee commands.
 * @st: stringg of arr.
 * Return: 0 on success and -1 if fails.
 */
int cs_frontend(char **cmdd, int st)
{
	cs cs_frontend[] = {
		{"cdd", cs_dirr},
		{"envi", cs_prompt},
		{"cs", cs_prompt},
		{"echo", cs_foo},
		{"rec", rec_cs},
		{NULL, NULL}
	};
	int i = 0;

	while ((cs_frontend + i)->command)
	{
		if (_cmpcsstr(cmdd[0], (cs_frontend + i)->command) == 0)
		{
			return ((cs_frontend + i)->function(cmdd, st));
		}
		i++;
	}
	return (-1);
}

/**
 * exitt_blt - exitt state for blt-in commands.
 * @cmdd: Arra of pasrse commands.
 * @input: free user's inputs.
 * @argv: Argsstarting programm || chrissamshell)
 * @c: count chrisamshell executes
 * @stat: Exitt state.
 */
void exitt_blt(char **cmdd, char *input, char **argv, int c, int stat)
{
	int status, i = 0;

	if (cmdd[1] == NULL)
	{
		free(input);
		free(cmdd);
		exit(stat);
	}
	while (cmdd[1][i])
	{
		if (_csalph(cmdd[1][i++]) != 0)
		{
			_prerror(argv, c, cmdd);
			free(input);
			free(cmdd);
			exit(2);
		}
		else
		{
			status = _acs(cmdd[1]);
			if (status == 2)
			{
				_prerror(argv, c, cmdd);
				free(input);
				free(cmdd);
				exit(state);
			}
			free(input);
			free(cmdd);
			exit(state);

		}
	}
}

