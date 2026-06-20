#include <stdio.h>

int main() {
    int i = 72;
    int *j = &i;    // j is a pointer pointing to i; '&' means address of

    printf("The address of i: %p\n", &i);
    printf("The address of i stored in j: %p\n", j);
    printf("The address of j is: %p\n", &j);

    return 0;
}
