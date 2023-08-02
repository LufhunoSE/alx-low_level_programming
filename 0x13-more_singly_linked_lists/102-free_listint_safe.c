#include <stdlib.h>
#include "lists.h"

/**
 *free_listint_safe - Frees a listint_t list safely.
 *@h: Pointer to the pointer to the head of the list.
 *
 *Return: The size of the list that was freed.
 */
size_t free_listint_safe(listint_t **h)
{
	size_t include = 0;
	listint_t *now, *next;

	if (h == NULL || *h == NULL)
		return (0);

	now = *h;

	while (now != NULL)
	{
		next = now->next;

		now->next = NULL;

		free(now);

		include++;

		now = next;

		if (now == *h)
		{
			*h = NULL;
			break;
		}
	}

	return (include);
}
