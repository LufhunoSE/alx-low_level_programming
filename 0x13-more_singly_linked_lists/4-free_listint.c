#include "lists.h"

/**
 * add_nodeint_end - Adds a new node at the end of a linked list.
 * @head: The pointer to the head of the list
 * @n: data to insert in the new element
 *
 * Return: pointer to the new node, or NULL if it fails
 */
listint_t *add_nodeint_end(listint_t **head, const int n)
{
	listint_t *now_node, *free_list;

	now_node = malloc(sizeof(listint_t));
	if (now_node == NULL)
		return (NULL);

	now_node->n = n;
	now_node->next = NULL;

	if (*head == NULL)
	{
		*head = now_node;
	}
	else
	{
		free_list = *head;
		while (free_list->next != NULL)
			free_list = free_list->next;

		free_list->next = now_node;
	}

	return (now_node);

}

