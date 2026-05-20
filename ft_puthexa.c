/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbali <dbali@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 15:18:03 by dbali             #+#    #+#             */
/*   Updated: 2026/05/19 15:26:09 by dbali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	ft_puthexa
	Prints a number in hexadecimal.
	Parameters:
		- n: The number to convert.
		- uppercase: If non-zero, uses uppercase hex digits (A-F), otherwise lowercase (a-f).
*/

#include "ft_printf.h"
#include <stdio.h>

int	ft_puthexa(unsigned long n, int uppercase)
{
	char	*base_lower; // Lowercase digits
	char	*base_upper; // Uppercase digits
	char	*base; // Which base will be used
	int		count; // Total number of characters printed

	base_lower = "0123456789abcdef";
	base_upper = "0123456789ABCDEF";
	if (uppercase) // If uppercase flag is set (1 or 0)
		base = base_upper;
	else
		base = base_lower;
	count = 0;
	if (n >= 16) // If n has more than one hex digit
		count += ft_puthexa(n / 16, uppercase);
	count += ft_putchar(base[n % 16]); // Print the digit
	return (count);
}

int	main(void)
{
	ft_puthexa(10, 0);
	ft_putchar('\n');
	ft_puthexa(10, 1);
}
