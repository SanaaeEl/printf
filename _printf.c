#include "main.h"


/**
 * print_format - handles the types of output
 * @format: chatacter string containing specifiers
 * @arg: argument to be printed
 * Return: the nb of bytes successfully printed
 */

static int print_format(const char *format, va_list *arg)
{
	int i = 0, t_count = 0, (*handler)(va_list *arg);

	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == '\0')
				return (-1);
			handler = get_specifier(format[i]);
			t_count += handler ? handler(arg) : _printch('%') + _printch(format[i]);
		}
		else
		{
			t_count += _printch(format[i]);
		}

		i++;
	}
	return (t_count);
}

/**
 * _printf - produces output according to a format
 * @format: character string containing specifiers
 * Return: the nb of characters printed
 */


int _printf(const char *format, ...)
{
	int total_count = 0;
	va_list arg;

	if (!format)
	{
		return (-1);
	}
	va_start(arg, format);
	total_count = print_format(format, &arg);

	va_end(arg);
	return (total_count);
}



