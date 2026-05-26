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

/*
	ft_putptr
	Prints a pointer's memory address in hexadecimal.
	Parameters:
		- ptr: The pointer whose address will be printed.
*/

#include "ft_printf.h"
#include <stdio.h>

int	ft_putptr(void *ptr)
{
	int	count; // Total number of characters printed
	unsigned long address; // Stores the pointer address

	if (!ptr) // If the pointer is NULL, the address is 0
		return (ft_putstr("(nil)"));
	count = 0;
	address = (unsigned long)ptr; // Cast to get the address as a number
	count += ft_putstr("0x"); // Print the '0x' prefix
	count += ft_puthexa(address, 0); // Print the address in lowercase hexadecimal
	return (count);
}

int	main(void)
{
	int num = 42;
    int *ptr = &num;

	printf("%s\n", "my func:");
	ft_putptr(ptr); // 0x7ffcdb46edac
	printf("%c", '\n');
	ft_putptr(&num); // 0x7ffcdb46edac
	printf("%c", '\n');
	printf("\n%d", ft_putptr(ptr)); // 0x7ffcdb46edac and 14

	printf("\n\n%s\n", "real func:");
	// Casting to void * because printf expects a void pointer for %p
    printf("%p\n", (void *)&num); // 0x7ffcdb46edac
    printf("%p\n", (void *)ptr); // 0x7ffcdb46edac
	printf("\n%d\n", printf("%p", (void *)ptr)); // 0x7ffcdb46edac and 14
}
