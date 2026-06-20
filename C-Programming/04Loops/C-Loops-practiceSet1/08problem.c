// 8. Write a program to check whether a given number is prime or not using loops.

#include <stdio.h>

int main() {
    int num;
    int is_prime = 1;

    printf("Enter number to check whether it is prime or not: ");
    scanf("%d", &num);

    if (num < 2) {
        is_prime = 0;
    }

    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            is_prime = 0;
            break;
        }
    }

    if (is_prime) {
        printf("Yes, it is a prime number.\n");
    } else {
        printf("No, it is not a prime number.\n");
    }

    return 0;
}
