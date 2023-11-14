#include "main.h"

int print_hex_addr(unsigned long int num);

/**
 * print_address - Entry point
 *
 *  * @char_len: the total number of characters written
 *  * @args: int to print
 *  * @flags: void
 *
 * Description: Function that print the address memory
 *
 * Return: void
 *
 */

void print_address(int *char_len, va_list args, flags_t *flags)
{
	void *addr_pointer = va_arg(args, void *);
	unsigned long int address;
	char *s = "(nil)";
	int len = 0;
	(void)flags;

	if (!addr_pointer)
		for (; s[len]; len++)
			(*char_len) += _putchar(s[len]);
	else
	{
		address = (unsigned long int)addr_pointer;

		(*char_len) += _putchar('0');
		(*char_len) += _putchar('x');

		(*char_len) += print_hex_addr(address);
	}

	va_end(args);
}

/**
 * print_hex_addr - prints an hexadecimal number.
 *
 * @num: arguments.
 *
 * Return: char_len
 */

int print_hex_addr(unsigned long int num)
{
	long int i;
	long int *array;
	long int char_len = 0;
	unsigned long int temp = num;

	while (num / 16 != 0)
	{
		num /= 16;
		char_len++;
	}

	char_len++;
	array = malloc(char_len * sizeof(long int));

	for (i = 0; i < char_len; i++)
	{
		array[i] = temp % 16;
		temp /= 16;
	}

	for (i = char_len - 1; i >= 0; i--)
	{
		if (array[i] > 9)
			array[i] = array[i] + 39;
		_putchar(array[i] + '0');
	}

	free(array);
	return (char_len);
}
