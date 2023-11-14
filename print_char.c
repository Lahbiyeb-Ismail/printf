#include "main.h"

/**
 * print_char - Entry point
 *
 *  * @char_len: the total number of characters written
 *  * @args: char to print
 *  * @flags: void
 *
 *
 * Description: Function that print a char
 *
 * Return: the total number of characters written is returned.
 *
 */

void print_char(int *char_len, va_list args, flags_t *flags)
{
	int c = va_arg(args, int);
	(void)flags;

	*char_len += _putchar(c);
}
