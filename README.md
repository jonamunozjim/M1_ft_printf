*This project has been created as part of the 42 curriculum by jmunoz-j.*

# ft_printf

## Description
The goal of this project is to reimplement the `printf()` function from the standard C library (libc). 

By rewriting this function, you gain a deep understanding of variadic functions in C (using a variable number of arguments). The key to a successful `ft_printf` is writing well-structured and extensible code. Unlike the original `printf()`, this custom implementation does not manage the buffer. The result is a static library (`libftprintf.a`) that can be used as a fundamental tool in future 42 projects.

## Instructions

### Prerequisites
To compile this project you will need:
- A C compiler (such as `gcc` or `clang`).
- The `make` utility.

### Compilation
1. Clone this repository to your local machine.
2. Navigate to the root of the repository.
3. Run the `make` command in your terminal.

This will compile the source files with `-Wall`, `-Wextra`, and `-Werror` flags, creating the static library `libftprintf.a`.

**Available Makefile commands:**
- `make` / `make all`: Compiles the static library `libftprintf.a`.
- `make clean`: Removes the object files (`.o`) generated during compilation.
- `make fclean`: Executes `clean` and also removes the compiled library file (`libftprintf.a

## Supported Conversions

| Specifier | Description |
|---|---|
| `%c` | Prints a single character. |
| `%s` | Prints a string (as defined by the common C convention). |
| `%p` | The `void *` pointer argument is printed in hexadecimal format. |
| `%d` | Prints a decimal (base 10) number. |
| `%i` | Prints an integer in base 10. |
| `%u` | Prints an unsigned decimal (base 10) number. |
| `%x` | Prints a number in hexadecimal (base 16) lowercase format. |
| `%X` | Prints a number in hexadecimal (base 16) uppercase format. |
| `%%` | Prints a literal percentage sign. |

## Algorithm and Data Structure
**Algorithm:**
The core algorithm is a single-pass string parser. It iterates through the format string character by character using a `while` loop. 
- When a standard character is encountered, it is printed directly to the standard output using the `write` function.
- When the `%` symbol is found, it acts as a trigger. The algorithm advances to the next character and uses a dispatch mechanism (a series of `if / else if` statements) to determine the requested format specifier.
- Based on the specifier, the algorithm extracts the corresponding variable using `va_arg` and routes it to specific helper functions (`ft_putstr`, `ft_putnbr_hex`, etc.) for formatting and printing.
- The total number of printed characters is continuously accumulated. If any `write` operation fails, the function catches the error (`if (n < 0)`) and immediately returns `-1`, matching the original `printf` behavior.

**Data Structure:**
To manage the variable number of arguments, the project relies exclusively on the `va_list` structure provided by the `<stdarg.h>` library (`va_start`, `va_arg`, `va_copy`, `va_end`). No internal buffering data structures (like arrays or dynamic strings) were used, strictly adhering to the project constraint of not managing the original `printf` buffer.

# Resources
## Documentation and References
- Operating system manual pages: `man 3 printf`, `man 3 stdarg`.
- GCC compiler documentation for function attributes like `__attribute__((format(printf, 1, 2)))`.

# Artificial Intelligence Usage
During the development of this project, AI was used as an educational support tool to:
- Translate and interpret error logs from tools like Valgrind regarding uninitialized bytes in the `write` function.
- Understand the strict argument extraction logic of `va_arg`.
- Discover and apply compiler validation attributes (`__attribute__`) to strictly check variadic arguments during compilation.

The AI was explicitly instructed not to provide solved code, but to limit itself to explaining the underlying logic and pointing out algorithmic flaws, ensuring that all project code was written and iterated autonomously.

