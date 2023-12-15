#include "monty.h"

/**
 * _rotl - Rotate stack element to the top
 * @front: Pointer to the first node of the stack
 *
 * Return: None
 */
void _rotl(stack_t **front)
{
	stack_t *current, *new_front, *last;

	if (front == NULL || *front == NULL || (*front).next == NULL)
	{
		return;
	}

	current = *front;
	new_front = (*front).next;
	new_front.prev = NULL;

	while (current.next != NULL)
	{
		current = current.next;
	}

	current.next = *front;
	(*front).next = NULL;
	(*front).prev = &current;

	*front = &new_front;
}
