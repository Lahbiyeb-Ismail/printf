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
/**
 * print_hex_digit - Prints a hexadecimal digit in the format
 * '0'-'9' or 'A'-'F'.
 *
 *  * @char_len: the total number of characters written
 *  * @digit: string to print
 *
 * Description: This function takes an integer representing a
 * hexadecimal digit and prints it
 * to the standard output in the specified format.
 * If the digit is in the range
 * 0-9, it is printed as '0' to '9'. If the digit is 10 or greater,
 * it is printed
 * as 'A' to 'F'.
 *
 * Return: The number of characters printed.
 *
 */

void print_hex_digit(int digit, int *char_len)
{
	if (digit > 9)
		(*char_len) += _putchar(digit + 55);
	else
		(*char_len) += _putchar(digit + '0');
}

/**
 * nonprintable_char - Prints a non-printable character in hexadecimal format.
 *
 *  * @ascii: The non-printable ASCII character to be printed.
 *  * @char_len: A pointer to the variable tracking the number
 * of characters printed.
 *
 * Description: This function takes a non-printable ASCII character and
 * prints it in the
 * format '\x' followed by the ASCII code value in hexadecimal (always 2
 * characters).
 *
 * Return: void
 *
 */

void nonprintable_char(char ascii, int *char_len)
{
	int divide, module;

	(*char_len) += _putchar('\\');
	(*char_len) += _putchar('x');
	divide = ascii / 16;
	module = ascii % 16;


	print_hex_digit(divide, char_len);
	print_hex_digit(module, char_len);
}
