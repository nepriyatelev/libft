# libft

*This project has been created as part of the 42 curriculum by modysseu.*

## Description

This project is about coding your own C library with useful general-purpose functions for future C projects at 42 School. The goal is to create a comprehensive library (libft.a) that reimplements standard C library functions and adds additional utility functions. Through this project, you'll learn how standard library functions work by implementing them yourself, develop a deep understanding of C programming, memory management, and data structures (specifically linked lists).

The libft library will be the foundation for all your future 42 projects, as many assignments will depend on and use these functions.

## Instructions

### Compilation

```bash
make all       # Compile the library (creates libft.a) - explicit rule
make           # Compile the library (default rule, same as 'make all')
make clean     # Remove object files (.o)
make fclean    # Remove object files and library (.a)
make re        # Clean and recompile (equivalent to 'make fclean' then 'make all')
make bonus     # Compile with bonus functions

```

### Installation

To use libft in your projects:

```bash
# Copy the library folder to your project
cp -r libft /path/to/your/project/

# In your project's Makefile, include:
LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

$(LIBFT):
	make -C $(LIBFT_DIR)

# Link your program with libft
your_program: $(LIBFT) your_objs.o
	cc -I $(LIBFT_DIR)/includes -L $(LIBFT_DIR) your_objs.o -lft -o your_program
```

## Resources

### Documentation

- [C Standard Library Reference](https://en.cppreference.com/w/c) - Complete C library documentation
- [Man Pages Online](https://man7.org/linux/man-pages/) - Unix man pages for standard functions
- [42 School Norm](https://github.com/42School/norminette) - Official 42 coding standard
- [C Programming Documentation](https://www.iso.org/standard/74528.html) - ISO C standard

### Tutorials & Learning Resources

- [C Memory Management](https://www.tutorialspoint.com/cprogramming/c_memory_management.htm) - Deep dive into malloc/free
- [Linked Lists in C](https://www.cprogramming.com/tutorial/c/lesson15.html) - Understanding data structures
- [Makefile Tutorial](https://www.gnu.org/software/make/manual/) - Build system basics
- [Git Basics](https://git-scm.com/book/en/v2) - Version control fundamentals
- [C Strings Guide](https://www.programiz.com/c-programming/c-strings) - String handling techniques

### Articles & References

- "The C Programming Language" by Brian W. Kernighan and Dennis M. Ritchie - Classic reference
- [Pointer Basics](https://www.cprogramming.com/tutorial/c/lesson6.html) - Understanding pointers
- [Type Conversion in C](https://www.tutorialspoint.com/cprogramming/c_type_casting.htm) - Type casting and conversion

## Detailed Library Description

### Part 1: Libc Functions (25 functions)

#### String Manipulation (11 functions)
- `ft_strlen` - Calculate the length of a string
- `ft_strcpy` - Copy a string (unsafe)
- `ft_strncpy` - Copy at most n characters of a string
- `ft_strcat` - Concatenate strings (unsafe)
- `ft_strncat` - Concatenate at most n characters
- `ft_strcmp` - Compare two strings
- `ft_strncmp` - Compare at most n characters
- `ft_strchr` - Find first occurrence of a character
- `ft_strrchr` - Find last occurrence of a character
- `ft_strstr` - Find first occurrence of a substring
- `ft_strnstr` - Find first occurrence of substring in n bytes

#### Memory Operations (6 functions)
- `ft_memset` - Fill memory with a constant value
- `ft_bzero` - Zero out memory
- `ft_memcpy` - Copy memory (non-overlapping)
- `ft_memmove` - Copy memory (may overlap)
- `ft_memcmp` - Compare memory areas
- `ft_memchr` - Find byte in memory

#### Character Checks (6 functions)
- `ft_isalpha` - Check if character is alphabetic
- `ft_isdigit` - Check if character is a digit
- `ft_isalnum` - Check if alphanumeric
- `ft_isascii` - Check if ASCII character
- `ft_isprint` - Check if printable character
- `ft_toupper`/`ft_tolower` - Case conversion

#### Conversion Functions (2 functions)
- `ft_atoi` - Convert string to integer
- `ft_calloc` - Allocate memory and initialize to zero

### Part 2: Additional Functions (11 functions)

- `ft_substr` - Extract substring from string
- `ft_strjoin` - Concatenate two strings with memory allocation
- `ft_strtrim` - Remove specified characters from beginning and end
- `ft_split` - Split string by delimiter character
- `ft_itoa` - Convert integer to string representation
- `ft_strmapi` - Apply function to each character with index
- `ft_striteri` - Apply function to each character (mutable)
- `ft_putchar_fd` - Output character to file descriptor
- `ft_putstr_fd` - Output string to file descriptor
- `ft_putendl_fd` - Output string with newline to file descriptor
- `ft_putnbr_fd` - Output integer to file descriptor

### Part 3: Linked List Functions (9 functions)

```c
typedef struct s_list
{
    void            *content;  // Generic data storage
    struct s_list   *next;     // Pointer to next node
}                   t_list;
```

- `ft_lstnew` - Create new list node
- `ft_lstadd_front` - Add node to front of list
- `ft_lstadd_back` - Add node to end of list
- `ft_lstsize` - Count nodes in list
- `ft_lstlast` - Get last node of list
- `ft_lstdelone` - Delete and free single node
- `ft_lstclear` - Delete and free entire list
- `ft_lstiter` - Apply function to each node
- `ft_lstmap` - Create new list from function applied to each node

## Requirements

- **Language:** C
- **Compiler:** cc with flags -Wall -Wextra -Werror
- **Norm:** Must comply with 42 School Norm
  - Maximum 25 lines per function
  - Maximum 5 functions per file
  - Maximum 4 local variables per function
  - C89 style (all variables declared at function start)
  - Maximum 80 characters per line
- **Memory:** No memory leaks, proper error handling
- **Build:** Makefile with rules: all, clean, fclean, re, bonus
- **Dependencies:** Only standard C library

---

*This is the first foundation project at 42 School, where you develop essential C programming skills by implementing your own library. The knowledge gained here forms the basis for all future projects.*