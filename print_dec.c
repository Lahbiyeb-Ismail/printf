#include "main.h"

/**
 * print_dec - Entry point
 *
 *  * @char_len: the total number of characters written
 *  * @args: int to print
 *  * @flags: flag for the '#'
 *
 * Description: Function that print decimal numbers
 *
 * Return: void
 *
 */

void print_dec(int *char_len, va_list args, flags_t *flags)
{
	long n = (long)va_arg(args, int);

	if (flags->space == 1 && flags->plus == 0 && n >= 0)
		(*char_len) += _putchar(' ');

	if (flags->plus == 1 && n >= 0)
		(*char_len) += _putchar('+');

	print_num_base(char_len, n, 10, 0);

	va_end(args);
}
