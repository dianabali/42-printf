#include "ft_printf.h"
#include <stdio.h>

/*
	ft_handle_conversion
	Decides which print function to call based on the format specifier.
	Parameters:
		- specifier: The format specifier (c, s, d, i, u, p, x, X, %).
		- args: The va_list containing the arguments passed to ft_printf.
	Returns:
		- The number of characters printed.
		- 0 if the specifier is unknown.
*/

/*
	Example:
	
	if (specifier == 'c')
		return (ft_putchar((char)va_arg(args, int)));

	- va_args - holds the args that you pass to your function ('A').
	- va_args takes the char as int (default argument promotion / type conversion in variadic functions) and returns it as char.
*/

int	ft_handle_conversion(char specifier, va_list args)
{
	// For chars
	// va_arg fetches the next arg as int then cast back to char
	// int - chars are stored as int (ASCII value) in va_arg
	if (specifier == 'c')
		return (ft_putchar((char)va_arg(args, int)));

	// For strings
	// va_arg fetches the next arg as a char pointer
	// char - expects a string
	else if (specifier == 's')
		return (ft_putstr(va_arg(args, char *)));

	// For pointers
	// va_arg fetches the next arg as a void pointer
	// void - to print a memory address of an unknown thing
	else if (specifier == 'p')
		return (ft_putptr(va_arg(args, void *)));

	// For ints and signed ints
	// va_arg fetches the next arg as int
	// int - to print signed decimal numbers
	else if (specifier == 'd' || specifier == 'i')
		return (ft_putnbr(va_arg(args, int)));

	// For unsigned ints
	// va_arg fetches the next arg as unsigned int
	// unsigned int - expects an unsigned int
	else if (specifier == 'u')
		return (ft_putunsigned(va_arg(args, unsigned int)));

	// For lowecase hexadecimal
	// 0 means lowercase
	// unsigned int - hexadecimal interprets bits as unsigned values
	else if (specifier == 'x')
		return (ft_puthexa(va_arg(args, unsigned int), 0));

	// For uppercase hexadecimal
	// 1 means uppercase
	// unsigned int - hexadecimal interprets bits as unsigned values
	else if (specifier == 'X')
		return (ft_puthexa(va_arg(args, unsigned int), 1));

	// For the % sign
	else if (specifier == '%')
		return (ft_putchar('%'));
	
	// If you are passing a specifier that is not handled such as %o or %f
	else
		return (ft_putchar('%'), ft_putchar(specifier));
	return (0); // For unknown specifiers
}

/*
	ft_printf
	The core function.
	Parses the format string and mimics the original printf function.
	Parameters:
		- format - The format string.
		- ... - Variadic args matching the format specifiers in the format string.
*/

int	ft_printf(const char *format, ...)
{
	va_list	args; // Holds the args passed in the format string
	int		count; // The total number of characters printed
	int		i; // Index to iterate through the format string

	if (!format) // If the format string is NULL
		return (-1); // To signal error

	va_start(args, format); // Initialize va_list. Args point to the first argument.

	i = 0;
	count = 0;
	while (format[i]) // Loop through the format string
	{
		if (format[i] == '%' && format[i + 1]) // Current char is a format specifier and ensure % is not the last char
		{
			i++; // Move past %
			count += ft_handle_conversion(format[i], args); // Handle the specifier and add printed chars to count
		}
		else if (format[i] != '%') // If its a char %
			count += ft_putchar(format[i]); // Print it and add +1 to count
		i++; // Move
	}
	va_end(args); // End va_list
	return (count);
}

int	main(void)
{
	int		num;
	char	*str;
	void	*ptr;
	char	*s;

	num = 42;
	str = "hello";
	ptr = &num;
	s = NULL;

	printf("MY FUNC:\n");

	ft_printf("this specifier is not handled: %y\n");
	ft_printf("char:          %c\n", 'A');
	ft_printf("string:        %s\n", str);
	ft_printf("null string:   %s\n", s);
	ft_printf("pointer:       %p\n", ptr);
	ft_printf("null pointer:  %p\n", NULL);
	ft_printf("decimal:       %d\n", num);
	ft_printf("negative:      %d\n", -42);
	ft_printf("integer:       %i\n", num);
	ft_printf("unsigned:      %u\n", 4294967295u);
	ft_printf("unsigned -1:   %u\n", -1);
	ft_printf("hex lower:     %x\n", 15);
	ft_printf("hex upper:     %X\n", 15);
	ft_printf("percent:       100%%\n");
	ft_printf("\n%s scored %x in libft\n", "oscar", 256);
	ft_printf("\nlen of hello:  %d\n", ft_printf("\nhello"));

	printf("\nREAL FUNC:\n");

	printf("this specifier is not handled: %y\n");
	printf("char:          %c\n", 'A');
	printf("string:        %s\n", str);
	printf("null string:   %s\n", s);
	printf("pointer:       %p\n", ptr);
	printf("null pointer:  %p\n", NULL);
	printf("decimal:       %d\n", num);
	printf("negative:      %d\n", -42);
	printf("integer:       %i\n", num);
	printf("unsigned:      %u\n", 4294967295u);
	printf("unsigned -1:   %u\n", -1);
	printf("hex lower:     %x\n", 15);
	printf("hex upper:     %X\n", 15);
	printf("percent:       100%%\n");
	printf("\n%s scored %x in libft\n", "oscar", 256);
	printf("\nlen of hello:  %d\n", ft_printf("\nhello"));
}
