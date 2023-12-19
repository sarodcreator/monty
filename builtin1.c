#include "monty.h"
/*
  * _pall - prints the stacks
  * @front: stack head
  * @count: no used
  * Return: no return
  */

void _pall (stack_t  **front, unsigned int count)
{
	stack_t  *f;
	
	count = count;
	f  = *front;
	
	if  (f != NULL)
	{
		while (f)
		{
			printf("%d\n", f->n);
			f = f->next;
		}
	}
	else
	{
		return;
	}
}

/**
 * _push - adds node to the stack
 * @front: double head pointer to the stack
 * @count: line count
 *
 * Return: nothing
 */

void _push(stack_t **front, unsigned int count)
{
	int d, n, flag;

	n = 0;
	flag = 0;

	if (!global.token)
	{
		fprintf(stderr, "L%d: usage : push integer\n", count);
		fclose (global.fd);
		free (global.content);
		free_stack(*front);
		exit(EXIT_FAILURE);
	}
	else
	{
		if (global.token[0] == '-')
			n++;
		for (; global.token[n] > 57 || global.token[n] <  48;)
			flag = 1;
		if (flag > 0 && flag < 2)
		{
				fprintf (stderr, "L%d: usage: Push integer\n", count);
				free (global.fd);
				free_stack(*front);
				exit(EXIT_FAILURE);
		}
	}
	d = atoi(global.token);
	
	if (global.token != 0)
	{
		addqueue(front, d);
	}
	else
	{
		addnode(front, d);
	}
}

/**
 * _pint - prints last node on stack
 * @front: pointer to pointer of first node
 * @count: line counter
 *
 * Return: none
 */
void _pint (stack_t **front, unsigned int count)
{
	if (*front == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", count);
		fclose(global.fd);
		free(global.content);
		free_stack(*front);
		exit (EXIT_FAILURE);
	}
	printf("%d\n", (*front)->n);
}

/**
 * _pop - removes top node on stack
 * @front: pointer to pointer of first node
 * @count: line counter
 *
 * Return: none
 */

void _pop(stack_t **front, unsigned int count)
{
	stack_t *f;
	if (*front == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", count);
		fclose(global.fd);
		free(global.content);
		free_stack(*front);
		exit(EXIT_FAILURE);
	}

	f = *front;
	*front = f->next;
	free(f);
}

/**
* _swap - swaps first two elements of stack
* @front: first node
* @count: line counter
*
* Return: none
*/

void _swap (stack_t **front, unsigned int count)
{
	stack_t *f;
	stack_t *new_node;
	
	int len = 0;
	int temp;

	f = *front;

	while(f)
	{
		f = f->next;
		len++;
	}
	if (len <=  1)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", count);
		fclose(global.fd);
		free(global.content);
		free_stack(*front);
		exit(EXIT_FAILURE);
	}
	f = *front;
	temp = f->n;
	new_node = f->next;
	f->n = new_node->n;
	new_node->n = temp;
}
