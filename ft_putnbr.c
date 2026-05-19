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

#include "ft_printf.h"
// #include <stdio.h>

int	ft_putnbr(int n)
{
	int	count;
	int	nb;

	count = 0;
	nb = (long)n;
	if (nb < 0)
	{
		count += ft_putchar('-');
		nb = -nb;
	}
	if (nb >= 10)
		count += ft_putnbr((int)(nb / 10));
	count += ft_putchar((char)(nb % 10 + '0'));
	return (count);
}

/* int	main(void)
{
	printf("%d", ft_putnbr(444));
} */
