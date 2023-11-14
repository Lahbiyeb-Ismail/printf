#include "main.h"

/**
 * print_perc - Entry point
 *
 *  * @char_len: the total number of characters written
 *  * @args: string to print
 *  * @flags: void
 *
 * Description: Function that print a %
 *
 * Return: void
 *
 */

void print_perc(int *char_len, va_list args, flags_t *flags)
{
	char percent = '%';
	(void)args;
	(void)flags;

	*char_len += _putchar(percent);
}
