//4. Write a program using recursion to calculate nth element of Fibonacci series.
#include <stdio.h>

int fibonacci(int n) {
    // Here 1st term is 0 and 2nd term is 1.
    if (n == 1) {
        return 0;
    } else if (n == 2) {
        return 1;
    }

    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main(void) {
    int n;

    printf("Enter the nth term: ");
    scanf("%d", &n);

    if (n < 1) {
        printf("Term cannot be 0 or less than 0\n");
        return 0;
    }

    printf("Fib %dth term: %d\n", n, fibonacci(n));

    return 0;
}
