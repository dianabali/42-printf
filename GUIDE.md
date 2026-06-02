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
int n = printf("%s scored %d% in ft_printf", "Oscar", 100);
// Output: Oscar scored 100% in ft_printf
// n = 30 (total characters printed)
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
1. Makefile - to create `libftprintf.a`.
2. ft_printf.h - the header file.
3. ft_printf.c - main function + `ft_handle_conversion()`.
4. ft_putchar.c - %c handler.
5. ft_putstr.c - %s handler.
6. ft_putnbr.c - %d and %i handler.
7. ft_putunsigned.c - %u handler.
8. ft_puthexa.c - %X and %x handler.
9. ft_putptr.c - %p handler.

## Step-by-step Implementation Guide



