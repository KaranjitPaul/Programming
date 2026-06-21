#include <stdio.h>

void swap(int *a, int *b) {
    // This changes the original variables because a and b store their addresses.
    *a = *a + *b;
    *b = *a - *b;
    *a = *a - *b;
}

int main() {
    int a = 10;
    int b = 12;

    printf("Before swap: a = %d ; b = %d\n", a, b);
    swap(&a, &b);
    printf("After swap: a = %d ; b = %d\n", a, b);

    return 0;
}
