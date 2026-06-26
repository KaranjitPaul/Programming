#include <stdio.h>

int main() {
    char str[] = "Cant be re-initialized";
    printf("Array string: %s\n", str);

    // A pointer can point to one string literal, then later point to another.
    char *canChange;
    canChange = "Karanjit";

    printf("Original pointer string: %s\n", canChange);

    canChange = "Paul";
    printf("Re-initialized pointer string: %s\n", canChange);

    // str = "New text"; would not work because array name cannot be reassigned.

    return 0;
}
