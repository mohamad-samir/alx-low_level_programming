#include "lists.h"
#include "2-add_dnodeint.c"
#include "3-add_dnodeint_end.c"

/**
 * insert_dnodeint_at_index - inserts a new node at a given position
 * @h: double pointer to the head of the list
 * @idx: index where the new node should be added, starting from 0
 * @n: data of the new node
 *
 * Return: the address of the new node, or NULL if it failed
 */
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
	dlistint_t *current_node, *new_node;
	unsigned int count;

	if (h == NULL)
	{
		return (NULL);
	}

	if (idx == 0)
	{
		return (add_dnodeint(h, n));
	}

	current_node = *h;
	count = 0;

	while (current_node != NULL)
	{
		if (count == idx)
		{
			new_node = malloc(sizeof(dlistint_t));
			if (new_node == NULL)
			{
				return (NULL);
			}

			new_node->n = n;
			new_node->prev = current_node->prev;
			new_node->next = current_node;
			current_node->prev->next = new_node;
			current_node->prev = new_node;

			return (new_node);
		}
		count++;
		current_node = current_node->next;
	}

	return (NULL);
}
