//3. Write your own version of strlen function from <string.h>
#include<stdio.h>

int main(){
    char str[20];
    printf("Enter string: ");
    fgets(str, 20, stdin);

    int count = 0;
    for (int i = 0; str[i] != '\0'; i++)
        if(str[i] != '\0')
            count++;
    
    printf("Length: %d", --count);

    return 0;
}