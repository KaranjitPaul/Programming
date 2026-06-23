#include<stdio.h>

int main(){
    int arr[3] = {12, 15, 36};
    for (int i = 0; i < 3; i++)
        printf("Address(%d): %p\n", i, &arr[i]);  //continous address differ by int size like in this case 4

    //Tips: int* a = &arr[0] and int* a = arr are same
    int* a = &arr[1];
    ++a;

    printf("a = &arr[1]; *(++a) == arr[2] : %d", *a);
    //address stored in pointer a increement by int memory size

    return 0;
}
/*
OUTPUT:
Address(1): 0061FF10
Address(2): 0061FF14
Address(3): 0061FF18
*/