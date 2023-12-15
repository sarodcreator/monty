#include "monty.h"

/**
 * _rotr - Rotates the stack to the bottom
 * @front: Pointer to the first node of the stack
 * @count: Number of elements to rotate (unused in this implementation)
 *
 * Return: None
 */

void _rotr(stack_t **front, __attribute__((unused)) unsigned int count)
{
	if (front == NULL || *front == NULL || (*front)->next == NULL)
	{
	    return;
	}

	stack_t *current = *front;
	stack_t *new_tail = *front;

	while (new_tail->next != NULL)
	{
		new_tail = new_tail->next;
	}

	new_tail->next = *front;
	(*front)->prev = new_tail;
	*front = (*front)->next;
	(*front)->prev = NULL;
}

