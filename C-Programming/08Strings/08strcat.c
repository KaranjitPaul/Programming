#include<stdio.h>
#include<string.h>

int main(){
    char firstName[] = "Karanjit";
    char lastName[] = " Paul";

    strcat(firstName, lastName);

    printf("Full name: %s", firstName);

    return 0;
}