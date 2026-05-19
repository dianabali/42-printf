#include "ft_printf.h"

int	ft_putptr(void *ptr)
{
	int				count;
	unsigned long	address;

	if (!ptr)
		return (ft_putstr("(null)"));
	count = 0;
	address = (unsigned long)ptr;
	count += ft_putstr("0x");
	count += ft_puthex(address, 0);
	return (count);
}
