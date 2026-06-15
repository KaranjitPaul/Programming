#include <stdio.h>

int main(void) {
    int num = 3;

    switch (num) {
        case 1:
            printf("The number is 1\n");
            break;
        case 2:
            printf("The number is 2\n");
            break;
        case 3:
            printf("The number is 3\n");
            break;
        case 4:
            printf("The number is 4\n");
            break;
        default:
            // default runs when none of the cases match.
            printf("The number is outside the range 1 to 4\n");
    }

    return 0;
}
