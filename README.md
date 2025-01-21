# Holberton School - printf Project

This project is about creating a simplified version of the `printf` function, which outputs formatted strings to the console. The function takes a format string and a variable number of arguments to print various types of data, such as characters, strings, and percentages.

## Requirements

- Allowed editors: vi, vim, emacs
- Compiler: gcc on Ubuntu 20.04 LTS with the following flags: `-Wall -Werror -Wextra -pedantic -std=gnu89`
- No global variables
- No more than 5 functions per file
- All header files must be include guarded
- Code should follow the Betty style

## Authorized functions and macros
- `write` (man 2 write)
- `malloc` (man 3 malloc)
- `free` (man 3 free)
- `va_start`, `va_end`, `va_copy`, `va_arg` (man 3 va_*)
  
## How to test
The main function provided in `main.c` can be used to test the implementation of the `_printf` function.

## Compilation
To compile your code, use:
```bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 -Wno-format *.c

