#include "monty.h"

/**
 * main - Monty code interpreter
 * @argc: Argument counter
 * @argv: Argument vector
 *
 * Return: Always 0
 */
int main(int argc, char *argv[])
{
	FILE *fd = NULL;
	char *content = NULL;
	size_t size = 0;
	ssize_t read_line = 1;
	stack_t *stack = NULL;
	unsigned int count = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	fd = fopen(argv[1], "r");
	global.fd = fd;

	if (!fd)
	{
		handle_error("Can't open file", fd, content, stack);
	}

	while (read_line > 0)
	{
		content = NULL;
		read_line = getline(&content, &size, fd);
		global.content = content;
		count++;

		if (read_line > 0 && exe(content, &stack, count, fd) == EXIT_FAILURE)
		{
			handle_error("Execute error", fd, content, stack);
		}

		free(content);
	}

	if (fclose(fd) == EOF)
	{
		handle_error("Error closing file", NULL, NULL, stack);
	}

	free_stack(stack);
	return 0;
}
