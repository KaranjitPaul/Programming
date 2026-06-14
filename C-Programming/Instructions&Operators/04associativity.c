#include <stdio.h>

int main(void) {
    int a = 5;
    int b = 2;
    int c = 10;

    // Operators with the same precedence are evaluated from left to right.
    printf("Division then multiplication: %d\n", c / b * a); // (10 / 2) * 5 = 25
    printf("Multiplication then division: %d\n", c * b / a); // (10 * 2) / 5 = 4

    // 7.0 makes the final addition use floating-point arithmetic.
    printf("A longer expression: %.2f\n", 3 * b / 2 * c + 7.0 * a);
    // (((3 * 2) / 2) * 10) + (7.0 * 5) = 30 + 35.0 = 65.0

    return 0;
}
