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
 * csfind_cmdd -  execute comand in path.
 * @cmd: user inputt
 * Return: success on 0 or  1 on fail
 */
int csfind_cmdd(char **cmdd)
{
	char *csfind, *value, *cmdd_csfind;
	struct stat buf;

	csfind = _getenv("PATH");
	value = _strtok(csfind, ":");
	while (value != NULL)
	{
		cmdd_csfind = build(*cmdd, value);
		if (stat(cmdd_csfind, &buf) == 0)
		{
			*cmdd = _strdup(cmdd_csfind);
			free(cmdd_csfind);
			free(csfind);
			return (0);
		}
		free(cmdd_csfind);
		value = _strtok(NULL, ":");
	}
	free(csfind);
	free(value);
	return (1);
}

/**
 * csblt - commands builds up
 * @token: commands are executible
 * @value: command in dirr.
 * Return: frontend of commandd path or failed on NULL.
 */
char *csblt(char *token, char *value)
{
	char *cmdd;
	size_t len;

	len = _strlen(value) + _strlen(token) + 2;
	cmd = malloc(sizeof(char) * len);
	if (cmdd == NULL)
	{
		free(cmdd);
		return (NULL);
	}

	memset(cmdd, 0, len);

	cmdd = _strcat(cmdd, value);
	cmdd = _strcat(cmdd, "/");
	cmdd = _strcat(cmdd, token);

	return (cmdd);
}

/**
 * _obcsenvi - variablee value obtain by environ.
 * @name: namee of environ.
 * Return: environ variablee obtained or fails on NULL.
 */
char *_obcsenvi(char *name)
{
	size_t name_len, value_len;
	char *value;
	int i, j, k;

	name_len = _strlen(name);
	for (i = 0 ; environ[i]; i++)
	{
		if (_strncmp(name, environ[i], name_len) == 0)
		{
			value_len = _strlen(environ[i]) - name_len;
			value = malloc(sizeof(char) * value_len);
			if (!value)
			{
				free(value);
				perror("unable to alloc");
				return (NULL);
			}

			j = 0;
			for (k = name_len + 1; environ[i][k]; k++, j++)
			{
				value[j] = environ[i][k];
			}
			value[j] = '\0';

			return (value);
		}
	}
	return (NULL);
}

