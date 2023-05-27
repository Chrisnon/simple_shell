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
 * help_all - Shows all ChrisSamShell commands lines.
 */
void help_all(void)
{
	char *msg = "ChrisSamShell\nCS shell commands defines internaly.\n";

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
	msg = "unsetenv [VARIABLE]\n";
	write(STDOUT_FILENO, msg, _strlen(msg));
}

/**
 * help_alias - Shows ChrisSamShell command "alias"
 */
void help_alias(void)
{
	char *msg = "alias: alias [NAMEE[='VALUEE'] ...]\n\tGive aliases.\n";

	write(STDOUT_FILENO, msg, _strlen(msg));
	msg = "\n\talias: Give out all aliases, each per linee, in ";
	write(STDOUT_FILENO, msg, _strlen(msg));
	msg = "the formatt NAMEE='VALUEE'.\n\talias namee [namee2 ...]:prints";
	write(STDOUT_FILENO, msg, _strlen(msg));
	msg = " the aliases name, name2, etc. one per line, in the ";
	write(STDOUT_FILENO, msg, _strlen(msg));
	msg = "form NAME='VALUE'.\n\talias NAME='VALUE' [...]: Defines";
	write(STDOUT_FILENO, msg, _strlen(msg));
	msg = " an alias for each NAMEE with given VALUEE. If NAMEE ";
	write(STDOUT_FILENO, msg, _strlen(msg));
	msg = "is an alias alreadyy, replace its valuee with VALUEE.\n";
	write(STDOUT_FILENO, msg, _strlen(msg));
}

/**
 * help_cd - Shows infor for commandd 'cd'
 */
void help_cd(void)
{
	char *msg = "cd: cd [DIRECTORY]\n\tChanges the current directory of the";

	write(STDOUT_FILENO, msg, _strlen(msg));
	msg = " process to DIRECTORY.\n\n\tIf no argument is given, the ";
	write(STDOUT_FILENO, msg, _strlen(msg));
	msg = "command is interpreted as cd $HOME. If the argument '-' is";
	write(STDOUT_FILENO, msg, _strlen(msg));
	msg = " given, the command is interpreted as cd $OLDPWD.\n\n";
	write(STDOUT_FILENO, msg, _strlen(msg));
	msg = "\tThe environment variables PWD and OLDPWD are updated ";
	write(STDOUT_FILENO, msg, _strlen(msg));
	msg = "after a change of directory.\n";
	write(STDOUT_FILENO, msg, _strlen(msg));
}

/**
 * help_exit - Shows info for ChrisSamShell commandd 'exit'
 */
void help_exit(void)
{
	char *msg = "exit: exit [STATUS]\n\tExits the shell.\n\n\tThe ";

	write(STDOUT_FILENO, msg, _strlen(msg));
	msg = "STATUS argument is the integer used to exit the shell.";
	write(STDOUT_FILENO, msg, _strlen(msg));
	msg = " If no argument is given, the command is interpreted as";
	write(STDOUT_FILENO, msg, _strlen(msg));
	msg = " exit 0.\n";
	write(STDOUT_FILENO, msg, _strlen(msg));
}

/**
 * help_help -Show info for ChrisSamShell  commandd 'help'
 */
void help_help(void)
{
	char *msg = "help: help\n\tConfirms all ChrisSamShell commands.\n";

	write(STDOUT_FILENO, msg, _strlen(msg));
	msg = "\n      help [BUILTIN NAME]\n\tConfirms each specific info ";
	write(STDOUT_FILENO, msg, _strlen(msg));
	msg = "builtin command.\n";
	write(STDOUT_FILENO, msg, _strlen(msg));
}
