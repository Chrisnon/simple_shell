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
 * check_cmd - commands in defined path from user input executed.
 * @cmd: frontend commands passes from array to stringg
 * @input: frees input from user.
 * @c:execute not found from ChrisSamShell.
 * @argv: program start after args || ChrisSamShell.
 * Return: Wrong inputt -1; o if executed; 1 if NULL.
 */
int check_cmd(char **cmd, char *input, int c, char **argv)
{
	int wstatus;
	pid_t pid;

	if (*cmd == NULL)
		return (EXIT_FAILURE);
	pid = fork();
	if (pid == -1)
	{
		perror("Error");
		return (-1);
	}
	if (pid == 0)
	{
		if (_strncmp(*cmd, "./", 2) != 0 && _strncmp(*cmd, "/", 1) != 0)
			path_cmd(cmd);
		if (access(cmd[0], R_OK) != 0)
		{
			print_error(cmd[0], c, argv);
			free_all(cmd, input);
			exit(127);
		}
		if (execve(*cmd, cmd, environ) == -1)
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
 * signal_to_handle - Configs ^C not to terminates ChrisSamShell
 * @sig: signall outcome.
 */
void signal_to_handle(int sig)
{
	if (sig == SIGINT)
	{
		PRINT("\n$ ");
	}
}
