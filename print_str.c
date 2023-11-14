#include "main.h"

/**
 * print_str - Entry point
 *
 *  * @char_len: the total number of characters written
 *  * @args: string to print
 *  * @flags: void
 *
 * Description: Function that print a string
 *
 * Return: void
 *
 */

void print_str(int *char_len, va_list args, flags_t *flags)
{
	int len = 0;
	char *s = va_arg(args, char *);
	(void)flags;

	if (s == NULL)
		s = "(null)";

	while (s[len])
	{
		*char_len += _putchar(s[len]);
		len++;
	}
}
