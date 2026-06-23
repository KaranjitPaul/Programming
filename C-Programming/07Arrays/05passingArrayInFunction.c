//PASSING ARRAY TO FUNCTIONS
#include<stdio.h>

void printMarks(int marksArray[], int arraySize){   //Also can be passed using pointers.
    for (int i = 0; i < arraySize; i++)
    {
        printf("Marks[%d] : %d\n", i, marksArray[i]);
    }
    
}
int main(){
    int marks[5];

    printf("Enter marks:\n");
    for(int i = 0; i < 5; i++)
        scanf("%d", &marks[i]);
    
    printMarks(marks, 5);

    return 0;
}