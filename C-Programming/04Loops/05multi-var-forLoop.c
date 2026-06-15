#include <stdio.h>

int main(void) {
    // Multiple variables can be initialized and updated in one for loop.
    for (int i = 0, j = 10; i < 10 && j > 1; i++, j--) {
        printf("i: %d,\tj: %d\n", i, j);
    }

    // With the comma operator, only the final expression decides the condition.
    //if use multiple condition use logical operator else if use ',' after conditions, only the last condition is only taken serious. i.e, if we reverse position from "i < 3, j > 5" to "j > 5, i < 3", now the program will care about i < 3 not j >5;
    for (int i = 0, j = 10; i < 3, j > 5; i++, j--) {
        printf("Comma condition -> i: %d,\tj: %d\n", i, j);
    }

    return 0;
}
