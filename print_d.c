#include "main.h"

/**
 * print_d - Prints an integer.
 * @arg: A va_list pointingto the integer
 *	to be printed.
 *
 */

void print_d(va_list arg)
{
	int d;

	d = va_arg(arg, int);

	print_number(d);
}
