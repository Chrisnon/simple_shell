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
 * _cpycsstr - copyy stringg.
 * @destt: destinatiion.
 * @src: source from user's inputs.
 * Return: destinatiion.
 */
char *_cpycsstr(char *destt, char *src)
{
	int i = 0;

	while (src[i])
	{
		destt[i] = src[i];
		i++;
	}
	destt[i] = '\0';
	return (destt);
}

/**
 * _catcsstr - concatennates tow(2) stringss.
 * @destt: firrst stringg.
 * @src: secondd stringg.
 * Return: firrst stringg+secondd stringg
 */
char *_catcsstr(char *destt, char *src)
{
	char *s = destt;

	while (*destt != '\0')
	{
		destt++;
	}

	while (*src != '\0')
	{
		*destt = *src;
		destt++;
		src++;
	}
	*destt = '\0';
	return (s);
}

/**
 * _chrcsstr - locate characterr stringg.
 * @s: stringg search
 * @c: characterr loccated.
 * Return: pointer to characterr
 */
char *_chrcsstr(char *s, char c)
{
	do {
		if (*s == c)
		{
			break;
		}
	} while (*s++);
	return (s);
}

/**
 * _cmpcsstrn - compare two92) characters of stringg.
 * @s1: firrst stringg.
 * @s2: secondd stringg.
 * @n: compared characterrs.
 * Return: 1 for unmatched string; otherrwise 0.
 */
int _cmpcsstrn(const char *s1, const char *s2, size_t n)
{
	size_t i;

	if (s1 == NULL)
		return (-1);

	for (i = 0; i < n && s2[i]; i++)
	{
		if (s1[i] != s2[i])
		{
			return (1);
		}
	}
	return (0);
}

/**
 * _dupcsstr - a tring dupplication.
 * @str: stringg.
 * Return: string duplicate; or fail if NULL.
 */
char *_dupcsstr(char *str)
{
	size_t len, i;
	char *str2;

	len = _strlen(str);
	str2 = malloc(sizeof(char) * (len + 1));
	if (!str2)
	{
		return (NULL);
	}
	for (i = 0; i <= len; i++)
	{
		str2[i] = str[i];
	}
	return (str2);
}

