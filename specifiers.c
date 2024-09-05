#include "main.h"


/**
 * get_specifier - specifiers function
 * @spec: specifier in question
 * Return: pointer to the specifier function
 */
int (*get_specifier(char spec))(va_list *)
{
	int i;
	sp_map specifiers[] = {
		{'c', handle_char},
		{'s', handle_string},
		{'%', handle_percent},
		{'d', handle_int},
		{'i', handle_int},
		{'\0', NULL}
	};

	for (i = 0; specifiers[i].specifier; i++)
		if (spec == specifiers[i].specifier)
			return (specifiers[i].handler);
	return (NULL);
}

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


/**
 * handle_int - handles integer type
 * @arg: integer in question
 * Return: nb of bytes written
 */
int handle_int(va_list *arg)
{
	int n = va_arg(*arg, int);

	return (print_int(n));
}
