#include <stdio.h>

int main() {
    char name[100];

    printf("Enter name: ");
    // fgets reads at most size - 1 characters, then stores '\0'.
    fgets(name, 10, stdin);

    // printf prints exactly what we ask. Here we manually add '\n'.
    printf("%s\n", name);

    // puts prints the string and then adds a newline by itself.
    puts(name);

    return 0;
}
