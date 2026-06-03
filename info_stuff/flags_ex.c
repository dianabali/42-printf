#include <stdio.h>

void printf_flag_ex() {
    int num = 42;
    int neg = -42;
    double pi = 3.141592;
    int hex = 255;

    // 1. Left alignment (-)
  	// - means  left-align
  	// 10 means total width of 10 characters
    printf("1. Left align     : |%-10d|\n", num);

    // 2. Right alignment with spaces (default)
    printf("2. Right align    : |%10d|\n", num);

    // 3. Zero padding (0)
    printf("3. Zero padded    : |%010d|\n", num);

    // 4. Always show sign (+)
    printf("4. Show sign      : |%+d| |%+d|\n", num, neg);

	// 5. Space before positive number ( )
    printf("5. Space flag     : |% d| |% d|\n", num, neg);

    // 6. Alternate form (#) - hexadecimal
    printf("6. Hex alternate  : |%#x|\n", hex);

	// 7. Alternate form (#) - octal
    printf("7. Octal alternate: |%#o|\n", hex);

    // 8. Precision for floating point
    printf("8. Precision      : |%.2f|\n", pi);

    // 9. Width + precision
	// Width = 10, Precision = 2
    printf("9. Width+precision: |%10.2f|\n", pi);

    // 10. String precision (max chars printed)
	// Prints only 5 characters
    printf("10. String cut     : |%.5s|\n", "HelloWorld");
}

int main() {
    printf_flag_ex();

	// Left align, Always show sign, Width 10
	printf("\nCombination of flags: %-+10d", 42);
    return 0;
}
