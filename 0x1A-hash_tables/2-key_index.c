#include "hash_tables.h"

/**
 * key_index - gives the index of a key.
 * @key: the key, a string.
 * @size: the size of the array of the hash table.
 *
 * Return: Index number for the key/value pair in the hash table array.
 */
unsigned long int key_index(const unsigned char *key, unsigned long int size)
{
	unsigned long int hash_value;
	unsigned long int index;

	/* Compute the hash value using the hash_djb2 function */
	hash_value = hash_djb2(key);

	/* Calculate index by taking modulus of hash value with array size */
	index = hash_value % size;

	return (index);
}
