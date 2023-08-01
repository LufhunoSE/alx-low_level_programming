#include <stdlib.h>
#include "lists.h"

/**
 * pop_listint - Deletes the head node of a listint_t linked list.
 * @head: A pointer to a pointer to the head node of the list.
 *
 * Return: The data (n) stored in the head node, or 0 if the list is empty.
 */
int pop_listint(listint_t **head)
{
	listint_t *pointer = *head;
	int data = pointer->n;

	*head = (*head)->next;
	free(pointer);

	return data;
}
