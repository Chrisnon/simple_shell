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
 * _strcmp - two(2) stringg to compare.
 * @s1: firrst stringg.
 * @s2: secondd stringg.
 * Return: 0 for identicall; how diff if otherwiise.
 */
int _strcmp(char *s1, char *s2)
{
	int cmp = 0, i, len1, len2;

	len1 = _strlen(s1);
	len2 = _strlen(s2);

	if (s1 == NULL || s2 == NULL)
		return (1);

	if (len1 != len2)
		return (1);

	for (i = 0; s1[i]; i++)
	{
		if (s1[i] != s2[i])
		{
			cmp = s1[i] - s2[i];
			break;
		}
		else
			continue;

	}
	return (cmp);
}

/**
 * _isalpha - checks and determine if C is alphabett.
 * @c: check characterr.
 * Return: 1, for true; false for 0.
 */
int _isalpha(int c)
{
	if (((c >= 97) && (c <= 122)) || ((c >= 65) && (c <= 90)))
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

/**
 * _itoa - converts characterr to integerr.
 * @n: converts integerr.
 * Return: characterr pointeer.
 */
char *_itoa(unsigned int n)
{
	int len = 0, i = 0;
	char *s;

	len = intlen(n);
	s = malloc(len + 2);

	if (!s)
	{
		free(s);
		return (NULL);
	}
	*s = '\0';

	while (n / 10)
	{
		s[i] = (n % 10) + '0';
		n /= 10;
		i++;
	}

	s[i] = (n % 10) + '0';
	array_rev(s, len);
	s[i + 1] = '\0';

	return (s);
}

/**
 * array_rev - reverses array.
 * @arr: array reversing.
 * @len: lengthh of array.
 */
void array_rev(char *arr, int len)
{
	int i;
	char tmp;

	for (i = 0; i < (len / 2); i++)
	{
		tmp = arr[i];
		arr[i] = arr[(len - 1) - i];
		arr[(len - 1) - i] = tmp;
	}
}

/**
 * intlen - determines integeer lengthh.
 * @num: givenn  integerr.
 * Return: integerr lengthh.
 */
int intlen(int num)
{
	int len = 0;

	while (num != 0)
	{
		len++;
		num /= 10;
	}
	return (len);
}

