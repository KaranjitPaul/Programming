/*
2. Write a program to determine whether a student has passed or failed. To pass,
a student requires a total of 40% and at least 33% in each of three subjects.
Take the marks as input from the user.
*/

#include <stdio.h>

int main(void) {
    int math, science, social_science;

    printf("Enter your marks:\nMaths: ");
    scanf("%d", &math);
    printf("Science: ");
    scanf("%d", &science);
    printf("Social Science: ");
    scanf("%d", &social_science);

    float percentage = (math + science + social_science) / 3.0f;

    // Failing either the total requirement or one subject means failing overall.
    if (percentage < 40 || math < 33 || science < 33 || social_science < 33) {
        printf("You failed with %.2f%%.\n", percentage);
    } else {
        printf("You passed with %.2f%%.\n", percentage);
    }

    return 0;
}
