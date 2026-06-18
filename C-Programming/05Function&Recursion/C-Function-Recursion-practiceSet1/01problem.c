//1. Write a program using function to find average of three numbers.
#include <stdio.h>

float average(int num1, int num2, int num3) {
    return (num1 + num2 + num3) / 3.0f;
}

int main(void) {
    int a = 12;
    int b = 8;
    int c = 15;

    printf("Their average: %.2f\n", average(a, b, c));

    return 0;
}
