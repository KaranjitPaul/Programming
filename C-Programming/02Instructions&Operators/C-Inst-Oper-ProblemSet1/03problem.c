/*
3. Write a program to check whether a number is divisible by 97 or not.
*/

#include <stdio.h>

int main(void) {
    int num;

    printf("Enter a number: ");
    scanf("%d", &num);

    // A remainder of 0 means the entered number is divisible by 97.
    printf("Remainder after division by 97: %d\n", num % 97);

    return 0;
}
