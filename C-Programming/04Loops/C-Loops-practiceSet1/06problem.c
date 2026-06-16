// 6. Write a program to calculate the factorial of a given number using a for loop.

#include <stdio.h>

int main(void) {
    int num = 5;
    int fact = 1;

    for (int i = num; i > 0; i--) {
        fact *= i;
    }

    printf("Factorial of %d is: %d\n", num, fact);

    return 0;
}
