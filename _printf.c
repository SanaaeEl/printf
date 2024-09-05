#include "main.h"


/**
 * print_format - handles the types of output
 * @format: chatacter string containing specifiers
 * @arg: argument to be printed
 * Return: the nb of bytes successfully printed
 */

static int print_format(const char *format, va_list *arg)
{
	int i = 0, t_count = 0, j, (*handler)(va_list *arg) = NULL;
	sp_map specifiers[] = {
		{'c', handle_char},
		{'s', handle_string},
		{'%', handle_percent},
		{'\0', NULL}
	};
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == '\0')
				return (-1);
			for (j = 0; specifiers[j].specifier != '\0'; j++)
			{
				if (format[i] == specifiers[j].specifier)
				{
					handler = specifiers[j].handler;
					break;
				}
			}
			if (handler)
			{
				t_count += handler(arg);
			}
			else
			{
				t_count += _printch(format[i - 1]);
				t_count += _printch(format[i]);
			}
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



