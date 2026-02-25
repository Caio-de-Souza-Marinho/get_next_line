# get_next_line

*This project has been created as part of the 42 curriculum by
caide-so.*

## Description

**get_next_line** is a foundational systems programming project at 42
School focused on file descriptors, static storage duration, and
low-level input handling in C.

The objective is to implement a function:

``` c
char *get_next_line(int fd);
```

that reads from a file descriptor and returns one line per call,
including the terminating newline (`\n`) when present.

Rather than loading an entire file into memory, this project enforces
incremental reading using `read()`, managing partial buffers, and
preserving state between function calls through the use of a static
variable.

This project reinforces core C concepts:

-   File descriptor management
-   Static storage duration
-   Dynamic memory allocation
-   Buffer control
-   Edge case handling
-   Defensive programming under strict constraints

It also requires strict compliance with the 42 Norm.

------------------------------------------------------------------------

## Why This Project Matters

### Stateful Function Design

You learn how to design a function that maintains internal state across
multiple calls without using global variables.

### Low-Level I/O Mastery

Working directly with `read()` builds understanding of how Unix-like
systems handle file input.

### Memory Discipline

Every allocation must be tracked and freed properly. Memory leaks or
undefined behavior result in failure.

### Algorithmic Thinking

The challenge is not reading a file --- it is reading just enough to
return exactly one line at a time.

This project marks the transition from simple procedural programming to
controlled state management and system-level thinking.

------------------------------------------------------------------------

## Project Structure

    get_next_line/
    ├── get_next_line.c
    ├── get_next_line_utils.c
    ├── get_next_line.h
    ├── get_next_line_bonus.c
    ├── get_next_line_utils_bonus.c
    ├── get_next_line_bonus.h
    └── Makefile

------------------------------------------------------------------------

## Mandatory Requirements

-   Repeated calls must return one line at a time
-   Returned lines must include `\n` when present
-   Return `NULL` on EOF or error
-   Must work with files and standard input
-   No use of `libft`
-   No use of `lseek()`
-   No global variables
-   Only allowed external functions:
    -   `read`
    -   `malloc`
    -   `free`

The function must compile with and without the `-D BUFFER_SIZE=n` flag.

Example:

``` bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c
```

The implementation must behave correctly for any valid `BUFFER_SIZE`,
including extreme values such as:

-   1
-   42
-   4096
-   9999

------------------------------------------------------------------------

## Algorithm Explanation

### Core Strategy

The function reads chunks of size `BUFFER_SIZE` from the file descriptor
using `read()` and accumulates the data inside a static storage buffer.

The process follows these steps:

1.  Validate `fd` and `BUFFER_SIZE`
2.  Read into a temporary buffer
3.  Append the buffer to a static storage string
4.  Stop reading once a newline is found or EOF is reached
5.  Extract one complete line from the storage
6.  Save the remaining part for the next call
7.  Return the extracted line

### Why a Static Variable?

A static variable retains its value between function calls.

Without it, each invocation would lose previously read but unreturned
data, making it impossible to properly return one line at a time.

The static storage acts as a persistent buffer that:

-   Accumulates unread data
-   Preserves partial reads
-   Ensures continuity between calls

### Memory Flow

-   Temporary buffer → appended to static storage
-   Extracted line → allocated and returned
-   Remaining content → preserved in static storage
-   Freed appropriately on EOF or error

The function never reads the entire file at once. It reads only as much
as necessary to produce the next line.

------------------------------------------------------------------------

## Bonus Part

The bonus extends the project with two additional constraints:

-   Use only one static variable
-   Handle multiple file descriptors simultaneously

Each file descriptor must maintain its own independent reading state.

Example:

``` c
get_next_line(fd1);
get_next_line(fd2);
get_next_line(fd1);
```

Each descriptor must resume from where it previously stopped.

------------------------------------------------------------------------

## Testing Considerations

Edge cases tested:

-   Empty files
-   Files without trailing newline
-   Very small `BUFFER_SIZE`
-   Very large `BUFFER_SIZE`
-   Consecutive newline characters
-   Reading from standard input
-   Invalid file descriptors
-   Large files
-   Pipes and redirected input

------------------------------------------------------------------------

## Compilation

Using Makefile:

``` bash
make
make clean
make fclean
make re
```

Manual compilation:

``` bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c
```

------------------------------------------------------------------------

## Undefined Behavior

The function exhibits undefined behavior if:

-   The file is modified between calls while reading is incomplete
-   A binary file is read without proper handling

------------------------------------------------------------------------

## Resources

### References

-   `man 2 read`
-   Static storage duration in C
-   Unix file descriptors
-   Memory management best practices
-   42 Norm documentation

### AI Usage

AI tools were not used in the development of this project. All
implementation and debugging were performed manually to ensure full
conceptual understanding of static storage, buffer management, and
low-level I/O.

This approach aligns with the 42 philosophy of building foundational
reasoning skills through independent problem-solving and peer learning.

------------------------------------------------------------------------

## Compiler Flags

The project is compiled with:

    -Wall -Wextra -Werror

------------------------------------------------------------------------

## Author

**caide-so**\
42 São Paulo
