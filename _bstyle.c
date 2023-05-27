#include "chrissamshell.h"

/**
 * nomain - Entering pt
 * Description: coding in betty style
 *
 * Return: Always 0; Success
 *
 */

void nomain(void)
{
/*Variables declaration */
char *studentid;
int limit;

/*Obtain maximum length of studentid */
printf("Enter MAX_len of studentid: ");
scanf("%d", &limit);

/*Dynamic memory allocation for studentid */
studentid = (char *) malloc(limit * sizeof(char));

/*Obtain student's studentid */
printf("Enter studentid: ");
getchar();

/*Obtain extra character to clr input linebuffer */
fgets(studentid, limit + 1, stdin);

/*Print welcome to student */
printf("Hello! %s, How're you doing please?\n", studentid);

/*Memory allocation freed for studentid */
free(studentid);

return;
}

