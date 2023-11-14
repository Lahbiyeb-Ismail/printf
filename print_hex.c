#include "main.h"

/**
 * print_hex - Entry point
 *
 *  * @char_len: the total number of characters written
 *  * @args: int to print
 *  * @flags: flag for the '#'
 *
 * Description: Function that print hexadecimal numbers (base 16)
 *
 * Return: void
 *
 */

void print_hex(int *char_len, va_list args, flags_t *flags)
{
	unsigned int n = (unsigned int)va_arg(args, int);

	if (flags->hash == 1)
	{
		(*char_len) += _putchar('0');
		(*char_len) += _putchar('x');
	}

	print_num_base(char_len, (long)n, 16, 0);

	va_end(args);
}
