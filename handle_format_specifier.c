#include "main.h"

/**
 * handle_format_specifier - Entry point
 *
 * * @format: A pointer to the format string containing text and
 * format specifiers.
 * * @args: A va_list of variable arguments to be formatted according
 * to the specifiers.
 *
 * Description: his function scans through the input format string,
 * identified by the '%' character,
 * and processes each format specifier accordingly.
 *
 *
 * Return: The total number of characters written to the standard
 * output (stdout). Returns -1 if an error occurs during processing.
 *
 */

int handle_format_specifier(const char *format, va_list args)
{
	int i, char_len;
	char *specifier;
	flags_t flags = { 0, 0, 0, 0, 0 };
	void (*get_specifier)(int *, va_list, flags_t *);

	i = 0, char_len = 0;
	for (; format[i]; i++)
	{
		flags_init(&flags);
		if (format[i] == '%')
		{
			if (format[i + 1] == ' ' && (format[i + 2] == '+'
				|| format[i + 2] == '#' || format[i + 2] == ' '))
				return (-1);

			while (handle_flags(format[i + 1], &flags))
				i++;
			if ((flags.plus && flags.space) || (flags.hash && flags.space))
				return (-1);
			while (handle_lengths(format[i + 1], &flags))
				i++;
			if (flags.lg && flags.sh)
				return (-1);
			specifier = copy_str(format[i + 1]);
			if (!specifier)
				return (-1);
			get_specifier = get_print_format(specifier);
			if (!get_specifier)
			{
				char_len += _putchar(format[i + 1]);
				free(specifier);
				continue;
			} get_specifier(&char_len, args, &flags);
			free(specifier);
			i++;
			continue;
		} char_len += _putchar(format[i]);
	}
	_putchar(-1);
	return (char_len);
}
