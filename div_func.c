#include "monty.h"

/**
 * _div - divide first 2 elements in the stack
 * @front: pointer to pointer to first node
 * @count: line counter
 *
 * Return: none
 */


void _div(stack_t **front, unsigned int count)
{
	stack_t *f;
	stack-t *new_node;
	int len, temp;

	f = *front;
	while (f)
	{
		f = (*f).next;
		len++;
	}
	if (len <= 1)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", count);
		fclose(global.fd);
		free(global.content);
		free_stack(*front);
		exit(EXIT_FAILURE);
	}
	f = *front;
	if ((*f).n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", count);
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
