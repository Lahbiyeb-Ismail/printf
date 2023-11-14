#include "main.h"

/**
 * print_un - Entry point
 *
 *  * @char_len: the total number of characters written
 *  * @args: int to print
 *  * @flags: void
 *
 * Description: Function that print unsigned integers
 *
 * Return: void
 *
 */

void print_un(int *char_len, va_list args, flags_t *flags)
{
	unsigned int n;

	if (flags->lg)
		n = va_arg(args, unsigned long int);
	else if (flags->sh)
		n = (unsigned short int)va_arg(args, int);
	else
		n = va_arg(args, unsigned int);

	print_num_base(char_len, (long)n, 10, 0);

	va_end(args);
}
