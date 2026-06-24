#include<stdio.h>

int main(){
    char str[] = "Cant be re-initialized";

    char *canChange;  //can be reinitialized if initialized using pointer
    canChange = "Karanjit";

    printf("original string: %s\n", canChange);
    canChange = "Paul";
    printf("Re-initialized string: %s", canChange);

    return 0;
}