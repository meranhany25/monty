#include "monty.h"
/**
 * mul_nodes -  the top two elements of the stack.
 * @stack: A pointer to a pointer to the top node of the stack.
 * @line_number: The line number of the opcode.
 */
void mul_nodes(stack_t **stack, unsigned int line_number)
{
	int product;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		more_err(8, line_number, "mul");

	(*stack) = (*stack)->next;
	product = (*stack)->n * (*stack)->prev->n;
	(*stack)->n = product;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}


/**
 * mod_nodes - Adds the top two elements of the stack.
 * @stack: A pointer to a pointer to the top node of the stack.
 * @line_number: The line number of the opcode.
 */
void mod_nodes(stack_t **stack, unsigned int line_number)
{
	int reminder;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)

		more_err(8, line_number, "mod");


	if ((*stack)->n == 0)
		more_err(9, line_number);
	(*stack) = (*stack)->next;
	reminder = (*stack)->n % (*stack)->prev->n;
	(*stack)->n = reminder;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
