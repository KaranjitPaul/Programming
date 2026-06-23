/*
1. Create an array of 10 numbers. Verify using pointer arithmetic that (ptr + 2)
points to the third element where ptr is a pointer pointing to the first element
of the array.
*/
#include <stdio.h>

int main() {
    int arr[10] = {12, 45, 151, 87, 77, 65, 48, 71, 78, 95};
    int *ptr = arr;

    printf("Value at ptr == arr[0]: %d\n", *ptr);
    printf("Value at (ptr + 2) == arr[2]: %d\n", *(ptr + 2));

    return 0;
}
