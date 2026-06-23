//6. Write a program containing function which counts the number of positive integers in an array.
#include <stdio.h>

int countPositive(int arr[], int size) {
    int count = 0;

    for (int i = 0; i < size; i++)
        if (arr[i] > 0)
            count++;

    return count;
}

int main() {
    int arr[] = {123, 56, -32, 0, -12, 76, -97};

    printf("Number of positive integers in the array: %d\n", countPositive(arr, 7));

    return 0;
}
