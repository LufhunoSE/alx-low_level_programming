#include <stdlib.h>
#include "lists.h"

/**
 *delete_nodeint_at_index - Deletes the node at the given index of a listint_t linked list.
 *@head: Pointer to a pointer that points to the head of the linked list.
 *@index: The index of the node to be deleted. Index starts at 0.
 *
 *Return: 1 if deletion succeeded, -1 if it failed.
 */
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	listint_t *prev_node, *interim;
	unsigned int l;

	if (head == NULL || *head == NULL)
	{
		return -1;
	}

	if (index == 0)
	{
		interim = *head;
		*head = (*head)->next;
		free(interim);
		return 1;
	}

	prev_node = *head;
	l = 0;
	while (l < index - 1 && prev_node != NULL)
	{
		prev_node = prev_node->next;
		l++;
	}

	if (prev_node == NULL || prev_node->next == NULL)
	{
		return -1;
	}

	interim = prev_node->next;
	prev_node->next = interim->next;

	free(interim);

	return 1;
}
