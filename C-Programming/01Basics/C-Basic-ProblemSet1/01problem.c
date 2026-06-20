/*
1. Write a C program to calculate area of a rectangle:
    a. Using hard coded inputs.
    b. Using inputs supplied by the user
*/

#include <stdio.h>

int main() {
    // First calculation using values already written in the program.
    int length = 5;
    int breadth = 3;

    printf("Hard-coded input:\n");
    printf("Area of rectangle: %d\n", length * breadth);

    // Reusing the same variables with values supplied by the user.
    printf("\nUser input:\nLength: ");
    scanf("%d", &length);
    printf("Breadth: ");
    scanf("%d", &breadth);

    int area = length * breadth;
    printf("Area of rectangle: %d\n", area);

    return 0;
}
