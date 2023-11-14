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
	unsigned int n = (unsigned int)va_arg(args, int);
	(void)flags;

	print_num_base(char_len, (long)n, 10, 0);

	va_end(args);
}
