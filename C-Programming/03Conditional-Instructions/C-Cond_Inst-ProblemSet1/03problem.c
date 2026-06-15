/*
3. Calculate income tax according to these slabs:
   2.5L - 5.0L: 5%
   5.0L - 10.0L: 20%
   Above 10.0L: 30%
There is no tax below 2.5L. Take income as input from the user.
*/

#include <stdio.h>

int main(void) {
    float income;
    float tax = 0.0f;

    printf("Please enter your income in lakh: ");
    scanf("%f", &income);

    // Each percentage applies only to the income inside that slab.
    if (income <= 2.5f) {
        tax = 0.0f;
    } else if (income <= 5.0f) {
        tax = (income - 2.5f) * 0.05f;
    } else if (income <= 10.0f) {
        tax = (2.5f * 0.05f) + (income - 5.0f) * 0.20f;
    } else {
        tax = (2.5f * 0.05f) + (5.0f * 0.20f) + (income - 10.0f) * 0.30f;
    }

    printf("Income tax: Rs. %.2f lakh\n", tax);

    return 0;
}
