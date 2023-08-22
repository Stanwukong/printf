#include "main.h"

/**
 * _printf - Outputs a formatted string
 * @format: Character string to print.
 *
 * Return: Number of characters printed.
 */

int _printf(const char *format, ...)
{
	buffer_type *output;
	va_list args;
	int res;

	if (format == NULL)
	{
		return (-1);
	}

	output = init_buffer();

	if (output == NULL)
	{
		return (-1);
	}

	va_start(args, format);

	res = run_printf(format, args, output);

	return (res);	
}
