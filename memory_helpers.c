#include "main.h"

void free_buffer(buffer_t *output);
unsigned int _memcpy(buffer_t *output, const char *src, unsigned int n);
buffer_t *init_buffer(void);

/**
 * free_buffer - Frees a buffer_t struct.
 *
 * @output: the buffer_t struct to be freed
 *
 */

void free_buffer(buffer_t *output)
{
	free(output->start);
	free(output);
}

/**
 * _memcpy - copies n bytes from memory area src to
 * the buffer contained in a buffer_t struct.
 *
 * @output: A buffer_t struct
 *
 * @src: Pointer to the memory area to copy
 *
 *@n: The number of bytes copied
 *
 * Return: The number of bytes copies
 */

unsigned int _memcpy(buffer_t *output, const char *src, unsigned int n)
{
	unsigned int index;

	for (index = 0; index < n; index++)
	{
		*(output->buffer) = *(src + index);
		(outpu->len)++;

		if (outpout->len == 1024)
		{
			write(1, output->start, output->len);
			output->buffer = output->start;
			output->len = 0;
		}
		else
			(output->buffer)++;
	}
	return (n);
}

/**
 * init_buffer - initializes a variable of struct type buffer_t
 *
 * Return: Pointer to the  initializes buffer_t
 */

buffer_t *init_buffer(void)
{
	buffer_t *output;

	output = malloc(sizeof(buffer_t));
	if (output == NULL)
		return (NULL);

	output->buffer = malloc(sizeof(char) * 1024);
	if (output->buffer  == NULL)
	{
		free(output);
		return (NULL);
	}
	output->start = output->buffer;
	output->len = 0;
	return (output);
}




