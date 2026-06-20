#include <stdio.h>

int main() {
    // Multiple variables can be initialized and updated in one for loop.
    for (int i = 0, j = 10; i < 10 && j > 1; i++, j--) {
        printf("i: %d,\tj: %d\n", i, j);
    }

    // With the comma operator, only the final expression decides the condition.
    // Use logical operators for multiple real conditions.
    // If this becomes j > 5, i < 3, then only i < 3 controls the loop.
    for (int i = 0, j = 10; i < 3, j > 5; i++, j--) {
        printf("Comma condition -> i: %d,\tj: %d\n", i, j);
    }

    return 0;
}
