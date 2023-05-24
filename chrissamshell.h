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


/*Mem Handlers*/
void free_all(char **input, char *line);
void *_calloc(unsigned int size);
void *fill_an_array(void *a, int el, unsigned int len);
char *_memcpy(char *dest, char *src, unsigned int n);
void free_env(char **env);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
void print_prompt1(void);
void print_prompt2(void);
char *read_cmd(void);


/*MCS*/
#define BUFSIZE 1024
#define DELIMITER " \t\r\n\a"
#define PRINT(c) (write(STDERR_FILENO, c, _strlen(c)))



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

/*String Handling Functns*/
int _strncmp(const char *s1, const char *s2, size_t n);
int _strlen(char *s);
char *_strncpy(char *destn, char *src, int n);
int _putchar(char c);
void _puts(char *str);
char *_strcpy(char *destn, char *src);
int _isalpha(int c);
int execute_command(char **args)
int intlen(int num);
int _atoi(char *s);
char *_itoa(unsigned int n);
char *_strcat(char *destn, char *src);
void array_rev(char *arr, int len);
char *_strchr(char *s, char c);
char *_strdup(char *str);
int _strcmp(char *s1, char *s2);

int main(void);
void exit_chrissamshell();

/*MISC and Inputt Functns*/
unsigned int check_delim(char c, const char *str);
void hashtag_handler(char *buff);
char *space(char *str);
int history(char *input);
char *enter(char *string);
void prompt(void);
char *_strtok(char *str, const char *delim);
char *_getline();
char **separator(char *input);

/*File Args Functns Handlers*/
void exit_bul_for_file(char **cmd, char *line, FILE *fd);
void treat_file(char *line, int count, FILE *fp, char **argv);
void read_file(char *file, char **argv);


/*Parse Args Functns Handlers*/
int check_cmd(char **cmd, char *input, int c, char **argv);
char **parse_cmd(char *input);
char **parse_command(char *input);
void signal_to_handle(int sig);

/*Handling Errors*/
void print_error(char *input, int counter, char **argv);
void _prerror(char **argv, int c, char **cmd);
void error_file(char **argv, int c);

/*Handling Environments*/
void free_env(char **env);
void free_args(char **args)
extern char **environ;
void create_envi(char **envi);


/*Print Functns*/
int print_echo(char **cmd);
void print_number(unsigned int n);
void print_number_int(int n);


/*Path Findlers *******/
char *_getenv(char *name);
int path_cmd(char **cmd);
char *build(char *token, char *value);

/*Help Handlingg*/
void help_unsetenv(void);
void help_env(void);
void help_setenv(void);
void help_alias(void);
void help_cd(void);
void help_help(void);
int display_help(char **cmd, __attribute__((unused))int st);
void help_exit(void);
void help_all(void);
void help_history(void);

/*Handlingg Builtins Command and Executepath*/
void exit_bul(char **cmd, char *input, char **argv, int c, int stat);
int handle_builtin(char **cmd, int st);
int change_dir(char **cmd, __attribute__((unused))int st);
int check_builtin(char **cmd);
int echo_bul(char **cmd, int st);

/*Structs Builtins Command*/

/**
 * struct _builtin - struct have type of data with their builtin commandss
 * have respective functionns of implementations.
 * @command: - builtin command
 * @function: - pointer to customized functiions having
 * similarities in functions as builtin commands
 */
typedef struct _builtin
{
	char *command;
	int (*function)(char **line, int st);
} builtin;

/* FUNCTIONS Module #1 */
int numcount(char *line);
int _printf(const char *format, ...);
int prstr(va_list *args);
int findonpath(char **tokens);
int parse(char *line, int num_tokens, char *argv[], int failcount);
int checkbltin(char *line, char **ar, char *newline, char **array);
int searchpath(char *p, char **tokens);
int exe(char *line, char **ar, char *nln, char **arry, char **argv, int flcnt);
void executepath(char *p, char **tokens);
int chkfmt(va_list *args, const char *format, int i);
int prchr(va_list *args);
void _puts(char *str);
void myfree(char *line, char **ar, char *newline, char **array);
int prdgt(va_list *args);
void getdigits(int n);
int _putchar(char c);
void changedir(char **ar);



#endif /* _SIMPLE_SHELL_H_ */

