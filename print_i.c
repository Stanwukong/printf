#include "main.h"

/**
 * print_i - Prints an integer
 * @arg: A va_list pointing to the integer to be printed.
 *
 */

void print_i(va_list arg)
{
	int i;

	i = va_arg(arg, int);

	print_number(i);
}
