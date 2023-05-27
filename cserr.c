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
 * print_error - Shows message abt error.
 * @input: receives user's input commands.
 * @counter: ChrisSamShell counts
 * @argv: args of program beginningg || ChrisSamShell.
 */

void print_error(char *input, int counter, char **argv)
{
	char *er;

	PRINT(argv[0]);
	PRINT(": ");
	er = _itoa(counter);
	PRINT(er);
	free(er);
	PRINT(": ");
	PRINT(input);
	PRINT(": not found\n");
}

/**
 *  _prerror - customized error prints.
 * @argv: args of program beginning || ChrisSamShell.
 * @c: ount err.
 * @cmd: frontend of array of stringg commands.
 */

void _prerror(char **argv, int c, char **cmd)
{
	char *er = _itoa(c);

	PRINT(argv[0]);
	PRINT(": ");
	PRINT(er);
	PRINT(": ");
	PRINT(cmd[0]);
	PRINT(": Illegal number: ");
	PRINT(cmd[1]);
	PRINT("\n");
	free(er);
}

/**
 * error_file - customized errors prints.
 * @argv: args of program beginning || ChrisSamShell.
 * @c: counts err.
 */
void error_file(char **argv, int c)
{
	char *er = _itoa(c);

	PRINT(argv[0]);
	PRINT(": ");
	PRINT(er);
	PRINT(": Can't open ");
	PRINT(argv[1]);
	PRINT("\n");
	free(er);
}
