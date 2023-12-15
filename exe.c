#include "monty.h"

/**
* exe - execute opcode
* @stack: stack of linked list
* @count: line counter
* @fd: pointer to monty file
*
* @content: line content
*
* Return: none
*/
int exe(char *content, stack_t **stack, unsigned int count, FILE *fd)
{
	instruction_t opst[] = {
				{"push", _push},
				{"pall", _pall}, 
				{"pint", _pint},
				{"pop", _pop},
				{"swap", _swap},
				{"add", _add},
				{"nop", _nop},
				{"sub", _sub},
				{"div", _div},
				{"mul", _mul},
				{"mod", _mod},
				{"pchar", _pchar},
				{"pstr", _pstr},
				{"rotl", _rotl},
				{"rotr", _rotr},
				{"queue", _queue},
				{"stack", _stack},
				{NULL, NULL}
				};
	unsigned int n;
	char *p;

	p = strtok(content, " \n\t");
	if (p && p[0] == '#')
		return (0);
	global.arg = strtok(NULL, " \n\t");
	for (n = 0; opst[n].opcode && p; n++)
	{
		if (strcmp(p, opst[n].opcode) == 0)
		{	opst[n].f(stack, count);
			return (0);
		}
	}
	if (p && opst[n].opcode == NULL)
	{ fprintf(stderr, "L%d: unknown instruction %s\n", count, p);
		fclose(fd);
		free(content);
		free_stack(*stack);
		exit(EXIT_FAILURE); }
	return (1);
}
