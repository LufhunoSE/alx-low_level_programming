#include "lists.h"

/**
*add_nodeint_end - Adds a new node at the end of a listint_t list.
* @head: Pointer to a pointer to the head node.
* @n: Value to be added to the new node.
*
* Return: The address of the new element, or NULL if it failed.
*/
listint_t *add_nodeint_end(listint_t **head, const int n)
{
	listint_t *brandnew, *final;

	brandnew = malloc(sizeof(listint_t));
	if (brandnew == NULL)
		return (NULL);

	brandnew->n = n;
	brandnew->next = NULL;

	if (*head == NULL)
	{
		*head = brandnew;
		return (brandnew);
	}

	final = *head;
	while (final->next != NULL)
	final = final->next;

	final->next = brandnew;

	return (brandnew);
}
