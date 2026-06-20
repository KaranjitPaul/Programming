#include <stdio.h>

int main() {
    int i = 0;

    // while checks the condition before every iteration.
    while (i < 10) {
        printf("%d. Hello World!\n", i + 1);
        i++; // Without this update, i remains 0 and the loop never ends.
    }

    return 0;
}
