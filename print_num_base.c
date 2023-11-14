#include "main.h"

/**
 * print_num_base - Entry point
 *
 * * @char_len: the total number of characters written
 * * @n: number to print
 * * @base: number base (10, 8, 16)
 * * @uppercase: 1 or 0 (1 = upper && 0 = lower)
 *
 * Description: Function that prints an integer.
 *
 * Return: nothing
 */

void print_num_base(int *char_len, long n, int base, int uppercase)
{
	long int n1;
	char c;
	char *symbols;
	char *lower_symbols = "0123456789abcdef";
	char *upper_symbols = "0123456789ABCDEF";

	symbols = uppercase == 1 ? upper_symbols : lower_symbols;

	if (n >= 0)
		n1 = n;
	else
	{
		n1 = -n;
		c = '-';
		(*char_len) += _putchar(c);
	}

	if (n1 < (long)base)
		(*char_len) += _putchar(symbols[n1]);

	else
	{
		print_num_base(char_len, (n1 / base), base, uppercase);
		c = symbols[n1 % base];

		(*char_len) += _putchar(c);
	}
}
