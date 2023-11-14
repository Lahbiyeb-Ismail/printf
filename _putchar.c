#include "main.h"

/**
 * _putchar - prints given character
 *
 * @c: character to print.
 *
 * * Description:
 * This function provides a buffered character output mechanism. It stores
 * characters in a static buffer until the buffer is full or until a special
 * character (-1) is encountered. When the buffer is full or the special
 * character is encountered, the contents of the buffer are written to the
 * standard output, and the buffer is reset. This helps reduce the number of
 * system calls to write individual characters to the output,
 * improving efficiency.
 *
 * Return: 1
 */

int _putchar(char c)
{
	static int i;
	static char buffer[BUFFER_SIZE];

	/* If c is not equal to -1, store it in the buffer*/
	if (c != -1)
		buffer[i++] = c;

	/* Check if c is -1 or buffer id full */
	if (c == -1 || i >= BUFFER_SIZE)
	{
		/* Write the buffer to the standard output */
		write(1, buffer, i);

		/* Reset the buffer index to 0 */
		i = 0;
	}

	return (1);
}
