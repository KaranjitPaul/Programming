/*
2. What data type will 3.0 / 8 - 2 return?
*/

#include <stdio.h>

int main(void) {
    // 3.0 is a double, so the expression produces the double value -1.625.
    double exact_result = 3.0 / 8 - 2;

    // Storing that result in an int removes its decimal part.
    int integer_result = 3.0 / 8 - 2;

    printf("Expression result = %.3f\n", exact_result);
    printf("Result stored in int = %d\n", integer_result);

    return 0;
}
