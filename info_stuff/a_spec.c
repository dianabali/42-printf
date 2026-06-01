#include "ft_printf.h"
#include <stdio.h>

// int	ft_putchar(char c)
// {
// 	write(1, &c, 1);
// 	return (1);
// }

// int	ft_putstr(char *str)
// {
// 	int	i;

// 	i = 0;
// 	while (str[i])
// 	{
// 		ft_putchar(str[i]);
// 		i++;
// 	}
// 	return (i);
// }

int	ft_handle_conversion(char specifier, va_list args)
{
	if (specifier == 'a')
		return (ft_putstr("my awesome 42"));
    return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;
	int		i;

	if (!format)
		return (-1);

	va_start(args, format);

	i = 0;
	count = 0;
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			i++;
			count += ft_handle_conversion(format[i], args);
		}
		else if (format[i] != '%')
			count += ft_putchar(format[i]);
		i++;
	}
	va_end(args);
	return (count);
}

int	main(void)
{
	ft_printf("%s\n", "hello %a world");
}
