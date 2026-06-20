#include <stdio.h>

int main() {
    int i = 72;
    int *j = &i;
    int **k = &j;
    int ***n = &k;

    printf("The value at address in pointer j: %d\n", *j);
    printf("The address of j: %p\n", &j);

    // k stores the address of j.
    printf("Value at address in pointer k: %p\n", *k);  // gives address of i
    printf("Value of i using pointer to pointer k: %d\n", **k); // gives value stored in i

    // n stores the address of k.
    printf("Value of i using **(&j): %d\n", **(&j));
    printf("Value of i using triple pointer n: %d\n", ***n);

    return 0;
}
