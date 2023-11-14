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
	flags_t flags = { 0, 0, 0 };
	void (*get_specifier)(int *, va_list, flags_t *);

	i = 0, char_len = 0;

	for (; format[i]; i++)
	{
		if (format[i] == '%')
		{
			if (format[i + 1] == ' ' && (format[i + 2] == '+'
				|| format[i + 2] == '#' || format[i + 2] == ' '))
				return (-1);

			specifier = handle_flags(format, &i, &flags);

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
 * * @i: Pointer to the current position in the format string
 * * @flags: Pointer to the flags struture
 *
 *
 * Description: Handles flags in the format specifier and retrieves
 * the specifier.
 *
 * Prototype: void _printf(const char *format, ...);
 *
 * Return: the total number of characters written is returned.
 *
 */

char *handle_flags(const char *format, int *i, flags_t *flags)
{
	char *specifier = NULL;

	switch (format[*i + 1])
	{
		case '+':
			flags->plus = 1;
			(*i)++;
			break;
		case ' ':
			flags->space = 1;
			(*i)++;
			break;
		case '#':
			flags->hash = 1;
			(*i)++;
			break;
	}

	specifier = copy_str(format[*i + 1]);
	return (specifier);
}

