#include "lists.h"

/**
 * insert_dnodeint_at_index - Inserts a node at a specific position in a
 * doubly linked list
 * @h: Pointer to a pointer to the head of the list
 * @n: The data value for the new node
 * @idx: The index at which the new node should be inserted
 * Return: Pointer to the new node on success, NULL on failure
 */
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
	dlistint_t *new_node, *current = *h;

	if (idx == 0) /* Insert at the beginning */
		return (add_dnodeint(h, n));

	/* Traverse to the node at position idx - 1 */
	while (idx > 1)
	{
		if (current == NULL)
			return (NULL);
		current = current->next;
		idx--;
	}

	if (current == NULL) /* Invalid position */
		return (NULL);

	if (current->next == NULL) /* Insert at the end */
		return (add_dnodeint_end(h, n));

	new_node = malloc(sizeof(dlistint_t));
	if (new_node == NULL)
		return (NULL);

	new_node->n = n;
	new_node->next = current->next;
	new_node->prev = current;
	current->next->prev = new_node;
	current->next = new_node;

	return (new_node);
}
