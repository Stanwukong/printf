#include "main.h"

/**
 * handle_length - matches lenth modifers with their corresponding values
 *
 * @modifier: Pointer to a length modifier
 *
 * @index: An index counter for the format string
 *
 * Return: Always 0 (Sucess)
 */

unsigned char handle_length(const char *modifier, char *index)
{
	if (*modifier == 'h')
	{
		(*index)++;
		return (SHORT);
	}
	else if (*modifier == 'l')
	{
		(*index)++;
		return (LONG);
	}
	return (0);
}
