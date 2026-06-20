#include <stdio.h>

int main() {
    int big_num = 15;
    int small_num = 4;

    // Addition
    int sum = big_num + small_num;
    printf("Arithmetic Operations:\nSum: %d\n", sum);

    // Subtraction
    int difference = big_num - small_num;
    int reverse_difference = small_num - big_num;
    printf("Difference: %d\nReverse difference: %d\n", difference, reverse_difference);

    // Multiplication
    int product = big_num * small_num;
    printf("Product: %d\n", product);

    // Both operands are int, so integer division removes the decimal part.
    int integer_division = big_num / small_num;

    // Explicitly converting one operand to float makes this floating-point division.
    float floating_division = big_num / (float)small_num;

    printf("Integer division: %d\n", integer_division);
    printf("Floating-point division: %.2f\n", floating_division);

    // Modulus gives the remainder after integer division.
    int remainder = big_num % small_num;
    printf("Remainder: %d\n", remainder);

    return 0;
}
