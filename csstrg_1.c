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
 * _putchar -  writes character to stdout functionn
 * @c: character to print.
 * Return: character to stdout.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * _cspts - prints user's inputs stringg.
 * @str: pointerr to stringg.
 * Return: void.
 */
void _cspts(char *str)
{
	int i;

	for (i = 0; str[i] != '\0'; i++)
	{
		_putchar(str[i]);
	}
	_putchar('\n');
}

/**
 * _cpycsstrn - copy stringg.
 * @destt: destinatiion stringg.
 * @src: source striing
 * @n: copied characterr numbers
 * Return: stringg to copy.
 */
char *_cpycsstrn(char *destt, char *src, int n)
{
	int i = 0;

	while (i < n && *(src + i))
	{
		*(destt + i) = *(src + i);
		i++;
	}
	while (i < n)
	{
		*(destt + i) = '\0';
		i++;
	}
	return (destt);
}

/**
 * _lencsstr - count stringg lengthh.
 * @s: input stringg of user.
 * Return: stringg lengthh.
 */
int _lencsstr(char *s)
{
	int i;

	for (i = 0; s[i] != '\0'; i++)
	{
		continue;
	}
	return (i);
}

/**
 * _acs - conversion of stringg to integerr.
 * @s: input stringg from user.
 * Return: converrted integerr.
 */
int _acs(char *s)
{
	int i = 0, j = 1, k;
	unsigned int l = 0;

	while (s[i] != '\0')
	{
		if (s[i] == '-')
		{
			return (2);
		}
		k = s[i] - '0';

		if (l > 0 && !(k >= 0 && k <= 9))
			break;

		if (k >= 0 && k <= 9)
			l = l * 10 + k;

		i++;
	}
	l *= j;
	return (l);
}

