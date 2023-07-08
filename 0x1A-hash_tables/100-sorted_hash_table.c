#include "hash_tables.h"

/**
 * check_input - Check if the input parameters are valid.
 * @ht: The hash table.
 * @key: The key.
 * @value: The value.
 *
 * Return: 1 if the input parameters are valid, 0 otherwise.
 */
int check_input(shash_table_t *ht, const char *key, const char *value)
{
	if (ht == NULL || key == NULL || value == NULL)
		return (0);
	return (1);
}

/**
 * create_new_node - Create a new node with the given key and value.
 * @key: The key.
 * @value: The value.
 *
 * Return: A pointer to the new node, or NULL if an error occurred.
 */
shash_node_t *create_new_node(const char *key, const char *value)
{
	shash_node_t *new_node = malloc(sizeof(shash_node_t));

	if (new_node == NULL)
		return (NULL);
	new_node->key = strdup(key);
	new_node->value = strdup(value);
	return (new_node);
}

/**
 * insert_new_node - Insert new node into the hash table at the given index.
 * @ht: The hash table.
 * @new_node: The new node.
 * @index: The index.
 */

void insert_new_node(shash_table_t *ht,
					 shash_node_t *new_node,
					 unsigned long int index)
{
	new_node->next = ht->array[index];
	ht->array[index] = new_node;
}

/**
 * update_shead - Update the shead pointer of the hash table with the new node.
 * @ht: The hash table.
 * @new_node: The new node.
 */
void update_shead(shash_table_t *ht, shash_node_t *new_node)
{
	new_node->sprev = NULL;
	new_node->snext = ht->shead;
	if (ht->shead != NULL)
		ht->shead->sprev = new_node;
	ht->shead = new_node;
}

/**
 * update_snext - Update the snext pointer of the temp node with the new node.
 * @temp: The temp node.
 * @new_node: The new node.
 */
void update_snext(shash_node_t *temp, shash_node_t *new_node)
{
	new_node->sprev = temp;
	new_node->snext = temp->snext;
	if (temp->snext != NULL)
		temp->snext->sprev = new_node;
	temp->snext = new_node;
}

/**
 * update_stail - Update the stail pointer of the hash table with the new node.
 * @ht: The hash table.
 * @new_node: The new node.
 */
void update_stail(shash_table_t *ht, shash_node_t *new_node)
{
	if (ht->stail == NULL || strcmp(ht->stail->key, new_node->key) < 0)
		ht->stail = new_node;
}

/**
 * shash_table_set - Set a key-value pair in the sorted hash table.
 * @ht: The hash table.
 * @key: The key.
 * @value: The value.
 *
 * Return: 1 if the key-value pair was set successfully, 0 otherwise.
 */
int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
	shash_node_t *new_node, *temp;
	unsigned long int index;

	if (!check_input(ht, key, value))
		return (0);

	index = key_index((const unsigned char *)key, ht->size);
	temp = ht->array[index];

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

	new_node = create_new_node(key, value);
	if (new_node == NULL)
		return (0);

	insert_new_node(ht, new_node, index);

	if (ht->shead == NULL || strcmp(ht->shead->key, key) > 0)
	{
		update_shead(ht, new_node);
	}
	else
	{
		temp = ht->shead;
		while (temp->snext != NULL && strcmp(temp->snext->key, key) < 0)
			temp = temp->snext;
		update_snext(temp, new_node);
	}

	update_stail(ht, new_node);
	return (1);
}
