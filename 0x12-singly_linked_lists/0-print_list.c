#include <stdio.h>
#include "lists.h"
#include <stddef.h>
/**
 * Pribt list of all the elements of a list_t list.
 * If string is NULL, print [0] (nil)
 * Return: the number of nodes
 */
size_t print_list(const list_t *h);
{
	size_t L = 0;
	while (h != NULL)
	{	
	    if(h->str == NULL)
	{	printf("[0] (nil\n");
	}	
	  else 
  	{
		printf("[%zu] %s\n", L, h->str);
	}

	h= h->next;

	node_count++;
	}

	return (L);
}	

