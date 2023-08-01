#include <stdlib.h>
#include "lists.h"

/**
 * sum_listint - Calculates the sum of all data elements (n) in a listint_t linked list.
 *
 * @head: A pointer to the head node of the linked list.
 *
 * Return: The sum of all data elements (n) of the linked list.
 *         If the linked list is empty, returns 0.
 */
int sum_listint(listint_t *head)
{
	int tally = 0;
	listint_t *now = head;

	while (now != NULL)
	{
		tally += now->n;
		now = now->next;
	}

	return tally;
}
