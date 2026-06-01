#include "ft_printf.h"
#include <stdio.h>

/*
	Returns 10 raised to the power exp.

	Examples:
	ft_pow10(0) = 1
	ft_pow10(1) = 10
	ft_pow10(2) = 100
	ft_pow10(3) = 1000
*/
static long	ft_pow10(int exp)
{
	long	result;

	result = 1; // Start with 10^0 = 1

	// Multiply by 10 exp times
	while (exp--)
		result *= 10;
	return (result);
}

/*
Prints a floating-point number with a specified precision.
	Parameters:
		n - Number to print
		precision - Number of digits after the decimal point
*/
int	ft_putfloat(double n, int precision)
{
	int		count; // Counts printed characters
	long	integer; // Integer part of n (3 in 3.14)
	long	decimal; // Decimal digits after scaling
	double	frac; // Fractional part of n (0.14 in 3.14)
	int		digits; // Used for leading-zero padding
	long	temp; // Temporary copy of decimal

	count = 0;

	/*
		If precision is negative, use the default precision of 6.
			Example:
			ft_putfloat(1.5, -1)
			prints: 1.500000
	*/
	if (precision < 0)
		precision = 6;

	/*
		Handle negative numbers.
			Example:
			n = -0.5
			Print '-', then make n positive so the rest of the code can work with positive values.
	*/
	if (n < 0)
	{
		count += ft_putchar('-');
		n = -n;
	}

	/*
		Extract the integer part.
			Example:
			3.14159 -> 3
			Casting to long removes everything after the decimal point.
	*/
	integer = (long)n;

	/*
		Special case: No decimal places requested.
			Example:
			ft_putfloat(3.7, 0)
			Output: 3
	*/
	if (precision == 0)
	{
		count += ft_putnbr(integer);
		return (count);
	}

	/*
		Extract the fractional part.
			Example:
			n = 3.14159
			integer = 3
			frac = 0.14159
	*/
	frac = n - (double)integer;

	/*
		Convert fractional part into an integer for ft_putnbr()
			Example:
			frac = 0.14159
			precision = 4
			10^4 = 10000
			0.14159 * 10000 = 1415.9
			Add 0.5 for rounding:
			1415.9 + 0.5 = 1416.4
			Cast to long:
			decimal = 1416
	*/
	decimal = (long)(frac * ft_pow10(precision) + 0.5);

	/*
		Handle rounding overflow.
			Example:
			9.999 with precision 2 decimal becomes 100
			But valid decimal range for precision 2 is 00-99.
			So:
				integer becomes 10
				decimal becomes 0
			Result: 10.00
	*/
	if (decimal >= ft_pow10(precision))
	{
		integer++;
		decimal -= ft_pow10(precision);
	}

	// Print integer portion
	count += ft_putnbr(integer);

	// Print decimal point and decimal digits.
	if (precision > 0)
	{
		// Print '.'
		count += ft_putchar('.');

		// Used to determine how many leading zeros must be printed.
		digits = precision;
		temp = decimal;

		/*
			Add leading zeros.
				Example:
				decimal = 10
				precision = 4
				Need: 0010
				Not: 10
		*/
		while (--digits > 0 && temp < ft_pow10(digits))
			count += ft_putchar('0');

		/*
			Print decimal digits.
				Example: decimal = 141590
		*/
		count += ft_putnbr(decimal);
	}

	// Return total characters printed.
	return (count);
}

int	main(void)
{
	printf("positive number:  3.141590\n");
	ft_putfloat(3.14159, 6);
	printf("\n\n");

	printf("negative number:  -0.50\n");
	ft_putfloat(-0.5, 2);
	printf("\n\n");

	printf("leading zeros:  0.0010\n");
	ft_putfloat(0.001, 4);
	printf("\n\n");

	printf("rounding with precision 2:  10.00\n");
	ft_putfloat(9.999, 2);
	printf("\n\n");

	printf("zero precision:  3\n");
	ft_putfloat(3.7, 0);
	printf("\n\n");

	printf("default precision:  1.500000\n");
	ft_putfloat(1.5, -1);
	printf("\n\n");

	return (0);
}
