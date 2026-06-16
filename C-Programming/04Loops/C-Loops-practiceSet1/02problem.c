// 2. Write a program to print the multiplication table of 10 in reverse order.

#include <stdio.h>

int main(void) {
    int num = 10;
    int i = 10;

    while (i > 0) {
        printf("%d x %d = %d\n", num, i, num * i);
        i--;
    }

    return 0;
}
