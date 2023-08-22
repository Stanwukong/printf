#include "main.h"

/**
 * handle_specifiers - A conversion specifer with a correspnding
 * conversion functions
 *
 * @specifier: Pointer to a conversion specifiers
 *
 * Return: Always 0 otherwise NULL
 */

unsigned int (*handle_specifiers(const char *specifier))(va_list, buffer_t *, unsigned char, int, int, unsigned char)
{
	int x;
	convert_t converters[] = {
		{'c', convert_c},
		{'s', convert_s},
		{'d', convert_di},
		{'i', convert_di},
		{'%', convert_percent},
		{'b', convert_b},
		{'u', convert_u},
		{'o', convert_o},
		{'x', convert_x},
		{'s', convert_s},
		{'p', convert_p},
		{'r', convert_r},
		{'R', convert_R},
		{0, NULL}
	};

	for (x = 0; convertser[x].func; x++)
	{
		if (converters[x].specifier == *specifier)
			return (converters[x].func);
	}
	return (NULL);

}
