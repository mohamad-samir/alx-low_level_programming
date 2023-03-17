#include <stdio.h>
/**
  * mian - Write a program that prints the alphabet in lowercase,
  * followed by a new line.
  * Return: 0
 */
int main(void)
{
	int i;

	for (i = 97; i <= 122; i++)
	{
		putchar(i);
	}
	putchar('\n');
	return (0);
}
