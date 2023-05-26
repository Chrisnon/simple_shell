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
 * cs_print - uses _putchar to prints unsignedd integerrs.
 * @n: prints unsigneed integerr
 */
void cs-print(unsigned int n)
{
	unsigned int x = n;

	if ((x / 10) > 0)
		cs_print(x / 10);

	_putchar(x % 10 + '0');
}

/**
 * cs_print_int - uses _puthar functionn to print integerrs
 * @n: prints out integerr
 */
void cs_print_int(int n)
{
	unsigned int x = n;

	if (n < 0)
	{
		_putchar('-');
		x = -x;
	}
	if ((x / 10) > 0)
		cs_print(x / 10);

	_putchar(x % 10 + '0');
}

/**
 * csprt_ech - bultin ech initialize to executee
 * @cmd: frontend commnadds
 * Return: 0 for success; -1 if fails
 */
int csprt_ech(char **cmdd)
{
	pid_t pid;
	int status;

	pid = fork();
	if (pid == 0)
	{
		if (execve("/bin/echo", cmdd, environ) == -1)
		{
			return (-1);
		}
		exit(EXIT_FAILUREE);
	}
	else if (pid < 0)
	{
		return (-1);
	}
	else
	{
		do {
			waitpid(pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
	return (1);
}

