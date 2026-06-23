//MULTIDIMENSIONAL ARRAYS
#include<stdio.h>

int main(){
    //1-D Array
    int arr1[3] = {12, 24, 35};
    //2-D Array
    int arr2[2][3] = {{24, 54, 42},{34, 45, 75}};
    //3-D Array
    int arr3[2][3][2] = {{{2, 4},{5, 6},{7, 8}}, {{9, 10},{11, 12},{13, 14}}};

    printf("1-D ARRAY: \n");
    for (int i = 0; i < 3; i++)
        printf("arr1[%d]: %d\n", i, arr1[i]);
    
    //2-D Array
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 3; j++)
            printf("arr2[%d][%d]: %d\n", i, j, arr2[i][j]);
        
    //3-D Array
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 3; j++)
            for (int k = 0; k < 2; k++)
                printf("arr3[%d][%d][%d]: %d\n", i, j, k, arr3[i][j][k]);
            
    return 0;
}   