#include <stdio.h>
#include <string.h>

int main() {
    char source[30];
    char target[30];

    printf("Enter string: ");
    fgets(source, 30, stdin);

    // strcpy copies source string into target.
    strcpy(target, source);

    printf("Copied string: %s", target);

    return 0;
}
