//02valueAtAddressOperator.c
#include <stdio.h>

int main() {
    int i = 72;
    int *j = &i; // j is a pointer pointing to i
    // Spaces around * do not change the meaning.

    printf("The value at address in pointer j: %d\n", *j);
    printf("The address stored in j: %p\n", *(&j));
    printf("The value at i: %d\n", *(&i));    // *(&i) == i

    return 0;
}
