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

/**
 * flags_init - Entry point
 *
 * * @flags: Pointer to the flags struture
 *
 *
 * Description: function that reset all the values in the flags struct
 *
 *
 * Return: void
 *
 */

void flags_init(flags_t *flags)
{
	flags->plus = 0;
	flags->space = 0;
	flags->hash = 0;

	flags->lg = 0;
	flags->sh = 0;
}
