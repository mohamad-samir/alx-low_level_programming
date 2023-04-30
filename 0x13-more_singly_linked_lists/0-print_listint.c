#include "lists.h"

/**
 * print_listint - prints a linked lists
 * @h: pointer to first node
 *
 * Return: counter of the size of the list
 */
size_t print_listint(const listint_t *h)
{
	size_t counter = 0;

	while (h!=NULL)
	{
		printf("%d\n", h->n);
		h = h->next;
		counter++;
	}
	return (counter);
}
