#include "main.h"

/**
 * print_HEX - Entry point
 *
 *  * @char_len: the total number of characters written
 *  * @args: int to print
 *  * @flags: flag for the '#'
 *
 * Description: Function that print hexadecimal numbers in uppercase (base 16)
 *
 * Return: void
 *
 */

void print_HEX(int *char_len, va_list args, flags_t *flags)
{
	unsigned long n;

	if (flags->hash == 1)
	{
		(*char_len) += _putchar('0');
		(*char_len) += _putchar('X');
	}

	if (flags->lg)
		n = va_arg(args, unsigned long);
	else if (flags->sh)
		n = (unsigned short int)va_arg(args, unsigned int);
	else
		n = va_arg(args, unsigned int);

	print_num_base(char_len, (long)n, 16, 1);

	va_end(args);
}
