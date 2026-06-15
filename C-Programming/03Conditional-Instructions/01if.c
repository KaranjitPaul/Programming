#include <stdio.h>

int main(void) {
    int age = 14;

    // Each if condition is checked separately.
    if (age > 10) {
        printf("Your age is greater than 10\n");
    }

    if (age < 18) {
        printf("Your age is less than 18\n");
    }

    return 0;
}
