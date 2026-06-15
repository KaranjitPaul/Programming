/*
Write a program to convert Celsius temperature to Fahrenheit.
*/

#include <stdio.h>

int main(void) {
    float celsius;
    float fahrenheit;

    printf("Enter the temperature in Celsius: ");
    scanf("%f", &celsius);

    fahrenheit = (celsius * 1.8f) + 32;
    printf("%.2f C in Fahrenheit is %.2f F\n", celsius, fahrenheit);

    return 0;
}
