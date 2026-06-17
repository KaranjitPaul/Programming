// Use a library function to calculate the area of a square with side a.

#include <stdio.h>
#include <math.h> // For using pow()

int main(void) {
    int side_a = 7;
    double area = pow(side_a, 2); // pow() works like side_a to the power of 2.

    printf("The area of the square is: %.0f\n", area);

    return 0;
}
