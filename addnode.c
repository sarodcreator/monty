#include "monty.h"

/**
 * add_node - Add a node to the top of the stack.
 * @front: Pointer to the first node.
 * @n: Value for the new node.
 *
 * Return: None.
 */
void addnode(stack_t **front, int n)
{
	stack_t *new;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		fprintf(stderr, "Error: Unable to allocate memory\n");
		exit(EXIT_FAILURE);
	}

	new->n = n;
	new->next = *front;
	new->prev = NULL;

	if (*front)
		(*front)->prev = new;

	*front = new;
}
