#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

/**
 * struct formatter - A new struct type defining
 *	a formatter
 * @letter: A letter representing a format type
 * @func: A function pointer to a function that prints
 *	a format type corresponding to letter.
 *
 */
typedef struct formatter {
	char *letter;
	void (*func)(va_list arg);
} format_spec;

int _printf(const char *format, ...);
void (*conv(const char *symbol))(va_list arg);
void print_c(va_list arg);
void print_s(va_list arg);

#endif
