#include "ft_printf.h"

int	ft_puthex(unsigned long n, int uppercase)
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
		count += ft_puthex(n / 16, uppercase);
	count += ft_putchar(base[n % 16]);
	return (count);
}
