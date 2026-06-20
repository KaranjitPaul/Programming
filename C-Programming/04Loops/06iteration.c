#include <stdio.h>

int main() {
    int a = 10;

    // Prefix changes the value before that value is used.
    printf("Starting value: %d\n", a);
    printf("Value produced by --a: %d\n", --a);
    printf("Value after --a: %d\n", a);

    // Postfix produces the old value, then changes the variable.
    printf("Value produced by a--: %d\n", a--);
    printf("Value after a--: %d\n", a);

    printf("Value produced by ++a: %d\n", ++a);
    printf("Value after ++a: %d\n", a);

    printf("Value produced by a++: %d\n", a++);
    printf("Value after a++: %d\n", a);

    return 0;
}
