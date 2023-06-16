#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * is_palindrome - Check if a string is a palindrome
 * @str: The string to check
 * Return: 1 if palindrome, 0 otherwise
 */
int is_palindrome(char *str)
{
    int i, len;

    len = strlen(str);
    for (i = 0; i < len / 2; i++)
    {
        if (str[i] != str[len - i - 1])
            return 0;
    }
    return 1;
}

int main(void)
{
    int largest_palindrome = 0;
    int factor1 = 0, factor2 = 0;

    for (int i = 100; i <= 999; i++)
    {
        for (int j = i; j <= 999; j++)
        {
            int product = i * j;
            char str[7];

            sprintf(str, "%d", product);

            if (is_palindrome(str) && product > largest_palindrome)
            {
                largest_palindrome = product;
                factor1 = i;
                factor2 = j;
            }
        }
    }

    // Write the largest palindrome to the file "102-result"
    FILE *file = fopen("102-result", "w");
    if (file != NULL)
    {
        fprintf(file, "%d", largest_palindrome);
        fclose(file);
    }

    return 0;
}
