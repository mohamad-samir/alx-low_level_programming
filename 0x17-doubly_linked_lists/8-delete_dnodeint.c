#include "lists.h"

/**
 * delete_dnodeint_at_index - deletes a node at a specific index
 * @head: double pointer to the linked list
 * @index: index at which to delete node
 * Return: 1 on success, -1 on failure
 */

int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *saved_head, *tmp;
	unsigned int p;

	if (*head == NULL)
		return (-1);

	saved_head = *head;

	if (index == 0)
	{
		*head = saved_head->next;

		if (saved_head->next != NULL)
			saved_head->next->prev = NULL;

		free(saved_head);
		return (1);
	}

	p = 0;
	tmp = *head;

	while (p < index)
	{
		if (tmp == NULL)
			return (-1);

		tmp = tmp->next;
		p++;
	}

	tmp->prev->next = tmp->next;
	if (tmp->next != NULL)
		tmp->next->prev = tmp->prev;

	free(tmp);
	return (1);
}
