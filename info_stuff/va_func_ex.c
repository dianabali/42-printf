#include <stdio.h>
#include <stdarg.h>

int	sum(int count, ...)
{
	va_list args; // va_list to keep track where we are while reading args (iterator)
	va_list copy;

	va_start(args, count); // "The extra args begin after count"
	va_copy(copy, args); // Copies args

	int total_1 = 0;
	int total_2 = 0;

	// First traversal using args
	for (int i = 0; i < count; i++)
		total_1 = total_1 + va_arg(args, int); // Get the next arg and add

	// Second traversal using copy
	for (int i = 0; i < count; i++)
        total_2 = total_2 + va_arg(copy, int);
	
	va_end(args); // Finishes the arg reading
	va_end(copy);

	return (total_1);
}

int	main(void)
{
	printf("%d", sum(3, 10, 20, 30)); //(count, arg1, arg2, arg3)
}
