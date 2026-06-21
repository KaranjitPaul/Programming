//4. Write a program using a function which calculates the sum and average of two numbers. Use pointers and print the values of sum and average in main().
#include <stdio.h>

void calculate(int a, int b, int *sum, float *average) {
    *sum = a + b;
    *average = *sum / 2.0f;
}

int main() {
    int a = 78;
    int b = 12;
    int numSum;
    float numAverage;

    calculate(a, b, &numSum, &numAverage);

    printf("Sum: %d\n", numSum);
    printf("Average: %.2f\n", numAverage);

    return 0;
}
