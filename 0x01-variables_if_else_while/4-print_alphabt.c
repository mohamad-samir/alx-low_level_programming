#include <stdio.h>

/**
  * main: program prints the alphabet in lowercase, followed by a new line.
  * Print all the letters except q and e
  * You can only use putchar twice
  * Return: 0
  */

int main(void)
{
	int lw = 'a';

		for (; lw <= 'z'; lw++)
		{
			if (lw == 'q' || lw == 'e')
			{
				lw++;
			}
			putchar(lw);
		}
		putchar('\n');
		return (0);
}
