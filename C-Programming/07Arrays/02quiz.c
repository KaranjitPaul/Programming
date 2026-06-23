//Write a program to accept marks of five students in an array and print them on the screen.
#include<stdio.h>

int main(){
    int student[5];

    for (int i = 0; i < 5; i++)
    {
        printf("Enter student(%d) marks: ", i+1);
        scanf("%d", &student[i]);
    }
    for (int i = 0; i < 5; i++)
        printf("Student(%d) marks: %d\n", i+1, student[i]);
    
    return 0;
}