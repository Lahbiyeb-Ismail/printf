#include "main.h"

int str_len(char *s);

/**
 * print_rev - Entry point
 *
 *  * @char_len: A pointer to the variable tracking the number
 * of characters printed.
 *  * @args: string to print in reverse
 *  * @flags: void
 *
 * Description: Function that print a string in reverse
 *
 * Return: void
 *
 */

void print_rev(int *char_len, va_list args, flags_t *flags)
{
	char *str = va_arg(args, char *);
	int len, i = 0;
	(void)flags;

	if (!str)
		str = "(null)";

	len = str_len(str);

	for (i = len - 1; i >= 0; i--)
		(*char_len) += _putchar(str[i]);

	va_end(args);
}


/**
 * str_len - Entry point
 *
 *  * @s: string
 *
 * Description: Function that calculate the len of a string
 *
 * Return: string length
 *
 */

int str_len(char *s)
{
	int len = 0;

	while (s[len])
		len++;

	return (len);
}
