//6. Try problem 3 using call by value and verify that it does not change the value of the said variable.
#include <stdio.h>

int tenTimes(int num) {
    return num * 10;
}

int main() {
    int value = 12;

    printf("Initial value: %d\n", value);
    printf("Ten times value: %d\n", tenTimes(value));
    printf("After function call, original value: %d\n", value);
    // The real value does not change because this is call by value.

    return 0;
}
