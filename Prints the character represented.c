/**
 * Prints the character represented by the ASCII value at the top of the stack.
 *
 * @param stack_ptr: Pointer to the pointer to the head of the stack.
 * @param line_number: The line number of the corresponding instruction.
 */
void print_character(stack_node_t **stack_ptr, int line_number) {
    if (stack_ptr == NULL || *stack_ptr == NULL) {
        handle_stack_error(STACK_EMPTY, line_number);
    }

    int ascii_value = (*stack_ptr)->value;

    if (ascii_value < 0 || ascii_value > 127) {
        handle_stack_error(INVALID_ASCII_VALUE, line_number);
    }

    printf("%c\n", ascii_value);
}

/**
 * Prints the string represented by the values of the stack.
 *
 * @param stack_ptr: Pointer to the pointer to the head of the stack.
 * @param line_number: The line number of the corresponding instruction.
 */
void print_string(stack_node_t **stack_ptr, int line_number) {
    stack_node_t *current_node = *stack_ptr;

    while (current_node != NULL) {
        int ascii_value = current_node->value;

        if (ascii_value <= 0 || ascii_value > 127) {
            handle_stack_error(INVALID_ASCII_VALUE, line_number);
            break;
        }

        printf("%c", ascii_value);
        current_node = current_node->next;
    }

    printf("\n");
}

/**
 * Rotates the stack to the left, moving the top node to the bottom.
 *
 * @param stack_ptr: Pointer to the pointer to the head of the stack.
 * @param line_number: The line number of the corresponding instruction.
 */
void rotate_left(stack_node_t **stack_ptr, int line_number) {
    if (stack_ptr == NULL || *stack_ptr == NULL || (*stack_ptr)->next == NULL) {
        handle_stack_error(STACK_TOO_SHORT, line_number);
    }

    stack_node_t *top_node = *stack_ptr;
    stack_node_t *bottom_node = *stack_ptr;

    while (bottom_node->next != NULL) {
        bottom_node = bottom_node->next;
    }

    bottom_node->next = top_node;
    top_node->prev = bottom_node;
    top_node->next = NULL;
    bottom_node->prev = NULL;
    *stack_ptr = top_node;
}

/**
 * Rotates the stack to the right, moving the bottom node to the top.
 *
 * @param stack_ptr: Pointer to the pointer to the head of the stack.
 * @param line_number: The line number of the corresponding instruction.
 */
void rotate_right(stack_node_t **stack_ptr, int line_number) {
    if (stack_ptr == NULL || *stack_ptr == NULL || (*stack_ptr)->next == NULL) {
        handle_stack_error(STACK_TOO_SHORT, line_number);
    }

    stack_node_t *top_node = *stack_ptr;
    stack_node_t *bottom_node = *stack_ptr;

    while (bottom_node->next != NULL) {
        bottom_node = bottom_node->next;
    }

    top_node->prev = bottom_node;
    bottom_node->next = top_node;
    bottom_node->prev = NULL;
    top_node->next = NULL;
    *stack_ptr = bottom_node;
}
