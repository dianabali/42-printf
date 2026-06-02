# ft_printf
A step-by-step guide to reimplementing `printf()` in C.

## Project Overview
ft_printf is a 42 project that requires you to recode the `printf()` function from the C standard library. The goal is to produce a static library called `libftprintf.a` that contains `ft_printf()` matching the behaviour of the original.

| Category | Details |
|:-----------|:-----------|
| Library name | libftprintf.a |
| Header file | ft_printf.h |
| Makefile rules | all, clean, fclean, re |
| External functs. | write, va_start, va_arg, va_end |
| Archive command | ar rcs |

## What is `printf()`
`printf()` is a standard C function declared in `<stdio.h>`. It reads a format string and prints characters to stdout, substituting conversion specifiers (%c, %s, ...) with the corresponding arguments.

**Prototype**:
```
int printf(const char *format, ...);
```

**Return value**:  `printf()` returns the total number of characters written to stdout. This is why every helpter function should return an int representing how many characters it printed.

Example:
```
printf("%d\n", printf("%s scored %d in ft_printf\n", "Oscar", 100));

// Output:
// Oscar scored 100 in ft_printf
// 30 (total characters printed)
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

**2. Why the `format[i + 1]` safety check in `ft_printf()`?**

When a '%' is found, the code checks `format[i + 1]` before advancing. If '%' is the last character in the string, format[i + 1] is '\0' (false), so the code skips it safely. Without this check, advancing past i and passing '\0' to `ft_handle_conversion()` would be undefined behaviour.

**3. What is the difference between %d and %i?**


**4. What happens if the format string is NULL?**

If `format` is NULL, there is nothing to iterate over. Attempting to dereference a NULL pointer would cause a segmentation fault. If the format string is NULL, the function should return -1. In this way, you prevent a crash and signal an error via the return value.

**5. Why does '%%' not use a va_arg?**

va_arg retrieves the next argument from the list. '%%' is not a conversion. It has no corresponding argument passed. It simply means print a literal %. 

**6. Why do we use unsigned long for the pointer address `ft_putptr()` and not int?**

On a 64-bit system, a memory address is 64 bits. `int` is only 32 bits, so it cannot hold a full pointer address. Unsigned is used because addresses are never negative.

**7. What would happen if you passed a float to `ft_printf()` with '%f' (not supported)?**

First, float values are automatically promoted to double when passed as variadic arguments, so va_arg(args, float) would actually be wrong. You would need va_arg(args, double). Second, since '%f' is not supported in `ft_printf()`, `ft_handle_conversion()` would hit the final return (0). The float would just be ignored.
```
ft_printf("Value: %f\n", 3.14);

// ft_handle_conversion() receiver 'f', matches nothing, returns 0.
// Output: Value:
```
```
ft_printf("%f %d", 3.14, 42);

// The 3.14 is passed as a double (8 bytes) and sits in the va_list.
// Since %f never calls va_arg, the double is not used.
// Then %d calls va_arg(args, int) but it reads from where 3.14 is sitting in memory, not where 42 is.
// So instead of 42 you get garbage. 42 is never reached at all.
```

**8. What does `ar rcs` do exactly?**

`ar` is the archive tool used to create static libraries.

- r - insert object files into the archive.
- c - create the archive file if it doesn't exist.
- s - write a symbol into the archive so the linker can find functions quickly.

The symbol looks like this:
```
ft_printf -> ft_printf.o
```

So when you compile `ft_printf.c`, the linker sees that it uses `ft_putchar.c`. Instead of opening every .o file one by one to search for it, it looks up `ft_putchar` directly in the symbol table and immediately knows it is in `ft_putchar.o`. It then only pulls that file in.

Without 's', the linker would have to scan through every .o file inside the archive sequentially until it found the right one, which is slow for large libraries with hundreds of functions.

**9. What happens if you call va_arg more times than there are arguments?**
It is undefined behavior. va_arg reads the next value from the stack regardless of whether a real argument was passed there. You get whatever happens to be in memory at that position (garbage values, values from other variables, or a crash).
```
ft_printf("%d %d %d", 42);

// Only one argument passed but three %d specifiers:
// first  va_arg → 42 (correct)
// second va_arg → garbage (reads random stack memory)
// third  va_arg → garbage (reads more random stack memory)
// output could be: 42 -285436856 1458081216 (unpredictable)
```

**10. Why must va_end always be called?**
If you skip it, you may cause memory leaks or stack corruption depending on the system. Even on systems where it compiles and runs fine without it, omitting va_end is undefined behavior according to the C standard so it must always be called before the function returns.
