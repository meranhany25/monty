/**
 * Handles various error conditions that occur during program execution.
 *
 * @param error_type: Represents the type of error encountered.
 *         Error types include:
 *         - 1: Insufficient or excessive file arguments.
 *         - 2: Unable to open or read the specified file.
 *         - 3: Invalid instruction encountered in the file.
 *         - 4: Memory allocation failure.
 *         - 5: Invalid format for the "push" instruction.
 * @param ...: Variable arguments to provide additional context for specific errors.
 */
void handle_error(error_type_t error_type, ...)
{
    va_list argument_list;
    char *opcode;
    int line_number;

    va_start(argument_list, error_type);

    switch (error_type) {
        case INSUFFICIENT_OR_EXCESSIVE_FILE_ARGUMENTS:
            fprintf(stderr, "USAGE: monty <filename>\n");
            break;
        case UNABLE_TO_OPEN_OR_READ_FILE:
            opcode = va_arg(argument_list, char *);
            fprintf(stderr, "Error: Cannot open file '%s'\n", opcode);
            break;
        case INVALID_INSTRUCTION:
            line_number = va_arg(argument_list, int);
            opcode = va_arg(argument_list, char *);
            fprintf(stderr, "L%d: Unknown instruction '%s'\n", line_number, opcode);
            break;
        case MEMORY_ALLOCATION_FAILURE:
            fprintf(stderr, "Error: Memory allocation failed\n");
            break;
        case INVALID_FORMAT_FOR_PUSH_INSTRUCTION:
            line_number = va_arg(argument_list, int);
            fprintf(stderr, "L%d: Usage: push <integer>\n", line_number);
            break;
        default:
            break;
    }

    free_nodes();
    exit(EXIT_FAILURE);
}

/**
 * Handles stack-related errors.
 *
 * @param error_type: Represents the type of stack-related error encountered.
 *         Error types include:
 *         - 1: Stack underflow.
 *         - 2: Stack overflow.
 * @param ...: Variable arguments to provide additional context for specific errors.
 */
void handle_stack_error(error_type_t error_type, ...)
{
    va_list argument_list;
    int line_number;

    va_start(argument_list, error_type);

    switch (error_type) {
        case STACK_UNDERFLOW:
            line_number = va_arg(argument_list, int);
            fprintf(stderr, "L%d: Stack underflow\n", line_number);
            break;
        case STACK_OVERFLOW:
            line_number = va_arg(argument_list, int);
            fprintf(stderr, "L%d: Stack overflow\n", line_number);
            break;
        default:
            break;
    }

    free_nodes();
    exit(EXIT_FAILURE);
}

/**
 * Handles errors related to string operations.
 *
 * @param error_type: Represents the type of string-related error encountered.
 *         Error types include:
 *         - 1: The number inside a node is outside ASCII bounds.
 *         - 2: The stack is empty.
 * @param ...: Variable arguments to provide additional context for specific errors.
 */
void handle_string_error(error_type_t error_type, ...)
{
    va_list argument_list;
    int line_number;

    va_start(argument_list, error_type);

    switch (error_type) {
        case NON_ASCII_VALUE:
            line_number = va_arg(argument_list, int);
            fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
            break;
        case EMPTY_STACK_FOR_PCHAR:
            line_number = va_arg(argument_list, int);
            fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
            break;
        default:
            break;
