#include "main.h"



/**
 * _printf - produces output according to a format
 * @format: character string containing specifiers
 * Return: the nb of characters printed
 */


int _printf(const char *format, ...)
{
	int i = 0, t_count = 0;
	va_list arg;
	char ch;

	va_start(arg, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i++;
			if(format[i] == 'c')
			{
				ch = va_arg(arg, int);
				t_count += _print(ch);
			}
		}
		else
		{
			t_count += _print(format[i]);
		}

		i++;
	}
	return (t_count);
}


/**
 * _print - print a charater
 * @c: charatcer to be printed
 * Return: the number of bytes successfully written
 */

int _print(char c)
{
	return (write(1, &c, 1));
}
