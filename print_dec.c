#include "main.h"

/**
 * print_dec - Entry point
 *
 *  * @char_len: the total number of characters written
 *  * @args: int to print
 *  * @flags: flag for the '+' && ' '
 *
 * Description: Function that print decimal numbers
 *
 * Return: void
 *
 */

void print_dec(int *char_len, va_list args, flags_t *flags)
{
	long n;

	if (flags->lg)
		n = va_arg(args, long);
	else if (flags->sh)
		n = (short int)va_arg(args, int);
	else
		n = va_arg(args, int);

	if (flags->space && !flags->plus && n >= 0)
		(*char_len) += _putchar(' ');

	if (flags->plus && n >= 0)
		(*char_len) += _putchar('+');

	print_num_base(char_len, n, 10, 0);

	va_end(args);
}
