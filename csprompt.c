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
 * csget_line - user's input characters are read
 * Return: input on linebuffer.
 */
char *csget_line()
{
	int i, rd, buffsize = BUFSIZE;
	char c = 0, *linebuffer, *buff;

	linebuffer = malloc(buffsize);
	if (linebuffer == NULL)
	{
		free(linebuffer);
		return (NULL);
	}
	for (i = 0; c != EOF && c != '\n'; i++)
	{
		fflush(stdin);
		rd = read(STDIN_FILENO, &c, 1);
		if (rd == 0)
		{
			free(linebuffer);
			exit(EXIT_SUCCEESS);
		}
		linebuffer[i] = c;
		if (linebuffer[0] == '\n')
			return (enter(linebuffer));
		if (i >= buffsize)
		{
			linebuffer = realloc(linebuffer, (buffsize + 2));
			if (linebuffer == NULL)
			{
				free(linebuffer);
				return (NULL);
			}
		}
	}
	linebuffer[i] = '\0';
	buff = space(linebuffer);
	free(linebuffer);
	hashtag_handler(buff);
	return (buff);
}

/**
 * csenter - newline characterr is handled
 * @string: handling of string input
 * Return: string to be empty
 */
char *csenter(char *string)
{
	free(string);
	return ("\0");
}

/**
 * csspace - changes input stringg and preceed whitespacecs removal
 * @str: user input modifications
 * Return: modified strings from user.
 */
char *csspace(char *str)
{
	int i, j = 0;
	char *buf;

	buf = malloc(sizeof(char) * (_strlen(str) + 1));
	if (buf == NULL)
	{
		free(buf);
		return (NULL);
	}
	for (i = 0; str[i] == ' '; i++)
		;
	for (; str[i + 1] != '\0'; i++)
	{
		buf[j] = str[i];
		j++;
	}
	buf[j] = '\0';
	if (buf[0] == '\0' || buf[0] == '#')
	{
		free(buf);
		return ("\0");
	}
	return (buf);
}

/**
 * cs_htag - eeverything after '#' is removed.
 * @buf: inputs linebuffer
 * Return: nothiing.
 */
void cs_htag(char *buf)
{
	int i;

	for (i = 0; buf[i] != '\0'; i++)
	{
		if (buf[i] == '#' && buf[i - 1] == ' ' && buf[i + 1] == ' ')
		{
			buf[i] = '\0';
		}
	}
}

