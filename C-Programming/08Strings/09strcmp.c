#include<stdio.h>
#include<string.h>

int main(){
    
    int leftSideFirst = strcmp("far", "joke");  //compare char to char based on ASCII
    int rightSideFirst = strcmp("joke", "far");
    int bothEqual = strcmp("far", "far");

    printf("Return value for leftSideFirst: %d\n", leftSideFirst);
    printf("Return value for rightSideFirst: %d\n", rightSideFirst);
    printf("Return value for bothEqual: %d\n", bothEqual);

    return 0;
}