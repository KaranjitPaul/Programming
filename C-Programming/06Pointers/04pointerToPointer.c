#include <stdio.h>

int main() {
    int i = 72;
    int *j = &i;
    int **k = &j;

    printf("The value at address in pointer j: %d\n", *j);
    printf("The address of j: %p\n", &j);

    // k stores the address of j.
    printf("Value at address in pointer k: %p\n", *k);
    printf("Value of i using pointer to pointer k: %d\n", **k);

    return 0;
}
