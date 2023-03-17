#include <stdio.h>
/**
  * main: a program prints all possible different combinations of two digits.
  * Return: 0
  */
int main(void)
{
	int i;
	int j;

	for (i = 0; i <= 9; i++)
	{
		putchar(i);
		for (j = 0; j <= 9; j++)
		{
			putchar(j);
			if (i == 8 && j == 9)
			{
				continue;
			}
			putchar(',');
			putchar(' ');
		}
	}
	return (0);
}
