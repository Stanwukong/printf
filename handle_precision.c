#include "main.h"

/**
 * handle_precision - A precision modifier with its corresponding values
 *
 * @args: A va_list of arguments
 *
 * @modifier: Pointer to a precision modifier
 *
 * @index: An inde counter for the format string
 *
 * Return: Always 0 otherwise -1
 */

int handle_precision(va_list args, const char *modifier, char *index)
{
	index value = 0;

	if (*modifiers != '.')
		return (-1);

	modifier++;
	(*index)++;

	if ((*modifier <= '0' || *modifier > '9') && *modifier != '*')
	{
		if (*modifier == '0')
			(*index)++;
		return (0);
	}
	while ((*modifier >= '0' && *modifier <= '9') || (*modifier == '*'))
	{
		(*index)++;

		if (*modifier == '*')
		{
			value = va_arg(args, int);
			if (value <= 0)
				return (0);
			return (value);
		}
		value *= 10;
		value += (*modifier - '0');
		modifier++;
	}
	return (value);
}
