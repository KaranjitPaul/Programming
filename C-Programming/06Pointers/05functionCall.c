#include <stdio.h>

int sum_by_value(int a, int b) {
    a = 5;

    return a + b;
}

int sum_by_reference(int *a, int *b) {
    *a = 10;

    return *a + *b;
}

int main() {
    int a = 2;
    int b = 6;

    printf("Call by value, sum: %d\n", sum_by_value(a, b));
    printf("a = %d\n", a);
    // a does not change because the function received only a copy.

    printf("Call by reference, sum: %d\n", sum_by_reference(&a, &b));
    printf("a = %d\n", a);
    // a changes because the function worked with the address of a.

    return 0;
}
