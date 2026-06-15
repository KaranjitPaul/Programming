/*
7. Write a program to display the ASCII value of a character and identify
whether it is a lowercase letter, uppercase letter, digit, or another symbol.
*/

#include <stdio.h>

int main(void) {
    char ch;

    printf("Enter a character: ");
    scanf(" %c", &ch);

    // %d displays the numeric ASCII value stored for the character.
    printf("Character: %c\nASCII value: %d\n", ch, ch);

    if (ch >= 'a' && ch <= 'z') {
        printf("It is a lowercase letter.\n");
    } else if (ch >= 'A' && ch <= 'Z') {
        printf("It is an uppercase letter.\n");
    } else if (ch >= '0' && ch <= '9') {
        printf("It is a digit.\n");
    } else {
        printf("It is another ASCII symbol.\n");
    }

    return 0;
}
