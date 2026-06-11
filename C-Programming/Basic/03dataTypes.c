#include <stdio.h>

// This function prints the sizes received from main().
void show_sizes(int char_size, int int_size, int float_size, int double_size) {
    printf("char takes %d byte(s)\n", char_size);
    printf("int takes %d byte(s)\n", int_size);
    printf("float takes %d byte(s)\n", float_size);
    printf("double takes %d byte(s)\n", double_size);
}

// void means this function does not return any value.
void show_message(void) {
    printf("\nThese sizes can change depending on the computer and compiler.\n");
}

int main(void) {
    char character = 'C';       // Stores a single character
    int whole_number = 25;      // Stores a whole number
    float decimal_number = 2.5f; // Stores a decimal number
    double precise_number = 2.5; // Stores a decimal with more precision

    printf("VALUES\n");
    printf("------\n");
    printf("char: %c\n", character);
    printf("int: %d\n", whole_number);
    printf("float: %f\n", decimal_number);
    printf("double: %f\n", precise_number);

    printf("\nSIZES\n");
    printf("-----\n");
    show_sizes(
        (int)sizeof(char),
        (int)sizeof(int),
        (int)sizeof(float),
        (int)sizeof(double)
    );

    // void has no value, so its size cannot be checked using sizeof.
    show_message();

    return 0;
}
