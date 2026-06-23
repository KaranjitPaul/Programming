//5. Write a program containing a function which reverses the array passed to it.
#include <stdio.h>

void reverseArray(int arr[], int size) {
    for (int i = 0, j = size - 1; i < j; i++, j--) {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

int main() {
    int arr[5] = {12, 43, 84, 97, 17};

    printf("Before reverse: ");
    for (int i = 0; i < 5; i++)
        printf("%d\t", arr[i]);

    reverseArray(arr, 5);

    printf("\nAfter reverse: ");
    for (int i = 0; i < 5; i++)
        printf("%d\t", arr[i]);

    printf("\n");

    return 0;
}
