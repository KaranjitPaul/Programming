#include <stdio.h>

int main(void) {
    // The decimal part is removed when the double value is stored in an int.
    int num = 3.55;
    printf("Value stored in num: %d\n", num);

    // Casting changes num to float only while this expression is evaluated.
    printf("num after casting to float: %.2f\n", (float)num);

    return 0;
}
