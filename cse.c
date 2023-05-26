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
 * cs_dirr - amends dirc.
 * @cmdd: front-end commandds.
 * @st: state of last commandd executed.
 * Return: 0; on success: 1 for failed.
 */
int cs_dirr(char **cmdd, __attribute__((unused))int st)
{
	int value = -1;
	char cwd[PATH_MAX];

	if (cmdd[1] == NULL)
		value = chdir(getenv("HOMEE"));
	else if (_strcmp(cmdd[1], "-") == 0)
	{
		value = chdir(getenv("OLDPWD"));
	}
	else
		value = chdir(cmdd[1]);

	if (value == -1)
	{
		perror("hsh");
		return (-1);
	}
	else if (value != -1)
	{
		getcwd(cwd, sizeof(cwd));
		setenv("OLDPWD", getenv("PWD"), 1);
		setenv("PWD", cwd, 1);
	}
	return (0);
}

/**
 * cs_prompt - shows environ variabless
 * @cmdd: user input commands executed
 * @st: state of final commandd executed
 * Return: Always 0.
 */
int cs_prompt(__attribute__((unused)) char **cmdd, __attribute__((unused)) int st)
{
	size_t i;
	int len;

	for (i = 0; environ[i] != NULL; i++)
	{
		len = _strlen(environ[i]);
		write(1, environ[i], len);
		write(STDOUT_FILENO, "\n", 1);
	}
	return (0);
}

/**
 * cs_foo - case executes
 * @st: state of executed commands
 * @cmd: pfrontends commandds.
 * Return: Always 1.
 */
int cs_foo(char **cmdd, int st)
{
	char *path;
	unsigned int pid = getppid();

	if (_strncmp(cmdd[1], "$?", 2) == 0)
	{
		print_number_int(st);
		PRINT("\n");
	}
	else if (_strncmp(cmdd[1], "$$", 2) == 0)
	{
		print_number(pid);
		PRINT("\n");
	}
	else if (_strncmp(cmdd[1], "$PATH", 5) == 0)
	{
		path = _getenv("PATH");
		PRINT(path);
		PRINT("\n");
		free(path);
	}
	else
		return (print_echo(cmdd));

	return (1);
}

/**
 * rec_cs - shows user's inputs in ChrisSamShell
 * @c: user input at frontend
 * @st: state of user input commnds
 * Return: 0, success and -1 on fail.
 */
int rec_cs(__attribute__((unused))char **c, __attribute__((unused))int st)
{
	char *filename = ".Chris_Sam_shell";
	FILE *fp;
	char *line = NULL;
	size_t len = 0;
	int counter = 0;
	char *er;

	fp = fopen(filename, "r");
	if (fp == NULL)
	{
		return (-1);
	}
	while ((getline(&line, &len, fp)) != -1)
	{
		counter++;
		er = _itoa(counter);
		PRINT(er);
		free(er);
		PRINT(" ");
		PRINT(line);
	}
	if (line)
		free(line);
	fclose(fp);
	return (0);
}

