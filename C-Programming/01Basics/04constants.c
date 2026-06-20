#include <stdio.h>

// #define creates a named constant before the code is compiled.
#define COURSE_NAME "C Programming"
#define MAX_SCORE 100

int main() {
    // const means these variables should not change after initialization.
    const int DAYS_IN_WEEK = 7;
    const float PI = 3.14159f;
    const char PASSING_GRADE = 'C';

    printf("Course: %s\n", COURSE_NAME);
    printf("Maximum score: %d\n", MAX_SCORE);
    printf("Days in a week: %d\n", DAYS_IN_WEEK);
    printf("Value of PI: %.5f\n", PI);
    printf("Passing grade: %c\n", PASSING_GRADE);

    // DAYS_IN_WEEK = 8; // This would give an error because DAYS_IN_WEEK is const.

    return 0;
}
