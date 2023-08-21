#include "main.h"

int main(void)
{
    /* Test case 1: Printing a simple string */
    _printf("Hello, world!\n");

    /* Test case 2: Printing a string with a format specifier */
    _printf("The answer is %c\n", 'A');

    /* Test case 3: Printing multiple values with different format specifiers */
    _printf("Values: %d, %c, %s\n", 123, 'A', "Testing");

    return 0;
}
