#include "monty.h"
col_t col = {NULL, NULL, NULL};
/**
* main - Entry point of the Monty interpreter
* @argc: Number of command-line arguments
* @argv: Array of command-line arguments
* Return: 0 on success, or EXIT_FAILURE on failure
*/
int main(int argc, char *argv[])
{
	stack_t *stack = NULL;
	FILE *file;
	char *line = NULL;
	size_t len = 0;
	ssize_t nread;
	unsigned int line_number = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	col.file = file;
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while ((nread = getline(&line, &len, file)) != -1)
	{
		line_number++;
		if (execute(line, line_number, &stack) == 0)
			continue;
	}
	free_stack(&stack);
	free(line);
	fclose(file);
	exit(EXIT_SUCCESS);
	return (0);
}
