/*
5. Write a program to determine whether a character entered by the user is
lowercase or not.
*/

#include <stdio.h>

int main(void) {
    char ch;

    printf("Enter a character: ");
    scanf(" %c", &ch);

    // Character ranges are clearer than writing their ASCII numbers directly.
    if (ch >= 'a' && ch <= 'z') {
        printf("%c is lowercase.\n", ch);
    } else {
        printf("%c is not lowercase.\n", ch);
    }

    return 0;
}
