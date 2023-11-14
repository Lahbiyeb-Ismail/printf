#include "main.h"


/**
 * print_oct - Entry point
 *
 *  * @char_len: the total number of characters written
 *  * @args: int to print
 *  * @flags: flag for the '#'
 *
 * Description: Function that print octal numbers (base 8)
 *
 * Return: void
 *
 */

void print_oct(int *char_len, va_list args, flags_t *flags)
{
	unsigned int n = (unsigned int)va_arg(args, int);

	if (flags->hash == 1)
		(*char_len) += _putchar('0');

	print_num_base(char_len, (long)n, 8, 0);

	va_end(args);
}
