#include "lists.h"

/**
 * listint_len - Returns the number of elements in a linked list.
 * @h: Pointer to the head of the linked list.
 *
 * Return: The number of elements in the linked list.
 */
size_t listint_len(const listint_t *h)
{
	size_t list_length = 0;

	while (h != NULL)
	{
		list_length++;
		h = h->next;
	}
	return (list_length);
}
