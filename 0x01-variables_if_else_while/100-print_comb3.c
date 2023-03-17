#include <stdio.h>
/**
  * main: a program prints all possible different combinations of two digits.
  * Return: 0
  */
int main(void)
{
	int i;
	int j;

	for (i = 48; i <= 57; i++)
	{
		putchar(i);
		for (j = 48; j <= 57; j++)
		{
			putchar(j);
			if (i == 48 && j == 57)
			{
				continue;
			}
			putchar(',');
			putchar(' ');
		}
	}
	return (0);
}
