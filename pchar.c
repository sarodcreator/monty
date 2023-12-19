#include "monty.h"

/**
 * _pchar - print the char at the top of stack
 * @front: stack head
 * @count: line number
 *
 * Return: none
 */

void _pchar(stack_t **front, unsigned int count)
{
	if (!front || !*front)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", count);
		fclose(global.fd);
		free(global.content);
		free_stack(*front);
		exit(EXIT_FAILURE);
	}

	if ((*front)->n < 0 || (*front)->n >= 128)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", count);
		fclose(global.fd);
		free(global.content);
		free_stack(*front);
		exit(EXIT_FAILURE);
	}

	printf("%c\n", (*front)->n);
}

