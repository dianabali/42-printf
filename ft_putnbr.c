/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbali <dbali@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 12:25:59 by dbali             #+#    #+#             */
/*   Updated: 2026/05/19 12:25:59 by dbali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// %d - for decimal
// %i - for decimal, hexadecimal, and octal

#include "ft_printf.h"
#include <stdio.h>

int	ft_putnbr(int n)
{
	int		count;
	long	nb;

	count = 0;
	nb = n;
	if (nb < 0)
	{
		count += ft_putchar('-');
		nb = -nb;
	}
	if (nb >= 10)
		count += ft_putnbr(nb / 10);
	count += ft_putchar((char)(nb % 10 + '0'));
	return (count);
}

int	main(void)
{
	printf("%s\n", "my func:");
	ft_putnbr(404); // 404
	printf("%c", '\n');
	printf("\n%d", ft_putnbr(404)); // 404 and 3
	

	printf("%c", '\n');

	printf("\n%s\n", "real func:");
	printf("%d", 404); // 404
	printf("%c", '\n');
	printf("\n%d", printf("%d", 404)); // 404 and 3
}
