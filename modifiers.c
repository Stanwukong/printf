#include "main.h"

/**
 * print_width - Stores leading spaces to a buffer for a width modifier
 *
 * @output: A buffer_t struct containing a charater array
 *
 * @printed: Number of characters already printed to output
 * for a given number
 *
 * @flags: Flag modifiers
 *
 * @wid: Width modifier
 *
 * Return: Number of bytes stored to the buffer
 */

unsigned int print_width(buffer_t *output, unsigned int printed, unsigned char flags, int wid)
{
	char width = ' ';
	unsigned int ret = 0;

	if (NEG_FLAG == 0)
	{
		for (wid -= printed; wid > 0;)
			ret += _memcpy(output, &width, 1);
	}
	return (ret);
}

/**
 * print_string_width - stores leading spaces to a buffer for a width modifier
 *
 * @output: A buffer_t struct containing a charater array
 *
 * @flags: Flag modifiers
 *
 * @wid: Width modifier
 *
 * @prec: A precision modifier
 *
 * @size: The size of the string
 *
 * Return: Number of bytes stored to the buffer
 */

unsigned int print_string_width(buffer_t *output, unsigned char flags, int wid, int prec, int size)
{
	char width = ' ';
	unsigned int ret = 0;

	if (NEG_FLAG == 0)
	{
		wid -= (prec == -1) ? size : prec;
		for (; wid > 0; wid--)
			ret += _memcpy(output, &width, 1);
	}
	return (ret);
}


/**
 * print_neg_width - stores trailing spaces to a buffer for a - flag
 *
 * @output: A buffer_t struct containing a charater array
 *
 * @printed: Number of characters already printed to output
 * for a given number
 *
 * @flags: Flag modifiers
 *
 * @wid: Width modifier
 *
 * Return: Number of bytes stored to the buffer
 */

unsigned int print_neg_width(buffer_t *output, unsigned int printed, unsigned char flags, int wid)
{
	unsigned int ret = 0;
	char width = ' ';

	if (NEG_FLAG == 1)
	{
		for (wid -= printed; wid > 0; wid--)
			ret += _memcpy(output, &width, 1);
	}
	return (ret);
}
