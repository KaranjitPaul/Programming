/*
7. Write a program using function to print the following pattern (first n lines)
*
* * *
* * * * *
*/
#include <stdio.h>

void pattern(int n) {
    for (int i = 1; i <= n; i++) {
        // Number of stars increases like 1, 3, 5, 7...
        // also possible nested loop--> for (int j = 1; j/2 < i; j++){....}
        for (int j = 1; j <= (2 * i - 1); j++) {
            printf("*\t");
        }

        printf("\n");
    }
}

int main() {
    int n = 0;

    printf("Enter n: ");
    scanf("%d", &n);

    pattern(n);

    return 0;
}
