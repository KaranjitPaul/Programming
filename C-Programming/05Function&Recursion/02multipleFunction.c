/*
Write a program with three functions:
1. Good morning function which prints "good morning".
2. Good afternoon function which prints "good afternoon".
3. Good night function which prints "good night".

main() should call all of these in order: 1 -> 2 -> 3.
*/

#include <stdio.h>

void morning(void); // Declarations make the function names known before main().
void noon(void);
void night(void);

int main(void) {
    morning();
    noon();
    night();

    return 0;
}

void morning(void) {
    printf("Good Morning! Myself Karanjit\n");
}

void noon(void) {
    printf("Good Afternoon! Myself Karanjit\n");
}

void night(void) {
    printf("Good Night!\n");
}
