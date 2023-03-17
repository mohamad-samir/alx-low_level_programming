#include <stdio.h>
/**
  * main -  a program that prints all the numbers of base 16 in lowercase,
  * followed by a new line.
  * Return: 0
  */
int main(void)
{
	int i = 48;
	int j = 97;

	while (i <= 57)
	{
		putchar(i);
		i++;
	}
	if (j <= 102)
	{
		putchar(j);
		j++;
	}
	return (0);
}
