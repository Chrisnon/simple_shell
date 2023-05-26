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


/*PROTOTYPES*/
/* main.c */
void shell_interactive(void);
void shell_no_interactive(void);

/*shell_interactive.c */
char *read_line(void);
char **split_line(char *line);
int execute_args(char **args);

/* execute_args */
int new_process(char **args);

/* shell_no_interactive */
char *read_stream(void);

/*---Builtin func---*/
int own_cd(char **args);
int own_exit(char **args);
int own_env(char **args);
int own_help(char **args);



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

void _puts(char *str);
char *_strdup(char *str);
char *_strcat(char *dest, char *src);
int _strcmp(char *s1, char *s2);
int parse(char *line, int num_tokens, char *argv[], int failcount);
int exe(char *line, char **ar, char *nln, char **arry, char **argv, int flcnt);
void myfree(char *line, char **ar, char *newline, char **array);
int _strncmp(char *s1, char *s2, int len);
int checkbltin(char *line, char **ar, char *newline, char **array);
int numcount(char *line);
int searchpath(char *p, char **tokens);
int findonpath(char **tokens);
void executepath(char *p, char **tokens);
int _csshell(const char *format, ...);
int chkfmt(va_list *args, const char *format, int i);
int prchr(va_list *args);
int prstr(va_list *args);
int prdgt(va_list *args);
void getdigits(int n);
int _putchar(char c);
void changedir(char **ar);


#endif /* SIMPLE_SHELL_H_ */

