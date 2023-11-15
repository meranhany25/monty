/**
 * Adds a new node to the top of the stack.
 *
 * @param new_node_ptr: Pointer to the pointer to the new node.
 * @param line_number: The line number of the corresponding instruction.
 */
void push_to_stack(stack_node_t **new_node_ptr, int line_number) {
    if (new_node_ptr == NULL || *new_node_ptr == NULL) {
        handle_stack_error(STACK_UNDERFLOW, line_number);
    }

    stack_node_t *new_node = *new_node_ptr;
    stack_node_t *current_top = head;

    if (head == NULL) {
        head = new_node;
        return;
    }

    new_node->next = current_top;
    new_node->prev = NULL;
    current_top->prev = new_node;
    head = new_node;
}

/**
 * Prints all the values of the stack.
 *
 * @param stack_ptr: Pointer to the pointer to the head of the stack.
 * @param line_number: The line number of the corresponding instruction.
 */
void print_stack(stack_node_t **stack_ptr, int line_number) {
    (void) line_number;

    if (stack_ptr == NULL || *stack_ptr == NULL) {
        handle_stack_error(STACK_EMPTY, line_number);
    }

    stack_node_t *current_node = *stack_ptr;

    while (current_node != NULL) {
        printf("%d\n", current_node->value);
        current_node = current_node->next;
    }
}

/**
 * Removes and frees the top node of the stack.
 *
 * @param stack_ptr: Pointer to the pointer to the head of the stack.
 * @param line_number: The line number of the corresponding instruction.
 */
void pop_top_node(stack_node_t **stack_ptr, int line_number) {
    if (stack_ptr == NULL || *stack_ptr == NULL) {
        handle_stack_error(STACK_UNDERFLOW, line_number);
    }

    stack_node_t *current_top = *stack_ptr;
    head = current_top->next;

    if (head != NULL) {
        head->prev = NULL;
    }

    free(current_top);
    *stack_ptr = head;
}

/**
 * Prints the value of the top node of the stack.
 *
 * @param stack_ptr: Pointer to the pointer to the head of the stack.
 * @param line_number: The line number of the corresponding instruction.
 */
void print_top_value(stack_node_t **stack_ptr, int line_number) {
    if (stack_ptr == NULL || *stack_ptr == NULL) {
        handle_stack_error(STACK_EMPTY, line_number);
    }

    printf("%d\n", (*stack_ptr)->value);
}
