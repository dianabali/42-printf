# ft_printf
A step-by-step guide to reimplementing `printf()` in C.

## Project Overview
ft_printf is a 42 project that requires you to recode the `printf()` function from the C standard library. The goal is to produce a static library called `libftprintf.a` that contains `ft_printf()` matching the behaviour of the original.

| Category | Details |
|:-----------|:-----------|
| Library name | libftprintf.a |
| Header file | ft_printf.h |
| Makefile rules | all, clean, fclean, re |
| External functs. | malloc, free, write, va_start, va_arg, va_copy, va_end |
| Archive command | ar rcs (libtool is forbidden) |

## What is `printf()`
`printf()` is a standard C function declared in `<stdio.h>`. It reads a format string and prints characters to stdout, substituting conversion specifiers (%c, %s, ...) with the corresponding arguments.

**Prototype**:
```
int printf(const char *format, ...);
```

**Return value**:  `printf()` returns the total number of characters written to stdout. This is why every helpter function should return an int representing how many characters it printed.

Example:
```
printf("%d\n", printf("%s scored %d% in ft_printf", "Oscar", 100));
// Output: Oscar scored 100% in ft_printf
// 30 - total characters printed.
```

## Variadic Functions
`printf()` accepts a variable number of arguments (the ... in its protptype). To access these arguments in C you must use the variadic macros defined in `<stdarg.h>`.

### Macros
| Macro | Description |
|:------------------|:-------------|
| va_list args | Declares a variable that holds the list of extra arguments |
| va_start(args, last) | Initializes args. `last` is the last named parameter before `...` |
| va_arg(args, type) | Retrieves the next argument from the list, cast to `type` |
| va_end(args) | Cleans up the `va_list`. Must always be called before returning |

Example of a simple variadic function:
```
#include <stdio.h>
#include <stdarg.h>

int	sum(int count, ...)
{
	va_list args; // va_list to keep track where we are while reading args (iterator)
	va_list copy;

	va_start(args, count); // "The extra args begin after count"
	va_copy(copy, args); // Copies args

	int total_1 = 0;
	int total_2 = 0;

	// First traversal using args
	for (int i = 0; i < count; i++)
		total_1 = total_1 + va_arg(args, int); // Get the next arg and add

	// Second traversal using copy
	for (int i = 0; i < count; i++)
        total_2 = total_2 + va_arg(copy, int);
	
	va_end(args); // Finishes the arg reading
	va_end(copy);

	return (total_1);
}

int	main(void)
{
	printf("%d", sum(3, 10, 20, 30)); //(count, arg1, arg2, arg3)
}
```

## Conversion Specifiers
| Specifier | Name | Description |
|:-----------|:------|:-------------|
| `%c` | Character | Prints a single character |
| `%s` | String | Prints a null-terminated string. `NULL` prints as `"(null)"` |
| `%p` | Pointer | Prints a `void *` address in hex with `0x` prefix. `NULL` prints as `"(nil)"` |
| `%d` | Decimal | Prints a signed decimal integer (base 10) |
| `%i` | Integer | Same as `%d` — prints a signed integer in base 10 |
| `%u` | Unsigned integer | Prints an unsigned decimal integer |
| `%x` | Hex lower | Prints an unsigned integer in hexadecimal lowercase |
| `%X` | Hex upper | Prints an unsigned integer in hexadecimal uppercase |
| `%%` | Percent | Prints a percent sign |

## Project Structure
1. `Makefile` - to create `libftprintf.a`.
2. `ft_printf.h` - the header file.
3. `ft_printf.c` - main function + `ft_handle_conversion()`.
4. `ft_putchar.c` - %c handler.
5. `ft_putstr.c` - %s handler.
6. `ft_putnbr.c` - %d and %i handler.
7. `ft_putunsigned.c` - %u handler.
8. `ft_puthexa.c` - %X and %x handler.
9. `ft_putptr.c` - %p handler.

## Step-by-step Implementation Guide
### Step 1: `ft_printf.h`
The header file must be named `ft_printf.h` and must include the prototype of `ft_printf()` and all helper function prototypes.

My header file: [ft_printf.h](ft_printf.h)

### Step 2: `ft_putchar.c`
The simpliest helper function. Uses `write()` to output one character and returns 1 (one character printed).

My ft_putchar: [ft_putchar.c](ft_putchar.c)

### Step 3: `ft_putstr.c`
Loops through a string and prints each character. Returns the total length so `ft_printf()` knows how many characters were written. Handles NULL string by printing "(null)".

My ft_putstr: [ft_putstr.c](ft_putstr.c)

### Step 4: `ft_putnbr.c`
Handles signed integers. Casts to long first to safely handle INT_MIN without overflow. User recursion to print digits in the correct order.

My ft_putnbr: [ft_putnbr.c](ft_putnbr.c)

### Step 5: `ft_putunsigned.c`
Same recursive approach as `ft_putnbr` but no sign handling since the value is always positive.

My ft_putunsigned: [ft_putunsigned.c](ft_putunsigned.c)

### Step 6: `ft_puthexa.c`
Handles both %x (lowercase) and %X (uppercase) using the uppercase flag to choose the base string. Uses the same recursive approach.

My ft_puthexa: [ft_puthexa.c](ft_puthexa.c)

### Step 7: `ft_putptr.c`
Prints a pointer address. Always prefixes with "0x" and uses lowercase hexadecimal. If you pass a NULL pointer, it is going to print "(nil)".

My ft_putptr: [ft_putptr.c](ft_putptr.c)

### Step 8: `ft_printf.c`
This is the main function. Iterates through the format string character by character. When it encounters '%', it checks that the next element exists, then calls `ft_handle_conversion()` with the specifier and the `va_list`. Plain characters are printed directly with `ft_putchar()`.

My ft_printf: [ft_printf.c](ft_printf.c)

### Step 9: `Makefile`
The Makefile compiles all .c files into .o object files, then archives them into `libftprintf.a` using `ar rcs`.

My Makefile: [Makefile](Makefile)

| Rule / Syntax | Description |
|--------------|-------------|
| `ar rcs` | Creates a static library. `r=insert`, `c=create`, `s=add index` |
| `$(SRCS:.c=.o)` | Pattern substitution: replaces `.c` with `.o` for all source files |
| `-Wall -Wextra -Werror` | All compiling flags |
| `$<` | Automatic variable: the first prerequisite (the `.c` file) |
| `${<:.c=.o}` | Automatic variable: the target (the `.o` file). Replace .c with .o |
| `.PHONY` | Tells `make` these are not real files, always run them |

## Key concepts to understand
**1. Why do all helper functions return `int`?**

`ft_printf()` must return the total number of character printed (the behaviour of the real `printf()`. Since it uses helper functions to print, each helper must tell how many characters it printed. `ft_printf()` accumulates all these return values into count and returns it at the end.

**2. Why the `format[i + 1]` safety check?**

When a '%' is found, the code checks `format[i + 1]` before advancing. If '%' is the last character in the string, format[i + 1] is '\0' (false), so the code skips it safely. Without this check, advancing past i and passing '\0' to `ft_handle_conversion()` would be undefined behaviour.

**3. What is the difference between %d and %i?**


















