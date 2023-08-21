#include "main.h"

/**
 * conv - matches symbol with corresponding
 *	function
 * @letter: conversion specifier symbol to match
 *
 * Return: function pointer to function matched by letter
 */

void (*conv(const char *letter))(va_list arg)
{
	format_spec func[] = {
		{"c", print_c},
		{"s", print_s},
		{"d", print_d},
		{"i", print_i}
	};
	int i;

	for (i = 0; i < 4; i++)
	{
		if (*symbol == *(func[i].letter))
		{
			return (func[i].func);
		}
	}
	write(2, "Conversion specifier not found", 17);
	exit(1);
}
