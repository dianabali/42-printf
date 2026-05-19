/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbali <dbali@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 15:35:00 by dbali             #+#    #+#             */
/*   Updated: 2026/05/19 15:35:02 by dbali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	ft_putptr(void *ptr)
{
	int	count;
	unsigned long address;

	if (!ptr)
		return (ft_putstr("(null)"));
	count = 0;
	address = (unsigned long)ptr;
	count += ft_putstr("0x");
	count += ft_puthexa(address, 0);
	return (count);
}

int	main(void)
{
	int num = 42;
    int *ptr = &num;

    printf("address of num:   %p\n", (void *)&num);
    printf("value of ptr:   %p\n", (void *)ptr);
}
