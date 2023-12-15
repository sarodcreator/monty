#include "monty.h"

/**
 * _mul - multiply first 2 elements in the stack
 * @front: pointer to pointer to first node
 * @count: line counter
 *
 * Return: none
 */

void _mul(stack_t **front, unsigned int count)
{
	stack_t *f, *new_node;
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
		fprintf(stderr, "L%d: can't mul, stack too short\n", count);
		fclose(global.fd);
		free(global.content);
		free_stack(*front);
		exit(EXIT_FAILURE);
	}
	new_node = (*f).next;
	temp = (*new_node).n / (*f).n;
	(*new_node).n = temp;
	*front = (*new_node).n;
	free(f);
}
