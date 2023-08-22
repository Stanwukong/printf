#include "main.h"

/**
 * handle_width - Width modifier with its corresponding value
 *
 * @args: A va_list of argumets
 *
 * @modifier: Pointer to a width modifier
 *
 * @index: An index counter for the format string
 *
 * Return: Always 0 (Success)
 */

int handle_width(va_list args, const char *modifier, char *index)
{
	int value = 0;

	while ((*modifier >= '0' && *modifier <= '9') || (*modifier == '*'))
	{
		(*index)++;
		if (*modifier == '*')
		{
			value = va_arg(args, int)
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
