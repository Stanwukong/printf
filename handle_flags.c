#include "main.h"

/**
 * handle_flags - matches flags with corresponding values
 *
 * @flag: Pointer to a string of flags
 *
 * @index: An index counter for the original format string
 *
 * Return: Always 0 (Success)
 */

unsigned char handle_flags(const char *flag, char *index)
{
	unsigned char ret = 0;
	int x, y;
	flag_t flags[] = {
		{'+', PLUS},
		{' ', SPACE},
		{'#', HASH},
		{'0', ZERO},
		{'-', NEG},
		{0, 0}
	};

	for (x = 0; flag[x]; x++)
	{
		for (y = 0; flags[y].flag != 0; y++)
		{
			if (flag[x] == flags[y].flag)
			{
				(*index)++;
				if (ret == 0)
					ret = flags[y].value;
				else
					ret |= flags[y].value;
				break;
			}
		}
		if (flags[y].value == 0)
			break;
	}
	return (ret);
}
