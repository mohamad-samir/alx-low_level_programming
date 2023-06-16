#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "../lists.h"
#include "../0-print_dlistint.c"
#include "../3-add_dnodeint_end.c"
#include "../4-free_dlistint.c"
#include "../5-get_dnodeint.c"
#include "../6-sum_dlistint.c"

/**
 * main - check the code
 *
 * Return: Always EXIT_SUCCESS.
 */
int main(void)
{
    dlistint_t *head;
    int sum;

    head = NULL;
    add_dnodeint_end(&head, 0);
    add_dnodeint_end(&head, 1);
    add_dnodeint_end(&head, 2);
    add_dnodeint_end(&head, 3);
    add_dnodeint_end(&head, 4);
    add_dnodeint_end(&head, 98);
    add_dnodeint_end(&head, 402);
    add_dnodeint_end(&head, 1024);
    sum = sum_dlistint(head);
    printf("sum = %d\n", sum);
    free_dlistint(head);
    head = NULL;
    return (EXIT_SUCCESS);
}