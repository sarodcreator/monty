#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <ctype.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */

typedef struct stack_s
{
       	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */

typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * global_var - struct with variable globals
 * @token: integer
 * fd: pointer to monty file
 * @content: line content
 * @lifo: flag change stack <-> queue
 *
 *Description: carries values through entire program
 */

typedef struct global_var
{
	char *token;
	FILE *fd;
	char *content;
	int lifo;
}   global_var_t;
extern global_var_t  global;

/**______builtin1.c______*/
void _pall (stack_t  **front, unsigned int count);
void _push(stack_t **front, unsigned int count);
void _pint (stack_t **front, unsigned int count);
void _pop(stack_t **front, unsigned int count);
void _swap (stack_t **front, unsigned int count);

/**______builtin2.c______*/
void _nop(stack_t **front, unsigned int count);

/**______add-func.c_____*/
void _add (stack_t **front, unsigned int count);

/**______sub_func.c______*/
void _sub(stack_t **front, unsigned int count);

/**______div-func.c______*/
void _div(stack_t **front, unsigned int count);

/**______mul-func.c______*/
void _mul(stack_t **front, unsigned int count);

/**______mod-func.c______*/
void _mod(stack_t **front, unsigned int count);

/**______pchar.c______*/
void _pchar(stack_t **front, unsigned int count);

/**______pstr.c______*/
void _pstr(stack_t **front, unsigned int count);

/**______rotr.c______*/
void _rotr(stack_t **front, __attribute__((unused)) unsigned int count);

/**______rotl.c______*/
void _rotl(stack_t **front, __attribute__((unused)) unsigned int count);

/**______struct.c______*/
void _stack(stack_t **front, unsigned int count);
void _queue(stack_t **head, unsigned int count);

/**____free_stack.c___*/
void free_stack(stack_t *front);

/**______add_queue.c______*/
void addqueue(stack_t **front, int n);

/**______add_node.c______*/
void addnode(stack_t **front, int n);

/**______exe.c______*/
int exe(char *content, stack_t **stack, unsigned int count, FILE *fd);

/**______handle_error.c______*/
void handle_error(const char *message, FILE *file, char *content, stack_t *stack);

ssize_t getline(char **lineptr, size_t *n, FILE *stream);

char *_realloc(char *ptr, unsigned int old_size, unsigned int new_size);
ssize_t getstdin(char **lineptr, int file);

char  *clean_line(char *content);
#endif
