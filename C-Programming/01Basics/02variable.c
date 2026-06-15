#include <stdio.h>

int main(void) {
    int a; // Declaring an integer variable
    a = 6; // Assigning a value after declaration

    // A decimal value is a double by default. The f makes this value a float.
    float b = 2.522f;

    char c = 'e'; // Declaring a variable with its first value is initialization

    printf("Integer: %d\n", a);
    printf("Float: %f\n", b); // Using %.2f would print only 2 digits after the decimal point
    printf("Character: %c\n", c);

    return 0;
}

// Variable names can contain letters, digits, and underscores.
// They cannot start with a digit or use a C keyword.
// Variable names in C are case-sensitive.
