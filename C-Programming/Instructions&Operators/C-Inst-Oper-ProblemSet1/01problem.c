/*
1. Which of the following is invalid in C?
a. int a = 1; int b = a;
b. int v = 3 * 3;
c. char dt = '21 dec 2020';
*/

#include <stdio.h>

int main(void) {
    int a = 1;
    int b = a;
    int v = 3 * 3;

    // This is invalid because char can store only one character.
    // char dt = '21 dec 2020';

    printf("b = %d and v = %d\n", b, v);

    return 0;
}
