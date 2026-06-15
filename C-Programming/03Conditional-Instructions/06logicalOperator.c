#include <stdio.h>

int main(void) {
    int working_age = 35;
    int retirement_age = 68;

    // && is true only when both conditions are true.
    if (working_age >= 18 && working_age < 60) {
        printf("%d is between 18 and 59\n", working_age);
    }

    // || is true when at least one condition is true.
    if (retirement_age < 18 || retirement_age >= 60) {
        printf("%d is outside the working-age range\n", retirement_age);
    }

    // ! reverses a condition: true becomes false and false becomes true.
    if (!(retirement_age < 60)) {
        printf("%d is not less than 60\n", retirement_age);
    }

    return 0;
}
