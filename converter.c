#include "main.h"

/**
 * conv - matches symbol with corresponding
 *	function
 * @symbol: conversion specifier symbol to match
 *
 * Return: function pointer to function matched by letter
 */

void (*conv(const char *symbol))(va_list arg)
{
	format_spec func[] = {
		{"c", print_c}
	};
	int i;

	for (i = 0; i < 4; i++)
	{
		if (*symbol == *(func[i].letter))
		{
			return (func[i].func);
		}
	}
	write(2, "Symbol not found", 17);
	exit(1);
}
