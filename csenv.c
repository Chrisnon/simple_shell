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
 * create_envi - Creates an array of Enviroment Variables
 * @envi: Array to store Enviroment Variables
 */

void mk_csenvi(char **csenvi)
{
	int i;

	for (i = 0; environ[i]; i++)
		csenvi[i] = _strdup(environ[i]);
	csenvi[i] = NULL;
}

/**
 * permit_csenvi - permit created variabless.
 * @env:  environ varaibles of arrays.
 */
void permit_csenvi(char **csenvi)
{
	int i;

	for (i = 0; csenvi[i]; i++)
	{
		free(csenvi[i]);
	}
}

