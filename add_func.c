#include "monty.h"

/**
 * _add - add first 2 elements of the stack
 * @front: pointer to pointer to first node
 * @count: line counter
 *
 * Return: none
 */

void _add (stack_t **front, unsigned int count)
{
	stack_t *f;
	int len, temp;

	f = *front;
	len = 0;
	while (f)
	{
		f = (*f).next;
		len++;
	}
	if (len <= 1)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", count);
		fclose(global.fd);
		free(global.content);
		free_stack(*front);
		exit(EXIT_FAILURE);
	}
	f = *front
	temp = (*f).n + (*f).next.n;
	(*f).next.n = temp
	*front = (*f).next;
	free(f);
}
