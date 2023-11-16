Monty Interpreter
The Monty Interpreter is a program that executes Monty byte code files. Monty is a simple, stack-based programming language.

Table of Contents
Usage
File Opening Error
Invalid Instruction Error
Memory Allocation Error
Running the Program
Compilation
Contributing
License
Usage
To use the Monty Interpreter, run the program with the following command:

bash
Copy code
monty file
Here, file is the path to the file containing Monty byte code.

If the user fails to provide a file or provides more than one argument, the program will display the following error message and exit with status EXIT_FAILURE:

bash
Copy code
USAGE: monty file
File Opening Error
If, for any reason, the program is unable to open the specified file, it will display an error message and exit with status EXIT_FAILURE. The error message will be in the following format:

bash
Copy code
Error: Can't open file <file>
Here, <file> is the name of the file that the program attempted to open.

Invalid Instruction Error
If the file contains an invalid instruction, the program will display an error message including the line number and the unknown opcode. It will then exit with status EXIT_FAILURE. The error message format is:

bash
Copy code
L<line_number>: unknown instruction <opcode>
Here, <line_number> is the line number where the invalid instruction appears, and <opcode> is the unknown instruction.

Memory Allocation Error
If the program is unable to allocate more memory using malloc, it will display the following error message and exit with status EXIT_FAILURE:

bash
Copy code
Error: malloc failed
Please note that the Monty program uses only malloc and free for memory allocation and deallocation, respectively.

Running the Program
The Monty program runs bytecodes line by line. It will stop execution under the following conditions:

It successfully executes every line in the file.
It encounters an error in the file.
A memory allocation error occurs.
Compilation
To compile the Monty Interpreter, use the provided Makefile. Simply run the following command:

bash
Copy code
make
This will generate the executable monty.

Contributing
If you would like to contribute to the Monty Interpreter, please follow our contribution guidelines
[MERAN HANY]
[AHMED RAMDAN]

License
This project is licensed under the MIT License.
