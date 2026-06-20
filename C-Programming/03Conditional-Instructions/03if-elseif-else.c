#include <stdio.h>

int main() {
    int age = 19;

    // Conditions are checked from top to bottom until one is true.
    if (age < 14) {
        printf("You are a child\n");
    } else if (age < 18) {
        printf("You are a teenager\n");
    } else {
        printf("You are an adult\n");
    }

    return 0;
}
