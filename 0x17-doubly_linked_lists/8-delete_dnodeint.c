#include "lists.h"

/**
 * delete_dnodeint_at_index - deletes a node at a specific index
 * @head: double pointer to the linked list
 * @index: index at which to delete node
 * Return: 1 on success, -1 on failure
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	if (*head == NULL)
		return (-1);

	if (index == 0)
	{
		dlistint_t *temp = *head;
		*head = (*head)->next;

		if (*head)
			(*head)->prev = NULL;

		free(temp);
		return (1);
	}

	dlistint_t *current = *head;
	unsigned int position = 0;

	while (current && position < index)
	{
		current = current->next;
		position++;
	}

	if (!current)
		return (-1);

	current->prev->next = current->next;

	if (current->next)
		current->next->prev = current->prev;

	free(current);
	return (1);
}
