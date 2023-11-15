/**
 * Performs no operation and does nothing.
 *
 * @param stack_ptr: Pointer to the pointer to the head of the stack.
 * @param line_number: The line number of the corresponding instruction.
 */
void do_nothing(stack_node_t **stack_ptr, int line_number) {
    (void) stack_ptr;
    (void) line_number;
}

/**
 * Swaps the values of the top two nodes of the stack.
 *
 * @param stack_ptr: Pointer to the pointer to the head of the stack.
 * @param line_number: The line number of the corresponding instruction.
 */
void swap_nodes(stack_node_t **stack_ptr, int line_number) {
    if (stack_ptr == NULL || *stack_ptr == NULL || (*stack_ptr)->next == NULL) {
        handle_stack_error(STACK_TOO_SHORT, line_number, "swap");
    }

    stack_node_t *top_node = *stack_ptr;
    stack_node_t *second_node = (*stack_ptr)->next;

    top_node->next = second_node->next;
    if (second_node->next != NULL) {
        second_node->next->prev = top_node;
    }

    second_node->next = top_node;
    top_node->prev = second_node;
    second_node->prev = NULL;
    *stack_ptr = second_node;
}

/**
 * Adds the values of the top two nodes of the stack.
 *
 * @param stack_ptr: Pointer to the pointer to the head of the stack.
 * @param line_number: The line number of the corresponding instruction.
 */
void add_nodes(stack_node_t **stack_ptr, int line_number) {
    if (stack_ptr == NULL || *stack_ptr == NULL || (*stack_ptr)->next == NULL) {
        handle_stack_error(STACK_TOO_SHORT, line_number, "add");
    }

    stack_node_t *top_node = *stack_ptr;
    stack_node_t *second_node = (*stack_ptr)->next;

    int sum = top_node->value + second_node->value;
    top_node->value = sum;

    free(second_node);
    top_node->next = second_node->next;
    if (second_node->next != NULL) {
        second_node->next->prev = top_node;
    }

    *stack_ptr = top_node;
}

/**
 * Subtracts the value of the second node from the value of the top node of the stack.
 *
 * @param stack_ptr: Pointer to the pointer to the head of the stack.
 * @param line_number: The line number of the corresponding instruction.
 */
void sub_nodes(stack_node_t **stack_ptr, int line_number) {
    if (stack_ptr == NULL || *stack_ptr == NULL || (*stack_ptr)->next == NULL) {
        handle_stack_error(STACK_TOO_SHORT, line_number, "sub");
    }

    stack_node_t *top_node = *stack_ptr;
    stack_node_t *second_node = (*stack_ptr)->next;

    int difference = top_node->value - second_node->value;
    top_node->value = difference;

    free(second_node);
    top_node->next = second_node->next;
    if (second)
