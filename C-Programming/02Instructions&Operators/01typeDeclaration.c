#include <stdio.h>

int main(void) {
    int i = 10; // Declare and initialize 'i' with 10
    int j = i;  // Initialize 'j' using the value stored in 'i'
    int a = 2, b = 3, c = 4, d = 5;

    printf("The value of i is %d and value of j is %d\n", i, j);
    printf("The value of a is %d and value of b is %d\n", a, b);
    printf("The value of c is %d and value of d is %d\n", c, d);

    // Assignment works from right to left, so every variable receives 25.
    a = b = c = d = 25;

    // The variables were already declared above, so 'int' is not written again.
    printf("Values:\na = %d\nb = %d\nc = %d\nd = %d\n", a, b, c, d);

    return 0;
}
