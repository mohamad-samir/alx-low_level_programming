#include "lists.h"

/**
 * get_dnodeint_at_index - returns the nth node of a dlistint_t linked list
 * @head: pointer to the head of the list
 * @index: index of the node, starting from 0
 *
 * Return: pointer to the nth node, or NULL if the node doesn't exist
 */
dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
	dlistint_t *current_node;
	unsigned int count;

	current_node = head;
	count = 0;

	while (current_node != NULL)
	{
		if (count == index)
		{
			return (current_node);
		}
		count++;
		current_node = current_node->next;
	}

	return (NULL);
}
