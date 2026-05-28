# Printf

### Description
`Printf` involves recreating the standard C library function `printf()`. The goal is to implement a custom version of `printf()` without using the original implementation in order to better understand variadic functions and formatted output.

**General `printf` format syntax:**
```
% [flags] [width] [.precision] [length] specifier
```

### Conversions
- `%c` - print a character.
- `%s` - print a string.
- `%p` - print a pointer address.
- `%d` / `%i` - print a decimal number.
- `%u` - print an unsigned decimal number.
- `%x` - print a hexadecimal number in lowercase.
- `%X` - print a hexadecimal number in uppercase.
- `%%` - print the percent symbol %.

### Flags
- `-` - left align output.
- `+` - always print the sign of the number.
- `(space)` - add leading spaces for positive numbers.
- `#` - used with these specifiers `%o`, `%x`, and `%X`, and the value is proceeded with `0`, `0x`, or `0X` respectively.
- `0` - pad with zeros.
- `width` - minimum field width.
- `.precision` - decimal digits / max string length.

## Instructions
1. Clone this repository:
```
git clone https://github.com/dianabali/42-printf
```
2. Run `make` or `make libftprintf.a` to compile the library `libftprintf.a`.
```
make
```
```
make libftprintf.a
```

**How to delete the files:**
- Run `make clean` to delete the object `.o` files.
- Run `make fclean` to delete the object files and `libftprintf.a`.
- Run `make re` to delete and recompile everything again.

## Resources
- Printf: https://man7.org/linux/man-pages/man3/printf.3.html and https://www.it.uc3m.es/pbasanta/asng/course_notes/input_output_printf_en.html
- Return value of `printf()`: https://www.geeksforgeeks.org/c/return-values-of-printf-and-scanf-in-c-cpp/
- Printf format specifiers and flags: https://cplusplus.com/reference/cstdio/printf/

## Testers
1. printfTester: https://github.com/Tripouille/printfTester
2. UnitTester ft_printf: https://github.com/MagicHatJo/-UT-ft_printf
3. ft_printf_tester: https://github.com/romslf/ft_printf_tester

## Library content
The library contains the following functions:
- `ft_printf` - mimics the real `printf`.
- `ft_putchar` - prints a character (%c).
- `ft_putstr` - prints a string (%s).
- `ft_putnbr` - prints a number (%d, %i).
- `ft_putunsigned` - prints an unsigned int (%u).
- `ft_puthexa` - prints the hexadecimal version of a number (%x, %X).
- `ft_putptr` - prints the address of a pointer (%p).
