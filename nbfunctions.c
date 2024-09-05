#include "main.h"


/**
 * print_int - prints an int
 * @nb: int to be printed
 * Return: the number of bytes written
 */

int print_int(int nb)
{
	int count = 0;

	if (nb == 0)
		return (_printch('0'));
	if (nb == INT_MIN)
		count += _printstr("-2147483648");
	if (nb < 0)
	{
		count += _printch('-');
		nb = -nb;
	}
	if (nb / 10)
		count += print_int(nb / 10);
	count += _printch((nb % 10) + '0');
	return (count);
}
