#include "monty.h"

/**
 * addqueue - add node to tail of queue
 * @front: head of the queue
 * @n: new value
 *
 * Return: none
 */


void addqueue(stack_t **front, int n)
{
	stack_t *new, *temp;

	new = malloc(sizeof(stack_t));

	if (new == NULL)
	{
		fprintf(stderr, "Error: Unable to allocate memory\n");
		exit(EXIT_FAILURE);
	}

	new->n = n;
	new->next = NULL;

	temp = *front;

	if (temp)
	{
		while (temp->next)
		{
			temp = temp->next;
		}
		temp->next = new;
		new->prev = temp;
	}
	else
	{
		*front = new;
		new->prev = NULL;
	}
}
