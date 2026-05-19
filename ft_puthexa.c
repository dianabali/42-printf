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

#include "ft_printf.h"
#include <stdio.h>

int	ft_puthexa(unsigned long n, int uppercase)
{
	char	*base_lower;
	char	*base_upper;
	char	*base;
	int		count;

	base_lower = "0123456789abcdef";
	base_upper = "0123456789ABCDEF";
	if (uppercase)
		base = base_upper;
	else
		base = base_lower;
	count = 0;
	if (n >= 16)
		count += ft_puthexa(n / 16, uppercase);
	count += ft_putchar(base[n % 16]);
	return (count);
}

int	main(void)
{
	printf("%x\n", 10);
	printf("%X\n", 10);
}
