#include "main.h"



/**
 * _printf - produces output according to a format
 * @format: character string containing specifiers
 * Return: the nb of characters printed
 */




int _printf(const char *format, ...)
{
	ssize_t nb;

	nb = write(STDOUT_FILENO, format, strlen(format));
	if (nb == -1)
		return (-1);
	return (nb);
}
