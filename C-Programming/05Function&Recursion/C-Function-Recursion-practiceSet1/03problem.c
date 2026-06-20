//3. Write a function to calculate force of attraction on a body of mass 'm' exerted by earth. Consider g = 9.8m/s^2.
#include <stdio.h>

float force(float m) {
    return m * 9.8f;
}

int main() {
    float m = 75;

    printf("Force of attraction: %.2fN\n", force(m));

    return 0;
}
