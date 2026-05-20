/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbali <dbali@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 12:46:09 by dbali             #+#    #+#             */
/*   Updated: 2026/05/19 12:46:18 by dbali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	ft_putunsigned
	Prints an unsigned integer.
	Parameters:
		- n: The unsigned int to print.
*/

#include "ft_printf.h"
#include <stdio.h>

int	ft_putunsigned(unsigned int n)
{
	int	count; // The total number of characters printed

	count = 0;
	if (n >= 10) // If n has more than 1 digit
		count += ft_putunsigned(n / 10);
	count += ft_putchar((char)(n % 10 + '0')); // Convert to ASCII and print
	return (count);
}

int	main(void)
{
	printf("%u", ft_putunsigned(-5));
}
