#include "main.h"



/**
 * _printf - produces output according to a format
 * @format: character string containing specifiers
 * Return: the nb of characters printed
 */




int _printf(const char *format, ...)
{
	int tcount = 0, c;
	char ch;
	va_list arg;
	const char *p = format;

	va_start(arg, format);
	if (!format)
		return (-1);
	while (*p)
	{
		if (*p == '%')
		{
			++p;
			if (*p == 'c')
			{
				ch = va_arg(arg, int);
				c = write(STDOUT_FILENO, &ch, 1);
				tcount += c;
			}
			else
			{
				va_end(arg);
				return (- 1);
			}
		}
		else
		{
			c = write(STDOUT_FILENO, &ch, 1);
			tcount += c;
			if (c == - 1)
			{
				va_end(arg);
				return (- 1);
			}
		}
		++p;
	}
	va_end(arg);
	return (tcount);
}
