#include "main.h"

/**
 * _putchar - prints given character
 * @c: character to print.
 *
 * Return: number of characters printed, -1 if error
 */

int _putchar(char c)
{
	return (write(1, &c, 1));
}
