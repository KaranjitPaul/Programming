#include <stdio.h>

int main() {
    // A string in C is a char array that ends with '\0'.
    char s[] = {'H', 'E', 'L', 'L', 'O', '\0'};

    // In double quotes, C adds '\0' automatically.
    char s2[] = "WORLD!";

    printf("%s ", s);
    printf("%s\n", s2);

    return 0;
}
