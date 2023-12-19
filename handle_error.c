#include "monty.h"
#define _GNU_SOURCE

global_var_t global = {NULL, NULL, NULL, 0};

/**
 * handle_error - Display an error message and perform cleanup before exit
 * @message: Error message to display
 * @fd: File to close (if open)
 * @content: Buffer to free (if allocated)
 * @stack: Stack to free
 */

void handle_error(const char *message, FILE *fd, char *content, stack_t *stack)
{
	fprintf(stderr, "Error: %s\n", message);

	if (fd != NULL)
		fclose(fd);

	if (content != NULL)
		free(content);

	free_stack(stack);
	exit(EXIT_FAILURE);
}
