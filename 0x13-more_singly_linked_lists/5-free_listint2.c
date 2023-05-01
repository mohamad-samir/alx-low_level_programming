#include "lists.h"

/**
 * free_listint2 - frees a linked list
 * @head: head of a list.
 *
 * Return: nothing.
 */

void free_listint2(listint_t **head)
{
	listint_t *temp;
	listint_t *current;

	if (head != NULL)
	{
		current = *head;
		temp = *head;
		while (current != NULL)
		{
			current = temp->next;
			free(temp);
			temp = current;
		}
		*head = NULL;
	}
}
