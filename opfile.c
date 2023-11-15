#include "monty.h"

/**
 * open_file - Opens a file.
 * @file_path: The file path.
 * Return: void
 */

void open_file(char *file_path)
{
FILE *file_descriptor = fopen(file_path, "r");
if (file_path == NULL || file_descriptor == NULL)
err(2, file_path);
read_file(file_descriptor);
fclose(file_descriptor);
}

/**
 * read_file - Reads a file.
 * @file_d: Pointer to file descriptor.
 * Return: void
 */

void read_file(FILE *file_d)
{
int line_number, format = 0;
char *lbuffer = NULL;
size_t buf_len = 0;
for (line_number = 1; getline(&lbuffer, &buf_len, file_d) != -1; line_number++)
{
format = parse_line(line_buffer, line_number, format);
}
free(line_buffer);
}

/**
 * parse_line - Separates each line into tokens to determine
 * which function to call.
 * @buffer: Line from the file.
 * @line_number: Line number.
 * @format: Storage format. If 0 Nodes will be entered as a stack.
 * if 1 nodes will be entered as a queue.
 * Return: Returns 0 if the opcode is stack. 1 if queue.
 */

int parse_line(char *buffer, int line_number, int format)
{
char *opcode, *value;
const char *delim = "\n ";
if (buffer == NULL)
err(4);
opcode = strtok(buffer, delim);
if (opcode == NULL)
return (format);
value = strtok(NULL, delim);
if (strcmp(opcode, "stack") == 0)
return (0);
if (strcmp(opcode, "queue") == 0)
return (1);
find_operation(opcode, value, line_number, format);
return (format);
}

/**
 * find_operation - Finds the appropriate function for the opcode.
 * @opcode: Opcode.
 * @value: Argument of opcode.
 * @line_number: Line number.
 * @format: Storage format. If 0 Nodes will be entered as a stack.
 * if 1 nodes will be entered as a queue.
 * Return: void
 */
void find_operation(char *opcode, char *value, int line_number, int format)
{
int i;
int flag;
instruction_t operation_list[] = {
{"push", push_to_stack},
{"pall", print_stack},
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
{"pstr", print_str},
{"rotl", rotl},
{"rotr", rotr},
{NULL, NULL}
};
if (opcode[0] == '#')
return;
for (flag = 1, i = 0; operation_list[i].opcode != NULL; i++)
{
if (strcmp(opcode, operation_list[i].opcode) == 0)
{
call_operation(operation_list[i].f, opcode, value, line_number, format);
flag = 0;
}
}
if (flag == 1)
err(3, line_number, opcode);
}

/**
 * call_operation - Calls the required function.
 * @op_func: Pointer to the function that is about to be called.
 * @opc: String representing the opcode.
 * @val: String representing a numeric value.
 * @line_num: Line number for the instruction.
 * @format: Format specifier. If 0 Nodes will be entered as a stack.
 * if 1 nodes will be entered as a queue.
 */
void call_operation(op_func, char *opc, char *val, int line_num, int format)
{
stack_t *node;
int flag;
int i;
flag = 1;
if (strcmp(opcode, "push") == 0)
{
if (value != NULL && value[0] == '-')
{
value = value + 1;
flag = -1;
}
if (value == NULL)
err(5, line_number);
for (i = 0; value[i] != '\0'; i++)
{
if (isdigit(value[i]) == 0)
err(5, line_number);
}
node = create_node(atoi(value) * flag);
if (format == 0)
operation(&node, line_number);
if (format == 1)
add_to_queue(&node, line_number);
}
else
operation(&head, line_number);
}
