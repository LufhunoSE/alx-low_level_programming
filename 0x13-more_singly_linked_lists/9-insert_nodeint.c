#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lists.h"

/**
* insert_nodeint_at_index - Inserts a new node at a given position in a list.
 * @head: A pointer to the pointer to the head of the list.
 * @idx: The index where the new node should be inserted (starting from 0).
 * @n: The data value to be stored in the new node.
 *
 * Return: The address of the new node, or NULL if it failed.
 */
listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
	listint_t *brandnew, *interim;
	unsigned int l;

	if (head == NULL)
		return (NULL);
	
	brandnew = malloc(sizeof(listint_t));
	if (brandnew == NULL)
		return (NULL);

	brandnew->n = n;
	brandnew->next = NULL;

	if (idx == 0)
	{
		brandnew->next = *head;
		*head = brandnew;
		return (brandnew);
	}

	interim = *head;
	for (l = 0; l < idx - 1; l++)
	{
		if (interim == NULL)
		{
			free(brandnew);
			return (NULL);
		}
		interim = interim->next;
	}

	if (interim == NULL)
	{
		free(brandnew);
		return (NULL);
	}

	brandnew->next = interim->next;
	interim->next = brandnew;

	return (brandnew);
}
