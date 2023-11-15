#ifndef MONTY_H
#define MONTY_H

#define _GNU_SOURCE
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdarg.h>

/**
 * struct stack_s - Doubly linked list representation of a stack (or queue)
 * @value: Integer value of the node
 * @prevNode: Points to the previous element of the stack (or queue)
 * @nextNode: Points to the next element of the stack (or queue)
 *
 * Description: Doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
int value;
struct stack_s *prevNode;
struct stack_s *nextNode;
} stack_t;

/**
 * struct instruction_s - Opcode and its function
 * @opcode: The opcode
 * @f: Function to handle the opcode
 *
 * Description: Opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
char *opcode;
void (*f)(stack_t **stack, unsigned int lineNumber);
} instruction_t;

extern stack_t *stack;
typedef void (*op_func)(stack_t **, unsigned int);

/* File operations */
void open_file(char *file_path);
int parse_line(char *buffer, int line_number, int storage_format);
void read_file(FILE *file_descriptor);
int len_chars(FILE *file_descriptor);
void find_function(char *opcode, char *, int line_number, int storage_format);

/* Stack operations */
stack_t *create_node(int value);
void free_nodes(void);
void print_stack(stack_t **stack, unsigned int lineNumber);
void add_to_stack(stack_t **newNode, unsigned int lineNumber);
void add_to_queue(stack_t **newNode, unsigned int lineNumber);
void call_func(op_func func, char *, char *, int lineNumber, int format);
void print_top(stack_t **stack, unsigned int lineNumber);
void pop_top(stack_t **stack, unsigned int lineNumber);
void nop(stack_t **stack, unsigned int lineNumber);
void swap_nodes(stack_t **stack, unsigned int lineNumber);

/* Math operations with nodes */
void add_nodes(stack_t **stack, unsigned int lineNumber);
void sub_nodes(stack_t **stack, unsigned int lineNumber);
void div_nodes(stack_t **stack, unsigned int lineNumber);
void multi_nodes(stack_t **stack, unsigned int lineNumber);
void mod_nodes(stack_t **stack, unsigned int lineNumber);

/* String operations */
void print_char(stack_t **stack, unsigned int lineNumber);
void print_str(stack_t **stack, unsigned int lineNumber);
void rotl(stack_t **stack, unsigned int lineNumber);

/* Error handling */
void handleError(int errorCode, ...);
void handleMoreErrors(int errorCode, ...);
void handleStringError(int errorCode, ...);

#endif

