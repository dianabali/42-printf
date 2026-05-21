/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbali <dbali@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 11:54:20 by dbali             #+#    #+#             */
/*   Updated: 2026/05/19 11:58:53 by dbali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	ft_putchar
	Prints a character.
	Parameters:
		- c: The character to be printed.
*/

#include "ft_printf.h"
// #include <stdio.h>

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	main(void)
{
	printf("%s\n", "my func:");
	printf("%d", ft_putchar('A')); // Prints A and 1 (nr of characters)

	printf("%c", '\n');

	printf("\n%s\n", "real func:");
	printf("%d", printf("%c", 'A')); // Prints A and 1
}
