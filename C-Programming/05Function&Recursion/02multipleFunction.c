/*
Write a program with three functions:
1. Good morning function which prints "good morning".
2. Good afternoon function which prints "good afternoon".
3. Good night function which prints "good night".

main() should call all of these in order: 1 -> 2 -> 3.
*/

#include <stdio.h>

void morning(); // Declarations make the function names known before main().
void noon();
void night();

int main() {
    morning();
    noon();
    night();

    return 0;
}

void morning() {
    printf("Good Morning! Myself Karanjit\n");
}

void noon() {
    printf("Good Afternoon! Myself Karanjit\n");
}

void night() {
    printf("Good Night!\n");
}
