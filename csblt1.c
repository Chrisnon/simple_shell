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
 * cs_shell - Shows all ChrisSamShell coomand lines.
 */
void cs_shell(void)
{
	char *msg = "ChrisSamShell\nCS shell commands defines internally.\n";

	write(STDOUT_FILENO, msg, _strlen(msg));
	msg = "Type 'cs' to see list.\nType 'cs namee' to show ";
	write(STDOUT_FILENO, msg, _strlen(msg));
	msg = "outt extra functions 'namee'.\n\n  alias   \t";
	write(STDOUT_FILENO, msg, _strlen(msg));
	msg = "alias [NAMEE[='VALUE'] ...]\n  cd    \tcd   ";
	write(STDOUT_FILENO, msg, _strlen(msg));
	msg = "[DIRECTORY]\n  exitt    \texitt [STATUS]\n  env     \tenv";
	write(STDOUT_FILENO, msg, _strlen(msg));
	msg = "\n  setenv  \tsetenv [VARIABLE] [VALUEE]\n  unsetenv\t";
	write(STDOUT_FILENO, msg, _strlen(msg));
	msg = "unsetenv [VARIABLEE]\n";
	write(STDOUT_FILENO, msg, _strlen(msg));
}

/**
 * cs_alias - Shows ChrisSamShell command 'alias'
 */
void cs_alias(void)
{
	char *msg = "alias: alias [NAMEE[='VALUEE'] ...]\n\Give aliases.\n";

	write(STDOUT_FILENO, msg, _strlen(msg));
	msg = "\n\talias: Give out all aliases, each per linee, in ";
	write(STDOUT_FILENO, msg, _strlen(msg));
	msg = "the formatt NAMEE='VALUEE'.\n\talias namee [namee2 ...]:gives";
	write(STDOUT_FILENO, msg, _strlen(msg));
	msg = " the aliases namee, namee2, etcc. each per linee, in thee ";
	write(STDOUT_FILENO, msg, _strlen(msg));
	msg = "formm NAMEE='VALUEE'.\n\talias NAMEE='VALUEE' [...]: defined";
	write(STDOUT_FILENO, msg, _strlen(msg));
	msg = " an alias for each NAMEE with given VALUEE. If NAMEE ";
	write(STDOUT_FILENO, msg, _strlen(msg));
	msg = "is an alias alreadyy, replace its valuee with VALUEE.\n";
	write(STDOUT_FILENO, msg, _strlen(msg));
}

/**
 * cs_cdd - Shows info for commandd 'cd'
 */
void cs_cdd(void)
{
	char *msg = "cdd: cdd [DIR]\n\tModifies curr. dir. of the";

	write(STDOUT_FILENO, msg, _strlen(msg));
	msg = " process to DIR.\n\n\tIf no arg is givenn, the ";
	write(STDOUT_FILENO, msg, _strlen(msg));
	msg = "commands is shown as cd $HOME. If the arg '-' is";
	write(STDOUT_FILENO, msg, _strlen(msg));
	msg = " given, the commandd is shown as cd $OLDPWD.\n\n";
	write(STDOUT_FILENO, msg, _strlen(msg));
	msg = "\tThe environ variables PWD and OLDPWD  updated ";
	write(STDOUT_FILENO, msg, _strlen(msg));
	msg = "after  change of dir.\n";
	write(STDOUT_FILENO, msg, _strlen(msg));
}

/**
 * cs_exitt - Shows info for ChrisSamShell commnadd 'exit'
 */
void cs_exitt(void)
{
	char *msg = "exitt: exitt [STATUS]\n\tExitts ChrisSamShell.\n\n\tThe ";

	write(STDOUT_FILENO, msg, _strlen(msg));
	msg = "STATUS arg is the integer utilized to exitt ChrisSamShell.";
	write(STDOUT_FILENO, msg, _strlen(msg));
	msg = " If arg given, command shown as";
	write(STDOUT_FILENO, msg, _strlen(msg));
	msg = " exitt 0.\n";
	write(STDOUT_FILENO, msg, _strlen(msg));
}

/**
 * help_help - Displays information on the shell by builtin command 'help'
 */
void help_help(void)
{
	char *msg = "help: help\n\tSee all possible Shellby builtin commands.\n";

	write(STDOUT_FILENO, msg, _strlen(msg));
	msg = "\n      help [BUILTIN NAME]\n\tSee specific information on each ";
	write(STDOUT_FILENO, msg, _strlen(msg));
	msg = "builtin command.\n";
	write(STDOUT_FILENO, msg, _strlen(msg));
}

