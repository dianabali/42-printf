#include <stdio.h>

int main(void)
{
	char *ptr = "hello";

	printf("Char: %c\n", 'A');
	printf("String: %s\n", ptr);
	printf("Pointer: %p\n", &ptr);
	printf("Int: %d\n", 42);
	printf("Int: %i\n", 42);
	printf("Unsigned int: %u\n", -5);
	printf("Lowcase hex: %x\n", 42);
	printf("Uppcase hex: %X\n", 42);
	printf("Percentage: %%\n");
}

// %u specifier - used for unsigned integers
// For signed int, C uses two's complement representation (write the int in binary, invert all bits, add 1)

// Example:
// -5

// Write -5 in binary:
// 5 = 00000000 00000000 00000000 00000101
// Invert = 11111111 11111111 11111111 11111010
// Add 1: 11111111 11111111 11111111 11111011
// -5 in memory is: 11111111 11111111 11111111 11111011

// Compute the value of -5: 2^32 - 5 = 4294967291 (unsigned = 2^32 + signed)

// Result:
// -5 in binary in 32-bit two's complement: 11111111 11111111 11111111 11111011
// -5 as unsigned int: 4294967291
