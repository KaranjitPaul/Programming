/*
1. What will be the output of this program?

int a = 10;
if (a = 11)
    printf("I am 11");
else
    printf("I am not 11");
*/

#include <stdio.h>

int main() {
    int a = 10;

    // This intentionally uses assignment instead of comparison.
    // It stores 11 in a, and the non-zero value 11 is treated as true.
    if ((a = 11)) {
        printf("I am 11\n");
    } else {
        printf("I am not 11\n");
    }

    return 0;
}
