#include <stdio.h>

int main() {
    int age = 35;

    if (age >= 18) {
        printf("The person is 18 or older.\n");

        // This condition is checked only after the outer condition is true.
        if (age < 60) {
            printf("The person is also younger than 60.\n");
        }
    }

    return 0;
}
