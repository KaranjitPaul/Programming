#include <stdio.h>

int main() {
    int i = 10;

    // The body runs once before the condition is checked.
    do {
        printf("%d\n", i);
    } while (i < 10);

    return 0;
}
