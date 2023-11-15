#include "monty.h"
/**
 * multi_nodes - Multiplies the top 2 elements of the stack.
 * @stack: Pointer to a pointer pointing to the top node of the stack.
 * @lineNumber: Integer representing the line number of the opcode.
 */
void multi_nodes(stack_t **stack, unsigned int lineNumber)
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
 * mod_nodes - Computes the modulus of the top two elements of the stack.
 * @stack: Pointer to a pointer pointing to the top node of the stack.
 * @line_number: Integer representing the line number of the opcode.
 */
void mod_nodes(stack_t **stack, unsigned int line_number)
{
int remainder;
if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
more_err(8, line_number, "mod");
if ((*stack)->n == 0)
more_err(9, line_number);
(*stack) = (*stack)->next;
remainder = (*stack)->n % (*stack)->prev->n;
(*stack)->n = remainder;
free((*stack)->prev);
(*stack)->prev = NULL;
}
