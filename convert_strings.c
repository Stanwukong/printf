#include "main.h"

/**
 * convert_s - Converts an argument to string and
 * stores it to a buffer contained in a struct
 *
 * @args: A va_list pointing to the argumen to be converted
 *
 * @flags: Flag modifiers
 *
 * @wid: A width modifier
 *
 * @prec: A precision modifier
 *
 * @len: A length modifier
 *
 * @output: Buffer_ struct containing a character array
 *
 * Return: Number of bytes stored to the buffer
 */

unsigned int convert_s(va_list args, buffer_t *output, unsigned char flags, int wid, int prec, unsigned char len)
{
	int size;
	char *str, *null = "(null)";
	unsigned int ret = 0;

	(void)flags;
	(void)len;

	str = va_arg(args, char *);
	if (str == NULL)
		return  (_memcpy(output, null, 6));
	for (size = 0; *(str + size);)
		size++;

	ret += print_string_width(output, flags, wid, prec, size);

	prec = (prec == -1) ? size : prec;
	while (*str != '\0' && prec > 0)
	{
		ret += _memcpy(output, str, 1);
		prec--;
		str++;

	}
	ret += print_neg_width(output, ret, flags, wid);
	return (ret);

}

/**
 * convert_s - Converts an argument to string and
 * stores it to a buffer contained in a struct
 *
 * @args: A va_list pointing to the argumen to be converted
 *
 * @flags: Flag modifiers
 *
 * @wid: A width modifier
 *
 * @prec: A precision modifier
 *
 * @len: A length modifier
 *
 * @output: Buffer_ struct containing a character array
 *
 * Return: Number of bytes stored to the buffer
*/

unsigned int convert_s(va_list args, buffer_t *output, unsigned char flags, int wid, int prec, unsigned char len)
{
	char *str, *null = "(null)", *hex = "\\x", zero = '0';
	unsigned int ret = 0;
	int size, index;

	(void)len;

	str = va_arg(args, char *);
	if (str == NULL)
		return (_memcpy(output, null, 6));

	for  (size = 0; str[size];)
		size++;
	ret += print_string_width(output, flags, wid, prec, size);

	prec = (prec == -1) ? size : prec;
	for (index = 0; *(str + index) != '\0' && index < prec; index++)
	{
		if (*(str + index) < 32 || *(str + index) >= 127)
		{
			ret += _memcpy(output, hex, 2);
			if (*(str + index) < 16)
				ret += _memcpy(output, &zero, 1);
			ret += convert_ubase(output, *(str + index), "0123456789ABCDEF", flags, 0, 0);
			continue;
		}
		ret += _memcpy(output, (str + index), 1);

	}
	ret += print_neg_width(output, ret, flags, wid);
	return (ret);
}

/**
 * convert_r - Reverses a string and stores it
 * to a buffer contained in a struct
 *
 * @args: A va_list pointing to the argumen to be converted
 *
 * @flags: Flag modifiers
 *
 * @wid: A width modifier
 *
 * @prec: A precision modifier
 *
 * @len: A length modifier
 *
 * @output: Buffer_ struct containing a character array
 *
 * Return: Number of bytes stored to the buffer
*/

unsigned int convert_r(va_list args, buffer_t *output, unsigned char flags, int wid, int prec, unsigned char len)
{
	int size, end, x;
	unsigned int ret = 0;
	char *str, *null = "(null)";

	(void)flags;
	(void)len;

	str = va_arg(args, char *);
	if (str == NULL)
		return (_memcpy(output, null, 6));
	for (size = 0; *(str + size);)
		size++;
	ret += print_string_width(output, flags, wid, prec, size);

	end = size - 1;
	prec = (prec == -1) ? size : prec;
	for (x = 0; end >= 0 && x < prec; x++)
	{
		ret += _memcpy(output, (str + end), 1);
		end--;
	}
	ret += print_neg_width(output, ret, flags, wid);
	return (ret);
}

/**
 * convert_R - converts a string to ROT13 and stores
 * it to a buffer contained in a struct
 *
 * @args: A va_list pointing to the argumen to be converted
 *
 * @flags: Flag modifiers
 *
 * @wid: A width modifier
 *
 * @prec: A precision modifier
 *
 * @len: A length modifier
 *
 * @output: Buffer_ struct containing a character array
 *
 * Return: Number of bytes stored to the buffer
*/

unsigned int convert_R(va_list args, buffer_t *output, unsigned char flags, int wid, int prec, unsigned char len)
{
	int x, y, size;
	unsigned int ret = 0;
	char *str, *null "(null)";
	char *alpha = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char *rot13 = "nopqrstuvwxyzabcdefghijklmNOPQRSTUVWXYZABCDEFGHIJKLM";

	(void)flags;
	(void)len;

	str = va_arg(args, char *);
	if (str == NULL)
		return (_memcpy(output, null, 6));
	for (size = 0; *(str + size);)
		size++;
	ret += print_string_width(output, flags, wid, prec, size);

	prec = (prec == -1) ? size : prec;
	for (x = 0; *(str + 1) != '\0' && x < prec; x++)
	{
		for (y = 0; y < 52; y++)
		{
			if (*(str + x) == *(alpha + y))
			{
				ret += _memcpy(output, (rot13 + y), 1);
				break;
			}
		}
		if (y == 52)
			ret += _memcpy(output, (str + x), 1);
	}
	ret += print_neg_width(output, ret, flags, wid);
	return (ret);
}
