#include "main.h"

/**
 * print_s - Prints a string.
 * @arg: A va_list pointing to
 *	the string to be printed.
 *
 */

void print_s(va_list arg)
{
	char *str;
	int index;

	str = va_arg(arg, char *);

	for (index = 0; str[index]; index++)
	{
		write(1, str, 1);
	}
}
