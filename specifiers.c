#include "main.h"

/**
 * sp_func - specifiers function
 * @arg: argument of type va_list
 */

typedef int (*sp_func)(va_list *arg);



/**
 * handle_char - handles char type
 * @arg: argument in question
 * Return: nb of bytes written
 */
int handle_char(va_list *arg)
{
	char ch = va_arg(*arg, int);

	return (_printch(ch));
}


/**
 * handle_string - handles string type
 * @arg: argument in question
 * Return: nb of bytes written
 */
int handle_string(va_list *arg)
{
	char *str;

	str = va_arg(*arg, char *);
	if (!str)
		str = "(null)";
	return (_printstr(str));
}



/**
 * handle_percent - handles percent character
 * @arg: argument in question
 * Return: nb of bytes written
 */
int handle_percent(va_list *arg)
{
	(void)arg;
	return (_printch('%'));
}



