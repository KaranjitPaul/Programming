#include <stdio.h>

void display(void); // Function declaration/prototype

int main(void) {
    display(); // Function call

    return 0;
}

void display(void) { // Function definition
    printf("Hello, I am Karanjit Paul.\n");
}

// display() is a user-defined function because we declared and defined it ourselves.
// printf() and scanf() are library functions declared through header files like stdio.h.
// Execution of a C program starts from main(). Other functions run when they are called.
