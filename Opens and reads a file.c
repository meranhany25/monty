/**
 * Opens and reads a file containing instructions for manipulating a stack or queue.
 *
 * @param filename: The path to the file to be processed.
 * @param format: The storage format for the instructions.
 *         - 0: Nodes will be stored as a stack.
 *         - 1: Nodes will be stored as a queue.
 */
void process_file(char *filename, int format) {
    FILE *file = fopen(filename, "r");

    if (file == NULL) {
        handle_error(UNABLE_TO_OPEN_OR_READ_FILE, filename);
    }

    char buffer[BUFSIZ];
    int line_number = 1;

    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        if (buffer[0] == '#') { // Ignore comment lines
            continue;
        }

        parse_and_execute_line(buffer, line_number, format);
        line_number++;
    }

    fclose(file);
}

/**
 * Parses a line of instructions and executes the corresponding action.
 *
 * @param buffer: The line of instructions to be parsed.
 * @param line_number: The line number of the instruction.
 * @param format: The storage format for the instructions.
 *         - 0: Nodes will be stored as a stack.
 *         - 1: Nodes will be stored as a queue.
 */
void parse_and_execute_line(char *buffer, int line_number, int format) {
    char *opcode = strtok(buffer, " ");
    if (opcode == NULL) {
        return; // Empty line
    }

    char *value = strtok(NULL, " ");

    if (strcmp(opcode, "stack") == 0) {
        format = 0;
    } else if (strcmp(opcode, "queue") == 0) {
        format = 1;
    } else {
        execute_instruction(opcode, value, line_number, format);
    }
}

/**
 * Executes a specific instruction based on the provided opcode and value.
 *
 * @param opcode: The instruction code.
 * @param value: The argument for the instruction (if applicable).
 * @param line_number: The line number of the instruction.
 * @param format: The storage format for the instructions.
 *         - 0: Nodes will be stored as a stack.
 *         - 1: Nodes will be stored as a queue.
 */
void execute_instruction(char *opcode, char *value, int line_number, int format) {
    struct instruction_t function_list[] = {
        {"push", add_to_stack},
        {"pall", print_all},
        {"pint", print_top},
        {"pop", pop_top},
        {"nop", nop},
        {"swap", swap_nodes},
        {"add", add_nodes},
        {"sub", sub_nodes},
        {"div", div_nodes},
        {"mul", mul_nodes},
        {"mod", mod_nodes},
        {"pchar", print_char},
        {"pstr", print_string},
        {"rotl", rotate_left},
        {"rotr", rotate_right},
        {NULL, NULL}
    };

    struct instruction_t *func = NULL;
    for (int i = 0; function_list[i].opcode != NULL; i++) {
        if (strcmp(opcode, function_list[i].opcode) == 0) {
            func = &function_list[i];
            break;
        }
    }

    if (func == NULL) {
        handle_error(INVALID_INSTRUCTION, line_number, opcode);
    }

    func->f(&head, line_number, format, value);
}
