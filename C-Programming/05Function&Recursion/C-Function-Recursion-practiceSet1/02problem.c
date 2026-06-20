//2. Write a function to convert Celsius temperature into Fahrenheit.
#include <stdio.h>

float celsiusToFahrenheit(float temp) {
    return (temp * 9 / 5) + 32;
}

int main() {
    float celsius = 0;

    printf("Fahrenheit of %.2fC is: %.2f\n", celsius, celsiusToFahrenheit(celsius));

    return 0;
}
