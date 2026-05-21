#include "ft_printf.h"

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

int	ft_handle_conversion(char specifier, va_list args)
{
	// For chars
	// va_arg fetches the next arg as int then cast back to char
	if (specifier == 'c')
		return (ft_putchar((char)va_arg(args, int)));

	// For strings
	// va_arg fetches the next arg as a char pointer
	else if (specifier == 's')
		return (ft_putstr(va_arg(args, char *)));

	// For pointers
	// va_arg fetches the next arg as a void pointer
	else if (specifier == 'p')
		return (ft_putptr(va_arg(args, void *)));

	// For ints and signed ints
	// va_arg fetches the next arg as int
	else if (specifier == 'd' || specifier == 'i')
		return (ft_putnbr(va_arg(args, int)));

	// For unsigned ints
	// va_arg fetches the next arg as unsigned int
	else if (specifier == 'u')
		return (ft_putunsigned(va_arg(args, unsigned int)));

	// For lowecase hexadecimal
	// 0 means lowercase
	else if (specifier == 'x')
		return (ft_puthexa(va_arg(args, unsigned int), 0));

	// For uppercase hexadecimal
	// 1 means uppercase
	else if (specifier == 'X')
		return (ft_puthexa(va_arg(args, unsigned int), 1));

	// For the % sign
	else if (specifier == '%')
		return (ft_putchar('%'));
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

	num = 42;
	str = "hello";
	ptr = &num;

	ft_printf("char:          %c\n", 'A'); // A
	ft_printf("string:        %s\n", str); // hello
	ft_printf("null string:   %s\n", NULL); // Seg fault if the string is NULL
	ft_printf("pointer:       %p\n", ptr); // 0x7ffc3c0c74ec
	ft_printf("null pointer:  %p\n", NULL); // (null)
	ft_printf("decimal:       %d\n", num); // 42
	ft_printf("negative:      %d\n", -42); // -42
	ft_printf("integer:       %i\n", num); // 42
	ft_printf("unsigned:      %u\n", 4294967295u); // 4294967295
	ft_printf("unsigned -1:   %u\n", -1); // 4294967295
	ft_printf("hex lower:     %x\n", 15); // f
	ft_printf("hex upper:     %X\n", 15); // F
	ft_printf("percent:       100%%\n"); // 100%
	ft_printf("\n%s scored %x in libft\n", "oscar", 64); // mixed: oscar scored 100 in libft
	ft_printf("\nreturn value:  %d\n", ft_printf("\nhello")); // hello + 6
}
