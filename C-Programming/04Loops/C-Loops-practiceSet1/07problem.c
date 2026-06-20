// 7. Repeat problem 6 using a while loop.

#include <stdio.h>

int main() {
    int num = 5;
    int original_num = num;
    int fact = 1;

    while (num > 0) {
        fact *= num;
        num--;
    }

    printf("Factorial of %d is: %d\n", original_num, fact);

    return 0;
}
