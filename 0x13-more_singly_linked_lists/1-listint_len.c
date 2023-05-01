#include "lists.h"

/**
 * listint_len - prints a linked lists
 * @h: pointer to first node
 *
 * Return: counter of the size of the list
 */
size_t listint_len(const listint_t *h)
{
	size_t counter = 0;

	while (h)
	{
		h = h->next;
		counter++;
	}
	return (counter);
}
