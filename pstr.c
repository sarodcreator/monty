#include "monty.h"

/**
 * _pstr - print string at the top of stack
 * @front: first node of linked list
 * @count: line counter
 *
 * Return: none
 */
void _pstr(stack_t **front, unsigned int count)
{
	stack_t *current;

	count = count; /*Unused parameter*/

	current = *front;
	while (current)
	{
		if (current->n >= 128 || current->n <= 0)
		{
			break;
		}

		putchar(current->n);
		current = current->next;
	}

	putchar('\n');
}
