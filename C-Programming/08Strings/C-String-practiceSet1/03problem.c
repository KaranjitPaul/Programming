/*
Write a function slice() to slice a string. It should change the original string such that it is now the sliced string. Take ‘m’ and ‘n’ as the start and ending position for slice
*/
#include<stdio.h>
#include<string.h>


void slice(char *ch, int m, int n){
    char temp[20];
    for (int j = 0; m <= n; j++)
        temp[j] = ch[m++];
    temp[m] = '\0';
    strcpy(ch, temp);    
}

int main(){
    char str[20];
    int m, n;

    printf("Enter string: ");
    fgets(str, 20, stdin);  //include '\n'
    int size = strlen(str) - 1;

    do{
        printf("Enter slice index(m to n),\nm(0 to %d): ", size);
        scanf("%d", &m);
        if(m < 0 || m > size)
            printf("Invalid! index from 0 to %d\n", size);
    }
    while(m < 0 || m > size);

    do{
        printf("n: ");
        scanf("%d", &n);
        if(n < m || n > size)
            printf("Invalid! index from %d to %d, ", m, size);
    }
    while(n < m || n > size);

    slice(str, m, n);
    printf("Sliced string: %s", str);

    return 0;
}