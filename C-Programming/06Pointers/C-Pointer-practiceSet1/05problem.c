//5. Write a program to print the value of a variable i by using pointer to pointer type of variable.
#include <stdio.h>

int main() {
    int i = 24;
    int *ptr = &i;
    int **ptr1 = &ptr;

    printf("Value using pointer to pointer: %d\n", **ptr1);

    return 0;
}
