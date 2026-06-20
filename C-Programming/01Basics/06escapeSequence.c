#include <stdio.h>

int main() {
    // \n starts a new line.
    printf("NEW LINE\n");
    printf("Hello\nWorld\n");

    // \t adds a horizontal tab space.
    printf("\nTAB\n");
    printf("Name\tAge\n");
    printf("Karan\t20\n");

    // \" prints double quotes inside a string.
    printf("\nDOUBLE QUOTES\n");
    printf("He said, \"Hello\".\n");

    // \\ prints one backslash.
    printf("\nBACKSLASH\n");
    printf("C:\\Users\\Karan\n");

    // \0 marks the end of a string.
    // printf stops printing when it reaches \0.
    printf("\nNULL CHARACTER\n");
    printf("Hello\0World\n");

    return 0;
}
