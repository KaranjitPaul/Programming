//1. Write a program to take string as an input from the user using %c and %s confirm that the strings are equal.
#include<stdio.h>
#include<string.h>

int main(){
    char chStr[6];

    for(int i = 0; i < 5; i++){
        scanf("%c", &chStr[i]); //either have to use fflush(stdin) if user input char by char or user have to give whole char string together
        fflush(stdin);
    }
    chStr[5] = '\0';
    printf("String: %s", chStr);

    return 0;
}