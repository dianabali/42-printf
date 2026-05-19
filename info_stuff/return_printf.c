#include <stdio.h>

int	main(void)
{
	char str[] = "hello";
	printf("the return value of printf() is: %d\n", printf("%s\n", str));
}

/*
The return value of printf() is the total number of characters printed.
*/
