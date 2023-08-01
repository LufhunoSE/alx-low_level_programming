#include "lists.h"

/**
 * add_nodeint_end - Adds a new node at the end of a linked list.
 * @head: The pointer to the head of the list
 * @n: data to insert in the new element
 *
 * Return: pointer to the new node, or NULL if it fails
 */
void free_listint(listint_t *head)
{
	listint_t *new_node, *free_listint;

	new_node = head;

	while (new_node != NULL)
	{
		free_listint = new_node;
		free(new_node);
		new_node = free_listint;
	}

}

