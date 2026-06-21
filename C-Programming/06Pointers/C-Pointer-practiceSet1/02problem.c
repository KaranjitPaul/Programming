//2. Write a program having a variable 'i'. Print the address of 'i'. Pass this variable to a function and print its address. Are these addresses same? Why?
#include <stdio.h>

void address(int i) {
    printf("Address of i in function: %p\n", &i);
}

int main() {
    int i = 5;

    printf("Original address of i in main: %p\n", &i);
    address(i);

    // The addresses are different because the function receives a copy of i.
    // Same name does not mean same memory location.

    return 0;
}
