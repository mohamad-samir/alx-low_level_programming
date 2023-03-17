#include <stdio.h>

/**
 * main - program that prints the alphabet in lowercase, followed by a new line
 * You can only use the putchar
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
