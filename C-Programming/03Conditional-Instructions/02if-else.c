#include <stdio.h>

int main() {
    int age = 17;

    // Exactly one of these two blocks will run.
    if (age >= 18) {
        printf("You are an adult\n");
    } else {
        printf("You are not an adult\n");
    }

    return 0;
}
