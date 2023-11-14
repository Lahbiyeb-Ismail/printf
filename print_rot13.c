#include "main.h"

/**
 * print_rot13 - Entry point
 *
 *  * @char_len: A pointer to the variable tracking the number
 * of characters printed.
 *  * @args: string to print in reverse
 *  * @flags: void
 *
 *
 * Description: Function that encodes a string using rot13.
 *
 * ROT13 ("rotate by 13 places", sometimes hyphenated ROT-13)
 * is a simple letter substitution cipher that replaces a
 * letter with the 13th letter after it in the latin alphabet.
 *
 *
 * Return: void
 *
 *
 */

void print_rot13(int *char_len, va_list args, flags_t *flags)
{
	char *str = va_arg(args, char *);
	int i = 0, j;
	char letters[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char replacements[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";
	(void)flags;

	while (str[i])
	{
		if (str[i] < 'A' || (str[i] > 'Z' && str[i] < 'a') || str[i] > 'z')
			(*char_len) += _putchar(str[i]);

		else
		{
			j = 0;
			while (letters[j])
			{
				if (str[i] == letters[j])
					(*char_len) += _putchar(replacements[j]);

				j++;
			}
		}
		i++;

	}
}
