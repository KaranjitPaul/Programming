/*
5. Write a program to calculate the sum of the numbers occurring in the
multiplication table of 8. Consider 8 x 1 to 8 x 10.
*/

#include <stdio.h>

int main(void) {
    int sum = 0;

    for (int i = 1; i <= 10; i++) {
        printf("8 x %d = %d\n", i, 8 * i);
        sum += 8 * i;
    }

    printf("The sum of products is: %d\n", sum);

    return 0;
}
