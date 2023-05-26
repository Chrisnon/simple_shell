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
 * cs_err - shows message abt error.
 * @input: recieves user's input commands.
 * @counter: chrissamshell counts.
 * @argv: args of program beinning || chrissamshell)
 */

void cs_err(char *input, int counter, char **argv)
{
	char *err;

	PRINT(argv[0]);
	PRINT(": ");
	er = _itoa(counter);
	PRINT(err);
	free(err);
	PRINT(": ");
	PRINT(input);
	PRINT(": not found\n");
}

/**
 *  _cserr - customized error prints.
 * @argv: args of program beinning || chrissamshell)
 * @c: counts err
 * @cmdd: frontend of array od strings commands.
 */

void _cserr(char **argv, int c, char **cmdd)
{
	char *err = _itoa(c);

	PRINT(argv[0]);
	PRINT(": ");
	PRINT(err);
	PRINT(": ");
	PRINT(cmdd[0]);
	PRINT(": Unallowed number: ");
	PRINT(cmdd[1]);
	PRINT("\n");
	free(err);
}

/**
 * err_cs - customized errors prints
 * @argv: args of program beinning || chrissamshell)
 * @c: counts err
 */
void err_cs(char **argv, int c)
{
	char *err = _itoa(c);

	PRINT(argv[0]);
	PRINT(": ");
	PRINT(err);
	PRINT(": unable to open ");
	PRINT(argv[1]);
	PRINT("\n");
	free(err);
}

