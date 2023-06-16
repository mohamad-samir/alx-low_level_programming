#include "lists.h"

/**
 * delete_dnodeint_at_index - deletes a node at a specific index
 * @head: double pointer to the linked list
 * @index: index at which to delete node
 * Return: 1 on success, -1 on failure
 */

int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *current;
	unsigned int i;

	// Check if the head or the list is empty
	if (head == NULL || *head == NULL)
		return (-1);
		
	// Set the current pointer to the head of the list
	current = *head;
	
	// If the index is 0 (deleting the head node)
	if (index == 0)
	{
		// Update the head to the next node
		*head = current->next;
		
		// Update the previous pointer of the new head, if it exists
		if (current->next != NULL)
		{
			current->next->prev = NULL;
		}
		
		// Free the memory of the deleted node
		free(current);
		return (1);
	}
	
	// Traverse the list to the node at the specified index
	for (i = 0; i < index; i++)
	{
		// If we reach the end of the list before the desired index, return -1 indicating failure
		if (current->next == NULL)
			return (-1);
		
		// Move to the next node
		current = current->next;
	}
	
	// Update the next and previous pointers of the surrounding nodes to skip the node at the specified index
	current->prev->next = current->next;
	if (current->next != NULL)
		current->next->prev = current->prev;
		
	// Free the memory of the deleted node
	free(current);
	return (1);
}
