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
void *_csrealloc(void *ptr, unsigned int oldd_cssize, unsigned int neww_cssize);
void *cs_array_fill(void *a, int el, unsigned int len);
void permit_csenvi(char **csenvi);
char *_cpycsmem(char *destt, char *src, unsigned int n);
void *_cscalloc(unsigned int size);
void permit_cs(char **input, char *line);

/*Inputt Functions and Misc for ChrisSamShell*/

char *csget_line();
char **cssep(char *input);
char *csspace(char *str);
void cs_prompt1(void);
unsigned int chk_csdelim(char c, const char *str);
char *_csstrk(char *str, const char *delim);
char *csenter(char *string);
void cs_htag(char *buf);
int csrec(char *input);


/*Environ Handlings for ChrisSamShell*/

extern char **environ;
void permit_csenvi(char **csenvi);
void mk_csenvi(char **csenvi);

/*Handlings for ChrisSamShell Strinngs*/
int _cmpcsstrn(const char *s1, const char *s2, size_t n);
char *_cpycsstrn(char *destt, char *src, int n);
char *_catcsstr(char *destt, char *src);
int _putchar(char c);
int _acs(char *s);
char *_dupcsstr(char *str);
void _cspts(char *str);
int _cmpcsstr(char *s1, char *s2);
int lencsint(int num);
int _lencsstr(char *s);
char *_acs(unsigned int n);
char *_cpycsstr(char *destt, char *src);
void rev_csarr(char *arr, int len);
char *_chrcsstr(char *s, char c);
int _csalph(int c);

/*ChrisSamShell Files Args Functionns*/

void cs_reads(char *reads, char **argv);
void cs_exitt(char **cmdd, char *line, FILE *fd);
void cs_treats(char *line, int count, FILE *fp, char **argv);

/*ChrisSamShell Args for Backend or Executee*/

char **csprt_cmdd(char *input);
int cs_cmdd(char **cmdd, char *input, int c, char **argv);
int cs_frontend(char **cmdd, int er);
void cs_sigg(int sigg);


/*CSPrint Functionns*/

void cs_print_int(int n);
void cs_print(unsigned int n);
int csprt_ech(char **cmdd);

/*Err Handlings for ChrisSamShell*/

void cs_err(char *input, int counter, char **argv);
void _cserr(char **argv, int c, char **cmdd);
void err_cs(char **argv, int c);

/*Struct Builtin Commandss*/

/**
 * struct _cst - contain builtin commandss
 * functionns implements resectvely
 * @command: - builtin
 * @function: - customized pointer to
 * similar functions of builtin commandss.
 */
typedef struct _cst
{
	char *command;
	int (*function)(char **line, int st);
} cst;

/*CSPath*/

char *csblt(char *token, char *value);
int csfind_cmdd(char **cmdd);
char *_obcsenvi(char *name);

/*CSHelpers*/

void cs_envi(void);
void help_history(void);
void cs_alias(void);
void cs_cdd(void);
void cs_exitt(void);
void cs_cssenvi(void);
void cs_shell(void);
void cs_cs(void);
int cs_prompt(char **cmdd, __attribute__((unused))int st);
void cs_csenvi(void);

/*Backend or Execute commands for builtin*/

int cs_frontend(char **cmdd, int st);
int frontend_parse(char **cmdd);
int cs_dirr(char **cmdd, __attribute__((unused))int st);
int cs_prompt(__attribute__((unused)) char **cmdd,
	    __attribute__((unused)) int st);
void exitx_blt(char **cmdd, char *input, char **argv, int c, int stat);
int cs_foo(char **cmdd, int st);
int rec_cs(__attribute__((unused))char **c,
		__attribute__((unused)) int st);



#endif /*SIMPLE_SHELL_H_*/

