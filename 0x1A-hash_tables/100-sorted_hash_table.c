#include "hash_tables.h"

/**
 * djb2 - Hash function
 * @str: Input string
 * Return: Hash value
 */
unsigned long int djb2(const unsigned char *str)
{
	unsigned long int hash = 5381;
	int c;

	while ((c = *str++))
		hash = ((hash << 5) + hash) + c; /* hash * 33 + c */

	return hash;
}

/**
 * key_index - Get the index of a key
 * @key: Input key
 * @size: Size of the array
 * Return: Index of the key
 */
unsigned long int key_index(const unsigned char *key, unsigned long int size)
{
	unsigned long int idx;

	idx = djb2(key) % size;
	return (idx);
}

/**
 * shash_table_create - Create a sorted hash table
 * @size: Size of the array
 * Return: Pointer to the created hash table
 */
shash_table_t *shash_table_create(unsigned long int size)
{
	shash_table_t *ht;
	unsigned long int i;

	ht = malloc(sizeof(shash_table_t));
	if (ht == NULL)
		return (NULL);

	ht->size = size;
	ht->array = malloc(sizeof(shash_node_t *) * size);
	if (ht->array == NULL)
	{
		free(ht);
		return (NULL);
	}

	for (i = 0; i < size; i++)
		ht->array[i] = NULL;

	ht->shead = NULL;
	ht->stail = NULL;

	return (ht);
}

/**
 * shash_table_set - Insert a key-value pair into the sorted hash table
 * @ht: Pointer to the hash table
 * @key: Key to insert
 * @value: Value to insert
 * Return: 1 on success, 0 otherwise
 */
int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
	shash_node_t *new_node, *temp;
	unsigned long int idx;

	if (ht == NULL || key == NULL || value == NULL)
		return (0);

	idx = key_index((unsigned char *)key, ht->size);

	temp = ht->array[idx];
	while (temp != NULL)
	{
		if (strcmp(temp->key, key) == 0)
		{
			free(temp->value);
			temp->value = strdup(value);
			return (1);
		}
		temp = temp->next;
	}

	new_node = malloc(sizeof(shash_node_t));
	if (new_node == NULL)
		return (0);

	new_node->key = strdup(key);
	new_node->value = strdup(value);
	new_node->next = ht->array[idx];
	ht->array[idx] = new_node;

	if (ht->shead == NULL || strcmp(key, ht->shead->key) < 0)
	{
		new_node->sprev = NULL;
		new_node->snext = ht->shead;
		if (ht->shead != NULL)
			ht->shead->sprev = new_node;
		ht->shead = new_node;
		if (ht->stail == NULL)
			ht->stail = new_node;
	}
	else
	{
		temp = ht->shead;
		while (temp->snext != NULL && strcmp(key, temp->snext->key) >= 0)
			temp = temp->snext;
		new_node->sprev = temp;
		new_node->snext = temp->snext;
		if (temp->snext != NULL)
			temp->snext->sprev = new_node;
		temp->snext = new_node;
		if (new_node->snext == NULL)
			ht->stail = new_node;
	}

	return (1);
}

/**
 * shash_table_get - Retrieve the value associated with a key from the sorted hash table
 * @ht: Pointer to the hash table
 * @key: Key to search for
 * Return: Value associated with the key, or NULL if key not found
 */
char *shash_table_get(const shash_table_t *ht, const char *key)
{
	shash_node_t *temp;
	unsigned long int idx;

	if (ht == NULL || key == NULL)
		return (NULL);

	idx = key_index((unsigned char *)key, ht->size);

	temp = ht->array[idx];
	while (temp != NULL)
	{
		if (strcmp(temp->key, key) == 0)
			return (temp->value);
		temp = temp->next;
	}

	return (NULL);
}

/**
 * shash_table_print - Print the sorted hash table in ascending order
 * @ht: Pointer to the hash table
 */
void shash_table_print(const shash_table_t *ht)
{
	shash_node_t *temp;
	int flag = 0;

	if (ht == NULL)
		return;

	printf("{");
	for (temp = ht->shead; temp != NULL; temp = temp->snext)
	{
		if (flag == 1)
			printf(", ");
		printf("'%s': '%s'", temp->key, temp->value);
		flag = 1;
	}
	printf("}\n");
}

/**
 * shash_table_print_rev - Print the sorted hash table in reverse order
 * @ht: Pointer to the hash table
 */
void shash_table_print_rev(const shash_table_t *ht)
{
	shash_node_t *temp;
	int flag = 0;

	if (ht == NULL)
		return;

	printf("{");
	for (temp = ht->stail; temp != NULL; temp = temp->sprev)
	{
		if (flag == 1)
			printf(", ");
		printf("'%s': '%s'", temp->key, temp->value);
		flag = 1;
	}
	printf("}\n");
}

/**
 * shash_table_delete - Delete the sorted hash table
 * @ht: Pointer to the hash table
 */
void shash_table_delete(shash_table_t *ht)
{
	shash_node_t *temp, *next;
	unsigned long int i;

	if (ht == NULL)
		return;

	for (i = 0; i < ht->size; i++)
	{
		temp = ht->array[i];
		while (temp != NULL)
		{
			next = temp->next;
			free(temp->key);
			free(temp->value);
			free(temp);
			temp = next;
		}
	}

	free(ht->array);
	free(ht);
}