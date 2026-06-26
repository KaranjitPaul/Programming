#include <stdio.h>

int main() {
    char firstName[20];
    char lastName[20];

    // scanf with %s reads only one word. It stops at space.
    printf("Enter first name: ");
    scanf("%19s", firstName);

    printf("Enter last name: ");
    scanf("%19s", lastName);

    printf("Your full name: %s %s\n", firstName, lastName);

    return 0;
}
