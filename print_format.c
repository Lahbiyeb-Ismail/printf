#include "main.h"

/**
 * _strcmp - string compare
 * @s1: pointer to str
 * @s2: pointer to str
 * Return: 1 if identical 0 if not
 */
int _strcmp(char *s1, char *s2)
{
	int i;

	for (i = 0; s1[i] && s2[i]; i++)
	{
		if (s1[i] == s2[i])
			continue;
		else
			return (0);
	}
	return (1);
}

/**
 * get_print_format - Entry point
 *
 *  * @spc: is a list of types of arguments passed to the function
 *
 * Description: Clone of the printf function
 *
 * Prototype: int print_format(char specifier, va_list args);
 *
 * Return: the total number of characters written is returned.
 *
 */

void (*get_print_format(char *spc))(int *char_len, va_list args, flags_t *f)
{
	print_t prints[] = {
			{"c", print_char},
			{"s", print_str},
			{"%", print_perc },
			{"i", print_dec },
			{"d", print_dec },
			{"b", print_bin },
			{"u", print_un },
			{"o", print_oct },
			{"x", print_hex },
			{"X", print_HEX },
			{"S", print_ascii },
			{NULL, NULL}
	};
	int i;

	i = 0;

	while (prints[i].specifier != NULL)
	{
		if (_strcmp(prints[i].specifier, spc))
			return (prints[i].print_func);

		i++;
	}

	return (NULL);
}
