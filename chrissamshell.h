#ifndef SIMPLE_SHELL_H_
#define SIMPLE_SHELL_H_

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
 *	  1. Samuel Atiemo
 *        2. Christian Obi
 *
 **********************************************************/


int main(void);

int _strlen(char *s);


/*** Standardized Header Library Files ***/
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <dirent.h>
#include <stdarg.h>
#include <sys/types.h>
#include <signal.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <linux/limits.h>
#include <string.h>



/*Macros*/
#define TOK_DELIM " \t\r\n\a\""
extern char **environ;


/*STRUCTS*/

/**
 * struct fmt - data types with respective functionns.
 * @ltr: data type
 * @type: data type of pinter to function.
 */
typedef struct fmt
{
	char *ltr;
	int (*type)();
} fmt;

/*Functions Module#1 */
int _csshell(const char *format, ...);
int numcount(char *line);
void _puts(char *str);
char *_strcat(char *dest, char *src);
int parse(char *line, int num_tokens, char *argv[], int failcount);
int cse(char *line, char **ar, char *nln, char **arry, char **argv, int flcnt);
int _strncmp(char *s1, char *s2, int len);
void changedir(char **ar);
int checkbltin(char *line, char **ar, char *newline, char **array);
int searchpath(char *p, char **tokens);
char *_strdup(char *str);
int findonpath(char **tokens);
void executepath(char *p, char **tokens);
int chkfmt(va_list *args, const char *format, int i);
int prchr(va_list *args);
int _strcmp(char *s1, char *s2);
int prstr(va_list *args);
void myfree(char *line, char **ar, char *newline, char **array);
int prdgt(va_list *args);
void getdigits(int n);
int _putchar(char c);



#endif /* SIMPLE_SHELL_H_ */

