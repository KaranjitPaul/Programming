#include<stdio.h>

int main(){
    char fullName[25];
    printf("Enter your name: ");
    gets(fullName); //though use of gets is stopped(deprecated) and instead fgets is used

    printf("Your name is ");
    puts(fullName); //in the end add '\n' is added automatically

    return 0;
}