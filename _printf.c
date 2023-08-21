#include "main.h"

/**
 * _printf - Produces output according to a format.
 * @format: Character string composed of zero or
 *		more directives
 * @...: Variadic argument
 *
 * Return: Number of characters printed
 */

int _printf(const char *format, ...)
{
	int index;
	va_list args;

	va_start(args, format);

	for (index = 0; *(format + index) != '\0'; index++)
	{
		if (*(format + index) == '%')
		{
			conv(format + ++index)(args);
		}
		else
		{
			write(1, format + index, 1);
		}
	}
	return (index);
}
