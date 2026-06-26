#include <stdio.h>
#include <string.h>

int main() {
    char fullName[25];

    printf("Enter your name: ");
    // gets() is unsafe and removed from modern C, so fgets() is used instead.
    fgets(fullName, 25, stdin);

    // fgets may store the Enter key as '\n'. This removes it if present.
    fullName[strcspn(fullName, "\n")] = '\0';

    printf("Your name is ");
    puts(fullName); // puts prints the string and adds '\n' automatically.

    return 0;
}
