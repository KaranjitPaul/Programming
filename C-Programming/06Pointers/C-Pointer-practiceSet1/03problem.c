//3. Write a program to change the value of a variable to ten times of its current value.
#include <stdio.h>

void tenTimes(int *num) {
    *num *= 10;
}

int main() {
    int value = 12;

    printf("Initial value: %d\n", value);
    tenTimes(&value);
    printf("Value after ten times: %d\n", value);

    return 0;
}
