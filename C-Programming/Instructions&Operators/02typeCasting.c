#include <stdio.h>

int main(void) {
    // The decimal part is removed when the double value is stored in an int.
    int num = 3.55;
    printf("Value stored in num: %d\n", num);

    printf("num: %f\n", num);   //will give 0.000000

    // Casting changes num to float only while this expression is evaluated; Explicit type conversion
    printf("num after casting to float: %.2f\n", (float)num);

    return 0;
}
