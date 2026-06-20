#include <stdio.h>

int main() {
    int age; // This variable will store the age entered by the user

    printf("Enter your age: ");

    // %d tells scanf to read an integer.
    // &age gives scanf the address where it should store the entered value.
    scanf("%d", &age);

    printf("Your age: %d\n", age);

    return 0;
}
