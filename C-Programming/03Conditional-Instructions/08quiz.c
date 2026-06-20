#include <stdio.h>

int main() {
    /*
    Quick Quiz: Find a student's grade from their marks:
        90 - 100 => A
        80 - 89  => B
        70 - 79  => C
        60 - 69  => D
        50 - 59  => E
        Below 50 => F
    */
    char grade;
    int marks = 46;

    // After one condition is true, the remaining else-if conditions are skipped.
    if (marks > 100 || marks < 0) {
        printf("Marks must be between 0 and 100.\n");
        return 0;
    } else if (marks >= 90) {
        grade = 'A';
    } else if (marks >= 80) {
        grade = 'B';
    } else if (marks >= 70) {
        grade = 'C';
    } else if (marks >= 60) {
        grade = 'D';
    } else if (marks >= 50) {
        grade = 'E';
    } else {
        grade = 'F';
    }

    printf("Marks: %d\nGrade: %c\n", marks, grade);

    return 0;
}
