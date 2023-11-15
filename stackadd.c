#include "monty.h"

/**
 * add_to_stack - Adds a node to the stack.
 * @newNode: Pointer to the new node.
 * @ln: Line number of the opcode.
 */
void add_to_stack(stack_t **newNode, __attribute__((unused))unsigned int ln)
{
	stack_t *tmp;

	if (newNode == NULL || *newNode == NULL)
		exit(EXIT_FAILURE);
	if (*stack == NULL)
	{
		*stack = *newNode;
		return;
	}
	tmp = *stack;
	*stack = *newNode;
	(*stack)->nextNode = tmp;
	tmp->prevNode = *stack;
}

/**
 * print_stack - Prints the values of all nodes in the stack.
 * @stack: Pointer to a pointer pointing to the top node of the stack.
 * @lineNumber: Line number of the opcode.
 */
void print_stack(stack_t **stack, unsigned int lineNumber)
{
	stack_t *tmp;

	(void) lineNumber;
	if (stack == NULL)
		exit(EXIT_FAILURE);
	tmp = *stack;
	while (tmp != NULL)
	{
		printf("%d\n", tmp->value);
		tmp = tmp->nextNode;
	}
}

/**
 * pop_top - Removes the top node from the stack.
 * @stack: Pointer to a pointer pointing to the top node of the stack.
 * @lineNumber: Line number of the opcode.
 */
void pop_top(stack_t **stack, unsigned int lineNumber)
{
	stack_t *tmp;

	if (stack == NULL || *stack == NULL)
		more_err(7, lineNumber);

	tmp = *stack;
	*stack = tmp->nextNode;
	if (*stack != NULL)
		(*stack)->prevNode = NULL;
	free(tmp);
}

/**
 * print_top - Prints the value of the top node in the stack.
 * @stack: Pointer to a pointer pointing to the top node of the stack.
 * @lineNumber: Line number of the opcode.
 */
void print_top(stack_t **stack, unsigned int lineNumber)
{
	if (stack == NULL || *stack == NULL)
		more_err(6, lineNumber);
	printf("%d\n", (*stack)->value);
}
