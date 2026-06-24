#include<stdio.h>

int main(){

    //Two types of initialiazation
    
    char s[] = {'H', 'E', 'L', 'L', 'O', '\0'}; //'\0' is added at the end to turn it into string
    char s2[] = {"WORLD!"}; //In this case '\0' automatically added

    printf("%s ", s);
    printf("%s", s2);

    return 0;
}