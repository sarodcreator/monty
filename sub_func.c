#include "monty.h"

/**
 * _sub - subtract 2 elements of the stack
 * @front: pointer to pointer to first node
 * @count: line counter
 *
 * Return: none
 */

void _sub(stack_t **front, unsigned int count)
{
	stack_t *temp;
	stack_t *new_node;

	int sub, n;

	temp = *front;

	n = 0;
	while(temp != NULL)
	{
		n++;
		temp = temp->next;
	}
	if (n <= 1)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", count);
		fclose(global.fd);
		free(global.content);
		free_stack(*front);
		exit(EXIT_FAILURE);
	}
	temp = *front;
	new_node = temp->next;
	sub = new_node->n - temp->n;
	new_node->n = sub;
	*front = new_node;
	free(temp);
}
