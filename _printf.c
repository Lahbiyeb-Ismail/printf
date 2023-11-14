#include "main.h"

/**
 * _printf - Entry point
 *
 * * @format: A pointer to the format string containing text and
 * format specifiers.
 *
 * Description: Clone of the printf function
 *
 * Prototype: void _printf(const char *format, ...);
 *
 * Return: the total number of characters written is returned.
 *
 */

int _printf(const char *format, ...)
{
	va_list args;
	int char_len = 0;

	if (!format || (format[0] == '%' && !format[1]))
		return (-1);

	if (format[0] == '%' && format[1] == ' ' && !format[2])
		return (-1);

	va_start(args, format);

	char_len += handle_format_specifier(format, args);

	va_end(args);
	return (char_len);
}

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
		if (format[i] == '%')
		{
			while (handle_flags(format[i + 1], &flags))
				i++;

			if (handle_lengths(format[i + 1], &flags))
				i++;

			specifier = copy_str(format[i + 1]);
			if (!specifier)
				return (-1);

			get_specifier = get_print_format(specifier);
			if (!get_specifier)
			{
				char_len += _putchar(format[i]);
				free(specifier);
				continue;
			}
			get_specifier(&char_len, args, &flags);
			free(specifier);
			i++;
			continue;
		}
		char_len += _putchar(format[i]);
	}
	_putchar(-1);
	return (char_len);
}


/**
 * handle_flags - Entry point
 *
 * * @format: A pointer to the format string containing text and
 * format specifiers.
 * * @flags: Pointer to the flags struture
 *
 * Description: Handles flags in the format specifier and retrieves
 * the specifier.
 *
 *
 * Return: the specifier
 *
 */

int handle_flags(char format, flags_t *flags)
{
	int i = 0;

	switch (format)
	{
		case '+':
			i = flags->plus = 1;
			break;
		case ' ':
			i = flags->space = 1;
			break;
		case '#':
			i = flags->hash = 1;
			break;
	}

	return (i);
}

/**
 * handle_lengths - Entry point
 *
 * * @format: A pointer to the format string containing text and
 * format specifiers.
 * * @flags: Pointer to the flags struture
 *
 *
 * Description: Handles flags in the format specifier and retrieves
 * the specifier.
 *
 *
 * Return: the specifier
 *
 */

int handle_lengths(char format, flags_t *flags)
{
	int i = 0;

	switch (format)
	{
		case 'l':
			i = flags->lg = 1;
			break;
		case 'h':
			i = flags->sh = 1;
			break;
	}

	return (i);
}

