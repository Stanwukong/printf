#include "main.h"

/**
 * print_c - Prints a character character
 * @arg: A va_list pointinig to the format to print.
 *
 * Return: Function pointer to function
 */

void print_c(va_list arg)
{
	char *chr_ptr;
	char chr;

	chr = va_arg(arg, int);
	chr_ptr = &chr;
	write(1, chr_ptr, 1);
}
