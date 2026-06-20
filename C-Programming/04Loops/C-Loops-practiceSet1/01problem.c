// 1. Write a program to print the multiplication table of a given number n.

#include <stdio.h>

int main() {
    int n;

    printf("Enter the number to print its table: ");
    scanf("%d", &n);

    for (int i = 1; i <= 10; i++) {
        printf("%d x %d = %d\n", n, i, n * i);
    }

    return 0;
}
