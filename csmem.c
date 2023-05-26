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
 * _csrealloc -  using malloc to reallocated mem blokcss.
 *@ptr: pointerr
 *@oldd_cssize: prev pointerr size.
 *@neww_cssize: current pointerr size.
 *Return: Pointerr to re-allocated mem.
 */
void *_csrealloc(void *ptr, unsigned int oldd_cssize, unsigned int neww_cssize)
{
	void *result;

	if (neww_cssize == oldd_cssize)
		return (ptr);
	if (neww_cssize == 0 && ptr)
	{
		free(ptr);
		return (NULL);
	}
	result = malloc(neww_cssize);
	if (result == NULL)
	{
		free(result);
		return (NULL);
	}
	if (ptr == NULL)
	{
		fill_an_array(result, '\0', neww_cssize);
		free(ptr);
	}
	else
	{
		_memcpy(result, ptr, oldd_cssize);
		free(ptr);
	}
	return (result);
}

/**
 * permit_cs - allocatedd mem release
 * @cmdd: pointerss array
 * @line: pointerr character
 * Return: Void
 */
void permit_cs(char **cmdd, char *line)
{
	free(cmdd);
	free(line);
	cmdd = NULL;
	line = NULL;
}

/**
 * _cpycsmem - bytes of mem copied from src dest.
 *@destt: pointerr of destinatiion.
 *@src: pointerr of sourcee
 *@n: size to be copied
 *Return: destination's pointerr
 */
char *_cpycsmem(char *destt, char *src, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
	{
		destt[i] = src[i];
	}
	return (destt);
}

/**
 * cs_array_fill - constantt byte to occupy.
 *@a: void pointerr
 *@el: int
 *@len: lengtth forr int
 *Return: void pointerr
 */
void *cs_array_fill(void *a, int el, unsigned int len)
{
	char *p = a;
	unsigned int i = 0;

	while (i < len)
	{
		*p = el;
		p++;
		i++;
	}
	return (a);
}

/**
 * _cscalloc - malloc allocatess mem for arrayy.
 *@size: sizee
 *Return: void pointerr
 */
void *_calloc(unsigned int size)
{
	char *a;
	unsigned int i;

	if (size == 0)
		return (NULL);
	a = malloc(size);
	if (a == NULL)
		return (NULL);
	for (i = 0; i < size; i++)
	{
		a[i] = '\0';
	}
	return (a);
}

