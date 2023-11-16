#include "monty.h"

/**
 * err - Prints appropriate error messages based on their error code.
 * @error_code: The error codes are the following:
 * (1) => The user does not provide a file or provides more than one
 * (2) => The provided file is not a file that can be opened or read.
 * (3) => The provided file contains an invalid instruction.
 * (4) => The program is unable to allocate more memory.
 * (5) => The parameter passed to the "push" instruction is not an integer.
 * (6) => The stack is empty when trying to print an integer.
 * (7) => The stack is empty when trying to pop an integer.
 * (8) => The stack is too short for the operation being performed.
 */
void err(int error_code, ...)
{
	va_list arg;
	char *opert;
	int l_number;

	va_start(arg, error_code);
	switch (error_code)
	{
		case 1:
			fprintf(stderr, "USAGE: monty file\n");
			break;
		case 2:
			fprintf(stderr, "Error: Can't open file %s\n",
				va_arg(arg, char *));
			break;
		case 3:
			l_number = va_arg(arg, int);
			opert = va_arg(arg, char *);
			fprintf(stderr, "L%d: unknown instruction %s\n", l_number, opert);
			break;
		case 4:
			fprintf(stderr, "Error: malloc failed\n");
			break;
		case 5:
			fprintf(stderr, "L%d: usage: push integer\n", va_arg(arg, int));
			break;
		default:
			break;
	}
	free_nodes();
	exit(EXIT_FAILURE);
}

/**
 * more_err - Handles more errors.
 * @error_code: The error codes are the following:
 * (6) => The stack is empty when trying to print an integer.
 * (7) => The stack is empty when trying to pop an integer.
 * (8) => The stack is too short for the operation being performed.
 * (9) => Division by zero.
 */
void more_err(int error_code, ...)
{
	va_list arg;
	char *opert;
	int l_number;

	va_start(arg, error_code);
	switch (error_code)
	{
		case 6:
			fprintf(stderr, "L%d: can't pint, stack empty\n",
				va_arg(arg, int));
			break;
		case 7:
			fprintf(stderr, "L%d: can't pop an empty stack\n",
				va_arg(arg, int));
			break;
		case 8:
			l_number = va_arg(arg, unsigned int);
			opert = va_arg(arg, char *);
			fprintf(stderr, "L%d: can't %s, stack too short\n", l_number, opert);
			break;
		case 9:
			fprintf(stderr, "L%d: division by zero\n",
				va_arg(arg, unsigned int));
			break;
		default:
			break;
	}
	free_nodes();
	exit(EXIT_FAILURE);
}

/**
 * string_err - handles errors in the string.
 * @error_code: The error codes are the following:
 * (10) => The value inside a node is outside the ASCII range.
 * (11) => The stack is empty.
 */
void string_err(int error_code, ...)
{
	va_list arg;
	int l_number;

	va_start(arg, error_code);
	l_number = va_arg(arg, int);
	switch (error_code)
	{
		case 10:
			fprintf(stderr, "L%d: can't pchar, value out of range\n", l_number);
			break;
		case 11:
			fprintf(stderr, "L%d: can't pchar, stack empty\n", l_number);
			break;
		default:
			break;
	}
	free_nodes();
	exit(EXIT_FAILURE);
}
