#include "main.h"

/**
 * print_binary - prints the binary representation of a number
 * @n: the number to print in binary form
 *
 * Return: void
 */
void print_binary(unsigned long int n)
{
	unsigned long int mask = 1;
	int i;

	/* Find the highest bit position that is set */
	while ((mask << 1) <= n)
		mask <<= 1;

	/* Print the binary digits from left to right */
	if (n == 0)
		_putchar('0');
	for (i = 0; mask > 0; mask >>= 1, i++)
	{
		if ((n & mask) == mask)
			_putchar('1');
		else
			_putchar('0');
	}
}
