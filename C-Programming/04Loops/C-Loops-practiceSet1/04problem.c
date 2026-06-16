// 4. Repeat problem 3 using for and do...while loops.

#include <stdio.h>

int main(void) {
    int sum = 0;

    for (int i = 1; i <= 10; i++) {
        sum += i;
    }
    printf("Using for loop: %d\n", sum);

    int num = 1;
    sum = 0;
    do {
        sum += num;
        num++;
    } while (num <= 10);
    printf("Using do...while loop: %d\n", sum);

    return 0;
}
