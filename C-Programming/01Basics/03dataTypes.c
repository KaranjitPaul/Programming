#include <stdio.h>

int main(void) {
    char character = 'C';       // Stores a single character
    int whole_number = 25;      // Stores a whole number
    float decimal_number = 2.5f; // Stores a decimal number
    double precise_number = 2.5; // Stores a decimal with more precision

    printf("VALUES\n"); // '\n' means new line
    printf("------\n");
    printf("char: %c\n", character);
    printf("int: %d\n", whole_number);
    printf("float: %f\n", decimal_number);
    printf("double: %f\n", precise_number);

    printf("\nSIZES\n");
    printf("-----\n");
    // sizeof returns size_t, so %zu is used to print the result.
    printf("char takes %zu byte(s)\n", sizeof(char));
    printf("int takes %zu byte(s)\n", sizeof(int));
    printf("float takes %zu byte(s)\n", sizeof(float));
    printf("double takes %zu byte(s)\n", sizeof(double));

    // void has no value, so its size cannot be checked using sizeof.
    printf("\nThese sizes can change depending on the computer and compiler.\n");

    return 0;
}
