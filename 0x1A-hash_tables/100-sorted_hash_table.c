#include "hash_tables.h"

/**
 * shash_table_create - creates a sorted hash table.
 * @size: number of array slots to make the table.
 *
 * Return: pointer to the hash table created, or NULL if malloc failed.
 */
shash_table_t *shash_table_create(unsigned long int size)
{
	shash_table_t *ht = malloc(sizeof(shash_table_t));

	if (ht == NULL)
		return (NULL);

	ht->size = size;
	ht->shead = NULL;
	ht->stail = NULL;
	ht->array = malloc(sizeof(shash_node_t *) * size);

	if (ht->array == NULL)
	{
		free(ht);
		return (NULL);
	}

	for (unsigned long int i = 0; i < size; i++)
		ht->array[i] = NULL;

	return (ht);
}

/**
 * shash_table_set - adds or updates an element to the sorted hash table.
 * @ht: pointer to the sorted hash table.
 * @key: the key, a string that cannot be empty.
 * @value: the value associated with the key, can be an empty string.
 *
 * Return: 1 on success, 0 on error.
 */
int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
	unsigned long int index;
	shash_node_t *node, *curr_old_node;

	if (key == NULL || ht == NULL)
		return (0);

	index = key_index((unsigned char *)key, ht->size);
	node = ht->array[index];

	if (node == NULL)
		node = set_spair_only(ht, key, value, index);
	else
	{
		while (node != NULL)
		{
			if (strcmp(node->key, key) == 0)
				return (update_value(node, value));
			node = node->next;
		}
		node = set_spair_front(ht, key, value, index);
	}

	if (node == NULL)
		return (0);

	if (ht->shead == NULL)
		return (slist_set_first(ht, node));

	curr_old_node = ht->shead;

	while (curr_old_node != NULL)
	{
		if (strcmp(curr_old_node->key, node->key) >= 0)
			return (slist_set(ht, curr_old_node, node));

		curr_old_node = curr_old_node->snext;
	}

	return (slist_set_end(ht, node));
}

/**
 * shash_table_lookup - retrieves a value associated with a key.
 * @ht: a pointer to the sorted hash table array.
 * @key: the key, a string that cannot be empty.
 *
 * Return: the value associated with the key, or NULL if key can't be found.
 */
void shash_table_lookup(const shash_table_t *ht, const char *key)
{
	if (ht == NULL || key == NULL)
		return;

	unsigned long int index = key_index((unsigned char *)key, ht->size);
	shash_node_t *node = ht->array[index];

	if (node == NULL)
	{
		printf("Key not found\n");
		return;
	}

	while (node != NULL)
	{
		if (strcmp(node->key, key) == 0)
		{
			printf("'%s': '%s'\n", node->key, node->value);
			return;
		}
		node = node->next;
	}

	printf("Key not found\n");
}

/**
 * shash_table_delete - deletes a sorted hash table
 * @ht: the sorted hash table.
 */
void shash_table_delete(shash_table_t *ht)
{
	unsigned long int i = 0;
	shash_node_t *node;

	while (i < ht->size)
	{
		while (ht->array[i] != NULL)
		{
			node = ht->array[i]->next;
			free(ht->array[i]->key);
			free(ht->array[i]->value);
			free(ht->array[i]);
			ht->array[i] = node;
		}
		i++;
	}

	free(ht->array);
	free(ht);
}
