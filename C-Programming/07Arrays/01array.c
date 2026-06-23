#include<stdio.h>

int main(){
    int arr[2];
    arr[0] = 11;
    arr[1] = 22;
    
    int arr1[] = {33, 44, 55};
    int arr2[4] = {66, 77, 88};

    arr2[2] = 99;

    for(int i = 0; i<4; i++){
        if(i<2)
            printf("arr(%d): %d\n", i, arr[i]);
        if(i<3)
            printf("arr1(%d): %d\n", i, arr1[i]);
        printf("arr2(%d): %d\n", i, arr2[i]);
    }

    return 0;
}