#include<stdio.h>
#include<string.h>

int main(){
    char source[30], target[30];
    printf("Enter string: ");
    fgets(source, 30, stdin);

    strcpy(target, source);
    printf("String: %s", target);

    return 0;
}