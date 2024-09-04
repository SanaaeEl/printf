#include "main.h"




/**
 * _printch - prints a charater
 * @c: charatcer to be printed
 * Return: the number of bytes successfully written
 */

int _printch(char c)
{
	return (write(1, &c, 1));
}



/**
 * _printstr - prints a string
 * @str: charatcer to be printed
 * Return: the number of bytes successfully written
 */

int _printstr(char *str)
{
	int i = 0;

	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

