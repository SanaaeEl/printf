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
	char ch, *str;

	if (format == NULL)
	{
		/**
		 * write(1, "", 0);
		 */
		return (- 1);
	}
	
	va_start(arg, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == 'c')
			{
				ch = va_arg(arg, int);
				t_count += _printch(ch);
			}
			else if (format[i] == 's')
			{
				str = va_arg(arg, char *);
				t_count += _printstr(str);
			}
			else if (format[i] == '%')
			{
				ch = '%';
				t_count += _printch(ch);
			}
			else
			{
				t_count += _printch(format[i - 1]);
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


