#include "main.h"

/**
 * cleanup - Peforms cleanup operations for _printf.
 * @args: A va_list of arguments provided to _printf.
 * @output: A buffer_type struct.
 */
void cleanup(va_list args, buffer_type *output)
{
	va_end(args);
	write(1, output->start, output->len);
	free_buffer(output);
}
