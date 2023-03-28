#include "main.h"
/**
 * print_rev - a function ptrint a string, in reverse, followed by a new line.
 * @s: the input string pointer.
 */
void print_rev(char *s)
{
	int length = _strlen(s);
	for (int i = length - 1; i >= 0; i--)
	{
		_putchar(s[i]);
	}
	_putchar("\n");
}
