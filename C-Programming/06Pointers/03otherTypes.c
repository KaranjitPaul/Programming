#include <stdio.h>

int main() {
    char i = 'a';
    char *j = &i;

    printf("The value at address in pointer j: %c\n", *j);
    printf("The address stored in j: %p\n", *(&j));
    printf("The value at i: %c\n", *(&i));    // *(&i) == i

    return 0;
}
