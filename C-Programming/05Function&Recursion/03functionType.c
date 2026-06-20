#include <stdio.h>

void display_message() {
    // Type 1: no return value and no parameters.
    printf("Type 1: no return value and no parameters.\n");
}

int sum(int a, int b) {
    // Type 2: returns a value and takes parameters.
    return a + b; // A function returns one value at a time.
}

void print_char(char a) {
    // Type 3: no return value, but takes a parameter.
    printf("Type 3 character is: %c\n", a);
}

float pi() {
    // Type 4: returns a value, but takes no parameters.
    return 3.145f;
}

int main() {
    int num1 = 25;
    int num2 = 20;
    int sum_of_num = sum(num1, num2);

    display_message();

    printf("Type 2 sum of numbers: %d\n", sum_of_num);
    printf("Type 2 direct call: %d\n", sum(num1, num2));

    print_char('c'); // Values can be passed directly; a variable is not always needed.

    printf("Type 4 pi value: %.3f\n", pi());

    return 0;
}
