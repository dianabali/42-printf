#include "ft_printf.h"
#include <stdio.h>

// returns 10 raised to the power of exp (e.g. ft_pow10(3) → 1000)
static long	ft_pow10(int exp)
{
	long	result; /* accumulates the power of 10 */

	result = 1;
	while (exp--)
		result *= 10;
	return (result);
}

/*
** ft_putfloat - prints a positive double with a given precision
**
** params:
**   n         - the positive double to print
**   precision - number of decimal places (pass -1 for default of 6)
**
** examples:
**   ft_putfloat(3.14159, 6)  → "3.141590"
**   ft_putfloat(0.001, 4)    → "0.0010"
**   ft_putfloat(9.999, 2)    → "10.00"  (rounding carry)
*/
int	ft_putfloat(double n, int precision)
{
	int		count;     /* total characters written */
	long	integer;   /* integer part of n (e.g. 3 from 3.14) */
	long	decimal;   /* decimal part shifted to integer (e.g. 14 from 3.14 at precision 2) */
	double	frac;      /* fractional part of n (e.g. 0.14 from 3.14) */
	int		digits;    /* used to count leading zeros in decimal part */
	long	tmp;       /* copy of decimal used in leading zero check */

	count = 0;
	if (precision < 0)
		precision = 6; /* default precision matches printf behavior */
	if (n < 0)
	{
		count += ft_putchar('-'); /* print minus sign for negative values */
		n = -n;                  /* work with positive value from here on */
	}
	integer = (long)n;                              /* strip fractional part */
	frac = n - (double)integer;                     /* isolate fractional part */
	decimal = (long)(frac * ft_pow10(precision) + 0.5); /* shift and round */
	/* if rounding pushed decimal to next power, carry into integer */
	if (decimal >= ft_pow10(precision))
	{
		integer++;
		decimal -= ft_pow10(precision);
	}
	count += ft_putnbr(integer); /* print integer part */
	if (precision > 0)
	{
		count += ft_putchar('.'); /* print decimal point */
		digits = precision;
		tmp = decimal;
		/* print leading zeros (e.g. 0.001 needs two leading zeros) */
		while (--digits > 0 && tmp < ft_pow10(digits))
			count += ft_putchar('0');
		count += ft_putnbr(decimal); /* print decimal digits */
	}
	return (count);
}
