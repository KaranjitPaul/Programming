#include <stdio.h>

int main() {
    for (int i = 0; i < 10; i++) {
        if (i == 5) {
            continue; // Skip the rest of this iteration.
        }

        if (i == 7) {
            break; // Exit the loop completely.
        }

        printf("i is: %d\n", i);
    }

    return 0;
}
