#include <stdio.h>
#include <string.h>

int main() {
    // firstName needs extra space because strcat adds lastName into it.
    char firstName[30] = "Karanjit";
    char lastName[] = " Paul";

    // strcat joins lastName at the end of firstName.
    strcat(firstName, lastName);

    printf("Full name: %s\n", firstName);

    return 0;
}
