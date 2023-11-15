**
 * Multiplies the values of the top two nodes of the stack.
 *
 * @param stack_ptr: Pointer to the pointer to the head of the stack.
 * @param line_number: The line number of the corresponding instruction.
 */
void multiply_nodes(stack_node_t **stack_ptr, int line_number) {
    if (stack_ptr == NULL || *stack_ptr == NULL || (*stack_ptr)->next == NULL) {
        handle_stack_error(STACK_TOO_SHORT, line_number, "mul");
    }

    stack_node_t *top_node = *stack_ptr;
    stack_node_t *second_node = (*stack_ptr)->next;

    int product = top_node->value * second_node->value;
    top_node->value = product;

    free(second_node);
    top_node->next = second_node->next;
    if (second_node->next != NULL) {
        second_node->next->prev = top_node;
    }

    *stack_ptr = top_node;
}

/**
 * Calculates the modulo of the values of the top two nodes of the stack.
 *
 * @param stack_ptr: Pointer to the pointer to the head of the stack.
 * @param line_number: The line number of the corresponding instruction.
 */
void modulo_nodes(stack_node_t **stack_ptr, int line_number) {
    if (stack_ptr == NULL || *stack_ptr == NULL || (*stack_ptr)->next == NULL) {
        handle_stack_error(STACK_TOO_SHORT, line_number, "mod");
    }

    stack_node_t *top_node = *stack_ptr;
    stack_node_t *second_node = (*stack_ptr)->next;

    if (second_node->value == 0) {
        handle_stack_error(DIVISION_BY_ZERO, line_number);
    }

    int remainder = top_node->value % second_node->value;
    top_node->value = remainder;

    free(second_node);
    top_node->next = second_node->next;
    if (second_node->next != NULL) {
        second_node->next->prev = top_node;
    }

    *stack_ptr = top_node;
}
