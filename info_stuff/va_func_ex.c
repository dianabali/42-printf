#include <stdio.h>
#include <stdarg.h>

int	sum(int count, ...)
{
	va_list args; // va_list to keep track where we are while reading args (iterator)

	va_start(args, count); // "The extra args begin after count"

	int total = 0;

	for (int i = 0; i < count; i++)
		total = total + va_arg(args, int); // Get the next arg and add
	va_end(args); // Finishes the arg reading
	return (total);
}

int	main(void)
{
	printf("%d", sum(3, 10, 20, 30)); //(count, arg1, arg2, arg3)
}