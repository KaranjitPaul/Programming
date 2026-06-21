//1. Write a program to print the address of a variable. Use this address to get the value of the variable.
#include <stdio.h>

int main() {
    int a = 12;
    int *b = &a;

    printf("Address of a using &a: %p\n", &a);
    printf("Address of a stored in b: %p\n", b);
    printf("Value at address stored in b: %d\n", *b);

    return 0;
}
