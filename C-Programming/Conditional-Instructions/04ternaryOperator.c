#include <stdio.h>

int main(void) {
    int a = 5;
    int b = 8;
    int c = 19;

    // A readable way to use the ternary operator one comparison at a time.
    int biggest_number = a > b ? a : b;
    biggest_number = biggest_number > c ? biggest_number : c;
    printf("Biggest number: %d\n", biggest_number);

    // Nested ternary operators work, but they are harder to read.
    int largest = a > b ? (a > c ? a : c) : (b > c ? b : c);
    printf("Using a nested ternary: %d\n", largest);

    return 0;
}
