#include "chrissamshell.h"

/**
*main - function that checks if our shell is called
*
*Return: 0 on success
*/
int main(void)
{
/* Determines if file descriptor is associated withh  terminal */
if (isatty(STDIN_FILENO) == 1)
{
shell_interactive();
}
else
{
shell_no_interactive();
}

return (0);
}
