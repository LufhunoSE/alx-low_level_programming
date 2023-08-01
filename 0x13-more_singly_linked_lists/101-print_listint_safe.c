#include <stdlib.h>
#include <stdio.h>
#include "lists.h"

/**
 *print_listint_safe - Prints a listint_t linked list.
 *@head: A pointer to the head of the list.
 *
 *Return: The number of nodes in the list.
 */
size_t print_listint_safe(const listint_t *head)
{
	const listint_t *now;
	size_t include = 0;

	while (head)
	{
		now = head;
		head = head->next;
		include++;
		printf("[%p] %d\n", (void *)now, now->n);

		if (now <= head)
		{
			printf("-> [%p] %d\n", (void *)head, head->n);
			exit(98);
		}
	}

	return (include);
}
