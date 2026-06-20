/*
Write a program to calculate simple interest for a set of values representing
principal, number of years and rate of interest.
*/

#include <stdio.h>

int main() {
    int principal;
    int number_of_years;
    int rate;

    printf("Simple interest calculator\n");
    printf("Principal: ");
    scanf("%d", &principal);
    printf("Number of years: ");
    scanf("%d", &number_of_years);
    printf("Rate of Interest: ");
    scanf("%d", &rate);

    // Using 100.0f keeps the calculation as a floating-point calculation.
    float interest = principal * number_of_years * rate / 100.0f;
    float amount = principal + interest;

    printf("Your interest is: %.2f\n", interest);
    printf("Your total amount is: %.2f\n", amount);

    return 0;
}
