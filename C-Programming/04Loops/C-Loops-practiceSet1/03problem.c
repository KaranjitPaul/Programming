// 3. Write a program to sum the first ten natural numbers using a while loop.

#include <stdio.h>

int main() {
    int n = 1;
    int sum = 0;

    while (n <= 10) {
        sum += n;
        n++;
    }

    printf("The sum of the first 10 natural numbers is: %d\n", sum);

    return 0;
}
