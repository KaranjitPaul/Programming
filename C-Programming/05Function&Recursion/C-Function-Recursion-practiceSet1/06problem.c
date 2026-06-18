//6. Write a recursive function to calculate the sum of first 'n' natural numbers.
#include <stdio.h>

int naturalNumSum(int num) {
    if (num == 1) {
        return 1;
    }

    return num + naturalNumSum(num - 1);
}

int main(void) {
    int num = 10;

    printf("Sum of first %d natural numbers: %d\n", num, naturalNumSum(num));

    return 0;
}
