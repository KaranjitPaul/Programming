#include<stdio.h>

int main(){
    
    char firstName[20];
    char lastName[20];

    //scanf can take one word input in single scanf, also means no spaces
    printf("Enter first name: ");
    scanf("%s", &firstName);
    printf("Enter last name: ");
    scanf("%s", &lastName);

    printf("Your full name: %s %s", firstName, lastName);

    return 0;
}