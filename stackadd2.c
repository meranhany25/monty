#include "monty.h"

/**
 * nop - Does nothing.
 * @stack: Pointer to a pointer pointing to the top node of the stack.
 * @line_number: Integer representing the line number of the opcode.
 */
void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}

/**
 * swap_nodes - Swaps the top two elements of the stack.
 * @stack: Pointer to a pointer pointing to the top node of the stack.
 * @line_number: Integer representing the line number of the opcode.
 */
void swap_nodes(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if (stack == NULL || *stack == NULL || (*stack)->nextNode == NULL)
		more_err(8, line_number, "swap");

	tmp = (*stack)->nextNode;
	(*stack)->nextNode = tmp->nextNode;
	if (tmp->nextNode != NULL)
		tmp->nextNode->prevNode = *stack;
	tmp->nextNode = *stack;
	(*stack)->prevNode = tmp;
	tmp->prevNode = NULL;
	*stack = tmp;
}

/**
 * add_nodes - Adds the top two elements of the stack.
 * @stack: Pointer to a pointer pointing to the top node of the stack.
 * @line_number: Integer representing the line number of the opcode.
 */
void add_nodes(stack_t **stack, unsigned int line_number)
{
	int sum;

	if (stack == NULL || *stack == NULL || (*stack)->nextNode == NULL)
		more_err(8, line_number, "add");

	(*stack) = (*stack)->nextNode;
	sum = (*stack)->value + (*stack)->prevNode->value;
	(*stack)->value = sum;
	free((*stack)->prevNode);
	(*stack)->prevNode = NULL;
}

/**
 * sub_nodes - Subtracts the top two elements of the stack.
 * @stack: Pointer to a pointer pointing to the top node of the stack.
 * @line_number: Integer representing the line number of the opcode.
 */
void sub_nodes(stack_t **stack, unsigned int line_number)
{
	int difference;

	if (stack == NULL || *stack == NULL || (*stack)->nextNode == NULL)
		more_err(8, line_number, "sub");

	(*stack) = (*stack)->nextNode;
	difference = (*stack)->value - (*stack)->prevNode->value;
	(*stack)->value = difference;
	free((*stack)->prevNode);
	(*stack)->prevNode = NULL;
}

/**
 * div_nodes - Divides the top two elements of the stack.
 * @stack: Pointer to a pointer pointing to the top node of the stack.
 * @line_number: Integer representing the line number of the opcode.
 */
void div_nodes(stack_t **stack, unsigned int line_number)
{
	int quotient;

	if (stack == NULL || *stack == NULL || (*stack)->nextNode == NULL)
		more_err(8, line_number, "div");

	if ((*stack)->value == 0)
		more_err(9, line_number);

	(*stack) = (*stack)->nextNode;
	quotient = (*stack)->value / (*stack)->prevNode->value;
	(*stack)->value = quotient;
	free((*stack)->prevNode);
	(*stack)->prevNode = NULL;
}
