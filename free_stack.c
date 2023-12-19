#include "monty.h"

/**
 * free_stack - frees doubly linked list
 * @front: pointer to the first node of the stack
 * Return: none
 */

void free_stack(stack_t *front)
{
	stack_t *current, *next_node;
	current = front;
	while (current != NULL)
	{
		next_node = current->next;
		free(current);
		current = next_node; 
	}

	front = NULL;
}
