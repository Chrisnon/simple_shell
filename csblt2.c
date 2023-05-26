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
 * cs_envi - Shows info about ChrisSamShell commandd 'envi'
 */
void cs_envi(void)
{
	char *msg = "envi: envi\n\tPrint currr environ.\n";

	write(STDOUT_FILENO, msg, _strlen(msg));
}

/**
 * cs_csenvi - Shows info for ChrisSamShell commandd 'csenvi'
 */
void cs_csenvi(void)
{
	char *msg = "csenvi: csenvi [VARIABLEE] [VALUEE]\n\tStarts neww";

	write(STDOUT_FILENO, msg, _strlen(msg));
	msg = "environ variables, or makes existings onee.\n\n";
	write(STDOUT_FILENO, msg, _strlen(msg));
	msg = "\tUpon fails, shows message to stderr.\n";
	write(STDOUT_FILENO, msg, _strlen(msg));
}

/**
 * cs_cssenvi - Shows ChrisSamShell info for commandd 'cssenvi'
 */
void cs_cssenvi(void)
{
	char *msg = "cssenvi: cssenvi [VARIABLEE]\n\tTakeOut an ";

	write(STDOUT_FILENO, msg, _strlen(msg));
	msg = "environ variablee.\n\n\tUpon fail, show a ";
	write(STDOUT_FILENO, msg, _strlen(msg));
	msg = "message to stderr.\n";
	write(STDOUT_FILENO, msg, _strlen(msg));
}

/**
 * cs_prompt - shows cs commands
 * @cmd: fron-ends commandd
 * @st: state of lastt commands exxecuted.
 * Return: 0; on Success.
 */
int cs_prompt(char **cmdd, __attribute__((unused))int st)
{
	if (!cmdd[1])
		cs_shell();
	else if (_strcmp(cmdd[1], "alias") == 0)
		cs_alias();
	else if (_strcmp(cmdd[1], "cd") == 0)
		cs_cdd();
	else if (_strcmp(cmdd[1], "exit") == 0)
		cs_exitt();
	else if (_strcmp(cmdd[1], "env") == 0)
		cs_envi();
	else if (_strcmp(cmdd[1], "setenv") == 0)
		cs_csenvi();
	else if (_strcmp(cmdd[1], "unsetenv") == 0)
		cs_cssenvi();
	else if (_strcmp(cmd[1], "help") == 0)
		cs_cs();
	return (0);
}

