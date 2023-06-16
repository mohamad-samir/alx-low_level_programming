#include "lists.h"

/**
 * delete_dnodeint_at_index - deletes a node at a specific index
 * @head: double pointer to the linked list
 * @index: index at which to delete node
 * Return: 1 on success, -1 on failure
 */

int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	if (head == NULL || *head == NULL)
		return (-1);

	dlistint_t *nodeToDelete = *head;

	if (index == 0)
	{
		*head = (*head)->next;
		if (*head)
			(*head)->prev = NULL;
		free(nodeToDelete);
		return (1);
	}

	for (unsigned int i = 0; i < index; i++)
	{
		if (nodeToDelete == NULL)
			return (-1);
		nodeToDelete = nodeToDelete->next;
	}

	if (nodeToDelete == NULL)
		return (-1);

	if (nodeToDelete->prev)
		nodeToDelete->prev->next = nodeToDelete->next;
	if (nodeToDelete->next)
		nodeToDelete->next->prev = nodeToDelete->prev;

	free(nodeToDelete);
	return (1);
}
