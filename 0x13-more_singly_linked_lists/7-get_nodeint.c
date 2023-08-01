#include "lists.h"

/**
 *get_nodeint_at_index - Returns the nth node of a listint_t linked list.
 *@head: Pointer to the head node of the list.
 *@index: Index of the node to be returned, starting at 0.
 *
 *Return: If the node does not exist, returns NULL.
 *         Otherwise, returns a pointer to the nth node.
 */
listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
	unsigned int get_node = 0;
	listint_t *now = head;

	while (now != NULL)
	{
		if (get_node == index)
			return now;
		
		now = now->next;
		get_node++;
	}

	return NULL;
}
