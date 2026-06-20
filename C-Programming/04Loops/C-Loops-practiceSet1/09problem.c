// 9. Implement problem 8 using while and do...while loops.

#include <stdio.h>

int main() {
    int num;
    int is_prime = 1;
    int i = 2;

    printf("Enter number to check whether it is prime or not: ");
    scanf("%d", &num);

    if (num < 2) {
        is_prime = 0;
    }

    while (i * i <= num && is_prime) {
        if (num % i == 0) {
            is_prime = 0;
            break;
        }
        i++;
    }

    printf("Using while loop:\n");
    if (is_prime) {
        printf("Yes, it is a prime number.\n");
    } else {
        printf("No, it is not a prime number.\n");
    }

    is_prime = 1;
    i = 2;

    if (num < 2) {
        is_prime = 0;
    } else if (i * i <= num) {
        do {
            if (num % i == 0) {
                is_prime = 0;
                break;
            }
            i++;
        } while (i * i <= num);
    }

    printf("Using do...while loop:\n");
    if (is_prime) {
        printf("Yes, it is a prime number.\n");
    } else {
        printf("No, it is not a prime number.\n");
    }

    return 0;
}
