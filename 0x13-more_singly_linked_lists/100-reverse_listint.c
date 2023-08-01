#include <stdio.h>
#include "lists.h"

/**
 *reverse_listint - Reverses a listint_t linked list.
 *@head: A pointer to the pointer of the head node.
 *
 *Return: A pointer to the first node of the reversed list.
 */
listint_t *reverse_listint(listint_t **head)
{
	listint_t *before = NULL;
	listint_t *now = *head;
	listint_t *next = NULL;

	while (now != NULL)
	{
		next = now->next;
		now->next = before;
		before = now;
		now = next;
	}

	*head = before;

	return (*head);
}
