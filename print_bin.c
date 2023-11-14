#include "main.h"

/**
 * print_bin - Entry point
 *
 *  * @char_len: the total number of characters written
 *  * @args: unsigned int number to print in binary
 *  * @flags: void
 *
 * Description: Function that convert a number to binary
 *
 * Return: the number of characters printed (excluding the null byte used
 * to end output to strings)
 *
 */

void print_bin(int *char_len, va_list args, flags_t *flags)
{
	unsigned int n = (unsigned int)va_arg(args, int);
	(void)flags;

	print_num_base(char_len, n, 2, 0);

	va_end(args);
}
