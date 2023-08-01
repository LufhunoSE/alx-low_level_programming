#include <stdlib.h>
#include "lists.h"

/**
 * add_nodeint - Adds a new node at the beginning of a listint_t list.
 * @head: Pointer to the pointer of the first node in the list.
 * @n: The integer value to be stored in the new node.
 *
 * Description:
 * This function creates a new node with the given integer value and inserts it
 * at the beginning of a linked list of type listint_t. The head pointer is
 * updated to point to the newly added node, making it the 1st on the ist.
 *
 * Return:
 * The address of the (the newly added node) if the addition is successful,
 * or NULL if it fails due to head pointer being NULL or melloc error.
 */
listint_t *add_nodeint(listint_t **head, const int n)
{
	listint_t *another_node = (listint_t *)malloc(sizeof(listint_t));

	if (head == NULL)
	{
		return (NULL);
	}

	another_node->n = n;

	another_node->next = *head;

	*head = another_node;

	return (another_node);
}

