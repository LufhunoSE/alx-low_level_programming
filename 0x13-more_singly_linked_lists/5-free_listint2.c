#include <stdlib.h>
#include "lists.h"

/**
 *free_listint2 - Frees a listint_t list and sets the head to NULL.
 *@head: Points to the head of the list.
 *
 *This function frees all the nodes of a linked list and sets the head pointer to NULL.
 */
void free_listint2(listint_t **head)
{
	listint_t *brandnew, *next;

	brandnew = *head;

	if (head == NULL)
		return;

	while (brandnew != NULL)
	{
		next = brandnew->next;
		free(brandnew);
		brandnew = next;
	}

	*head = NULL;
}
