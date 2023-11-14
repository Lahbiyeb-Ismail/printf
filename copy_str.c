#include "main.h"

/**
 * copy_str - function to copy chars & make str
 * @c1: char
 * Return: pointer to str
 */

char *copy_str(char c1)
{
	char *str;

	str = malloc(sizeof(char) * 2);

	if (str == NULL)
		return (NULL);

	str[0] = c1;
	str[1] = '\0';

	return (str);
}
