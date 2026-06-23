/*
2. If S[3] is a 1-D array of integers, then *(S + 3) refers to the third element:
(i) True.
(ii) False. ---> correct, third element is *(S + 2)
(iii) Depends.
*/
#include <stdio.h>

int main() {
    int S[3] = {12, 32, 54};

    printf("Third element using S[2]: %d\n", S[2]);
    printf("Third element using *(S + 2): %d\n", *(S + 2));
    printf("*(S + 3) is outside the array, so we should not read it.\n");

    return 0;
}
