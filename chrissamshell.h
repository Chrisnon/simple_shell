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
 *        1. Samuel Atiemo
 *        2. Christian Obi
 *
 **********************************************************/

/*MACROS*/
#define DELIMITER " \t\r\n\a"
#define PRINT(c) (write(STDERR_FILENO, c, _strlen(c)))
#define BUFSIZE 10240


/*Standardized Libs*/
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <string.h>
#include <stdio.h>
#include <signal.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <stdarg.h>
#include <dirent.h>
#include <linux/limits.h>
#include <errno.h>


/*CS Mems*/
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
void *fill_an_array(void *a, int el, unsigned int len);
void free_env(char **env);
char *_memcpy(char *dest, char *src, unsigned int n);
void *_calloc(unsigned int size);
void free_all(char **input, char *line);

/*Inputt Functions and Misc for ChrisSamShell*/

char *_getline();
char **separator(char *input);
char *space(char *str);
void prompt(void);
unsigned int check_delim(char c, const char *str);
char *_strtok(char *str, const char *delim);
char *enter(char *string);
void hashtag_handler(char *buff);
int history(char *input);


/*Environ Handlings for ChrisSamShell*/

extern char **environ;
void create_envi(char **envi);
void free_env(char **env);

/*Handlings for ChrisSamShell Strinngs*/
int _strncmp(const char *s1, const char *s2, size_t n);
char *_strncpy(char *dest, char *src, int n);
char *_strcat(char *dest, char *src);
int _putchar(char c);
int _atoi(char *s);
char *_strdup(char *str);
void _puts(char *str);
int _strcmp(char *s1, char *s2);
int intlen(int num);
int _strlen(char *s);
char *_itoa(unsigned int n);
char *_strcpy(char *dest, char *src);
void array_rev(char *arr, int len);
char *_strchr(char *s, char c);
int _isalpha(int c);

/*ChrisSamShell Files Args Functionns*/

void read_file(char *file, char **argv);
void exit_bul_for_file(char **cmd, char *line, FILE *fd);
void treat_file(char *line, int count, FILE *fp, char **argv);

/*ChrisSamShell Args for Backend or Executee*/

char **parse_cmd(char *input);
int check_cmd(char **cmd, char *input, int c, char **argv);
int handle_builtin(char **cmd, int er);
void signal_to_handle(int sig);


/*CSPrint Functionns*/

void print_number_int(int n);
void print_number(unsigned int n);
int print_echo(char **cmd);

/*Err Handlings for ChrisSamShell*/

void print_error(char *input, int counter, char **argv);
void _prerror(char **argv, int c, char **cmd);
void error_file(char **argv, int c);

/*Struct Builtin Commandss*/

/**
 * struct _builtin - contain builtin commandss
 * functionns implements resectvely
 * @command: - builtin
 * @function: - customized pointer to
 * similar functions of builtin commandss.
 */
typedef struct _builtin
{
	char *command;
	int (*function)(char **line, int st);
} builtin;

/*CSPath*/

char *build(char *token, char *value);
int path_cmd(char **cmd);
char *_getenv(char *name);

/*CSHelpers*/

void help_env(void);
void help_history(void);
void help_alias(void);
void help_cd(void);
void help_exit(void);
void help_unsetenv(void);
void help_all(void);
void help_help(void);
int display_help(char **cmd, __attribute__((unused))int st);
void help_setenv(void);

/*Backend or Execute commands for builtin*/

int handle_builtin(char **cmd, int st);
int check_builtin(char **cmd);
int change_dir(char **cmd, __attribute__((unused))int st);
int dis_env(__attribute__((unused)) char **cmd,
	    __attribute__((unused)) int st);
void exit_bul(char **cmd, char *input, char **argv, int c, int stat);
int echo_bul(char **cmd, int st);
int history_dis(__attribute__((unused))char **c,
		__attribute__((unused)) int st);



#endif /*SIMPLE_SHELL_H_*/


