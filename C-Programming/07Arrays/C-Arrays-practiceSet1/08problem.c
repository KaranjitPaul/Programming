//8. Repeat problem 7 for a custom input given by the user.
#include <stdio.h>

int main() {
    int arr[3][10];
    int num[3];
    int times;

    printf("Enter 3 numbers for multiplication table:\n");
    for (int i = 0; i < 3; i++)
        scanf("%d", &num[i]);

    printf("Enter times up to 10: ");
    scanf("%d", &times);

    if (times > 10)
        times = 10; // each row has only 10 columns

    for (int i = 0; i < 3; i++)
        for (int j = 0; j < times; j++)
            arr[i][j] = num[i] * (j + 1);

    for (int i = 0; i < 3; i++) {
        printf("\nTable of %d:\n", num[i]);

        for (int j = 0; j < times; j++)
            printf("%d x %d = %d\n", num[i], j + 1, arr[i][j]);
    }

    return 0;
}
