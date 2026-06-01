// ft_handle_conversion:
else if (spec == 'o')
    return (ft_putnbr_base(va_arg(args, unsigned int), "01234567"));


#include "ft_printf.h"
#include <stdio.h>

int	ft_putoct(unsigned int n)
{
	int		count;
	char	*base;

	base = "01234567";
	count = 0;
	if (n >= 8)
		count += ft_putoct(n / 8);
	count += ft_putchar(base[n % 8]);
	return (count);
}

int	main(void)
{
	printf("%s\n", "my func:");
	ft_putoct(67); // 103
	printf("%c", '\n');
	printf("%o\n", 67); // 103
}
