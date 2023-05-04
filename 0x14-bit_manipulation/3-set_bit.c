#include "main.h"

/**
 * set_bit - sets the value of a bit to 1 at a given index
 * @n: pointer to the unsigned long int to modify
 * @index: index of the bit to set
 *
 * Return: 1 if it worked, or -1 if an error occurred
 */

int set_bit(unsigned long int *n, unsigned int index)
{
	/* check if index is valid */
	if (index >= (sizeof(unsigned long int) * 8))
		return (-1);

	/* set the bit at index to 1 */
	*n |= (1ul << index);

	return (1);
}

