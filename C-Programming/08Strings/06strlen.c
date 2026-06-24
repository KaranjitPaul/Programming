#include<stdio.h>
#include<string.h>  //will make a problem code using user defined function not library

int main(){
    char name[30];
    printf("Enter name: ");
    fgets(name, 30, stdin);

    printf("The length of the name is: %d", strlen(name));  //strlen counts ' '(spaces) too

    return 0;
}