//4. Repeat problem 3 for a general input provided by the user using scanf.
#include <stdio.h>

int main() {
    int array[10];
    int num;
    int times;

    printf("Enter the number for multiplication table: ");
    scanf("%d", &num);

    printf("Times up to 10: ");
    scanf("%d", &times);

    if (times > 10)
        times = 10; // array has only 10 spaces

    for (int i = 0; i < times; i++)
        array[i] = num * (i + 1);

    for (int i = 0; i < times; i++)
        printf("%d x %d = %d\n", num, i + 1, array[i]);

    return 0;
}
