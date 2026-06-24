#include<stdio.h>

int main(){
    char name[100];
    printf("Enter name: ");
    fgets(name, 10, stdin); //takes input 1 less since stores '\0' in the end

    printf("%s\n", name);   //Hey GPT you take care of the use of printf and puts for string    though both work fine
    puts(name);

    return 0;
}