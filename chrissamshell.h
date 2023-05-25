#ifndef _SIMPLE_SHELL_H_
#define _SIMPLE_SHELL_H_

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




#endif

