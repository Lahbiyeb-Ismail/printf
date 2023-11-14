#include "main.h"

void print_hex_digit(int digit, int *char_len);
void nonprintable_char(char ascii, int *char_len);

/**
 * print_ascii - Prints a string with special formatting for
 * non-printable ASCII characters.
 *
 *  * @char_len: the total number of characters written
 *  * @args: string to print
 *  * @flags: void
 *
 * Description: Function that print ascii characters
 *
 * Return: void
 *
 */

void print_ascii(int *char_len, va_list args, flags_t *flags)
{
	char *s = va_arg(args, char *);
	char ascii;
	int i;
	(void)flags;

	if (s == NULL)
		s = "(null)";

	i = 0;

	while (s[i])
	{
		ascii = s[i];
		if ((ascii > 0 && ascii < 32) || ascii >= 127)
			nonprintable_char(ascii, char_len);
		else
			(*char_len) += _putchar(s[i]);

		i++;
	}

	va_end(args);
}
