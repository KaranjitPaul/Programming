/*
6. Write a program to find the greatest of four numbers entered by the user.
*/

#include <stdio.h>

int main(void) {
    int first, second, third, fourth;

    printf("Enter number 1: ");
    scanf("%d", &first);
    printf("Enter number 2: ");
    scanf("%d", &second);
    printf("Enter number 3: ");
    scanf("%d", &third);
    printf("Enter number 4: ");
    scanf("%d", &fourth);

    // Nested ternary operators work here, but they become harder to read as values increase.
    int greatest = first > second
        ? (first > third ? first : third)
        : (second > third ? second : third);

    greatest = greatest > fourth ? greatest : fourth;

    printf("Greatest number: %d\n", greatest);

    return 0;
}
