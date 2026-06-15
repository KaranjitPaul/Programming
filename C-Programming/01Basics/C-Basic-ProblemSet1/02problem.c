/*
Calculate the area of a circle and modify the same program to calculate the
volume of a cylinder given its radius and height.
*/

#include <stdio.h>

#define PI 3.1415

int main(void) {
    int radius = 7;
    int height = 10;

    printf("Area of circle: %.2f\n", PI * radius * radius);
    printf("Volume of cylinder: %.2f\n", PI * radius * radius * height);

    return 0;
}
