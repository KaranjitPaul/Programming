#include <stdio.h>
#include <string.h>

int main() {
    char name[30];

    printf("Enter name: ");
    fgets(name, 30, stdin);

    // strlen counts characters before '\0'. If fgets stores '\n', that is counted too.
    printf("The length of the name is: %lu\n", (unsigned long)strlen(name));

    return 0;
}
