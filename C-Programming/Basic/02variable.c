#include <stdio.h>

int main(void) {
    int a; // Declaring an integer variable
    a = 6; // Assigning a value after declaration

    float b = 2.5f; // Declaring and initializing a float
    char c = 'e'; // A single character uses single quotes

    printf("Integer: %d\n", a);
    printf("Float: %.1f\n", b);
    printf("Character: %c\n", c);

    return 0;
}

// Variable names can contain letters, digits, and underscores.
// They cannot start with a digit or use a C keyword.
// Variable names in C are case-sensitive.
