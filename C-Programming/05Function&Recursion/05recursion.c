#include <stdio.h>

int factorial(int num) {
    // Recursion means a function calls itself to solve a smaller version of the same problem.
    if (num < 0) {
        printf("Wrong input. Factorial cannot be calculated for a negative number.\n");
        return 0;
    } else if (num <= 1) {
        return 1;
    }

    return num * factorial(num - 1);
}

int main(void) {
    
    printf("Factorial of 5 is: %d\n", factorial(5));

    return 0;
}
