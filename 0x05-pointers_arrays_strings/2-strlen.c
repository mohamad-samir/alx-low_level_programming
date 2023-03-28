#include "main.h"
/**
 * _strlen - Write a function that returns the length of a string.
 * @s: a null-terminated string input.
 * Return: the length of the string.
 */
int _strlen(char *s)
{
	int len = 0;

	while (*s != '\0')
	{
		len++;
		s++;
	}
	return (len);
}
