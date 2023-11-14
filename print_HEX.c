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
	unsigned int n = (unsigned int)va_arg(args, int);
	(void)flags;

	print_num_base(char_len, (long)n, 16, 1);

	va_end(args);
}
