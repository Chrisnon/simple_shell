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
 * help_env - Shows info about ChrisSamShell commandd 'env'
 */
void help_env(void)
{
	char *msg = "env: env\n\tPrint curr environ.\n";

	write(STDOUT_FILENO, msg, _strlen(msg));
}

/**
 * help_setenv - Show info for ChrisSamShell  commandd 'setenv'
 */
void help_setenv(void)
{
	char *msg = "setenv: setenv [VARIABLEE] [VALUEE]\n\tStarts neww";

	write(STDOUT_FILENO, msg, _strlen(msg));
	msg = "environ variable, or makes existings onee.\n\n";
	write(STDOUT_FILENO, msg, _strlen(msg));
	msg = "\tUpon fails, shows message to stderr.\n";
	write(STDOUT_FILENO, msg, _strlen(msg));
}

/**
 * help_unsetenv - Show ChrisSamShell infor for commandd
 * 'unsetenv'
 */
void help_unsetenv(void)
{
	char *msg = "unsetenv: unsetenv [VARIABLEE]\n\tTakeOut an ";

	write(STDOUT_FILENO, msg, _strlen(msg));
	msg = "environmental variable.\n\n\tUpon fail, show a ";
	write(STDOUT_FILENO, msg, _strlen(msg));
	msg = "message to stderr.\n";
	write(STDOUT_FILENO, msg, _strlen(msg));
}

/**
 * display_help - Shows cs commnadds.
 * @cmd: frontends commnadd.
 * @st: State of lastt commands executed.
 * Return: 0; Success.
 */
int display_help(char **cmd, __attribute__((unused))int st)
{
	if (!cmd[1])
		help_all();
	else if (_strcmp(cmd[1], "alias") == 0)
		help_alias();
	else if (_strcmp(cmd[1], "cd") == 0)
		help_cd();
	else if (_strcmp(cmd[1], "exit") == 0)
		help_exit();
	else if (_strcmp(cmd[1], "env") == 0)
		help_env();
	else if (_strcmp(cmd[1], "setenv") == 0)
		help_setenv();
	else if (_strcmp(cmd[1], "unsetenv") == 0)
		help_unsetenv();
	else if (_strcmp(cmd[1], "help") == 0)
		help_help();
	return (0);
}
