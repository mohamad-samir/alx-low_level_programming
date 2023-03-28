#include "main.h"
/**
 * print_rev - a function ptrint a string, in reverse, followed by a new line.
 * @s: the input string pointer.
 */
void print_rev(char *s)
{
	int i, j, len;

	i = 0;

	while (s[i] != '\0')
	{
		i++;
	}

	len = i;

	for (j = len; j >= 1; j--)
	{
		_putchar(s[j]);
	}

	_putchar('\n');
}

