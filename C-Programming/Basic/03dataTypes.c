#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>

struct Student {
    int roll_number;
    char grade;
};

union Number {
    int whole_number;
    float decimal_number;
};

enum Day {
    MONDAY,
    TUESDAY,
    WEDNESDAY
};

// This function prints the variable name, detected type, and size.
void show_type_and_size(const char *name, const char *type, size_t size) {
    printf("%-22s %-24s %2zu byte%s\n", name, type, size, size == 1 ? "" : "s");
}

// _Generic checks the type while the code is being compiled.
#define TYPE_NAME(value) _Generic((value), \
    _Bool: "_Bool / bool", \
    char: "char", \
    signed char: "signed char", \
    unsigned char: "unsigned char", \
    short: "short", \
    unsigned short: "unsigned short", \
    int: "int", \
    unsigned int: "unsigned int", \
    long: "long", \
    unsigned long: "unsigned long", \
    long long: "long long", \
    unsigned long long: "unsigned long long", \
    float: "float", \
    double: "double", \
    long double: "long double", \
    int *: "pointer to int", \
    void (*)(void): "pointer to function", \
    struct Student: "struct Student", \
    union Number: "union Number", \
    default: "another type" \
)

// This saves us from writing the variable name, type, and sizeof every time.
#define SHOW_TYPE(value) show_type_and_size(#value, TYPE_NAME(value), sizeof(value))

void greet(void) {
    printf("The function pointer called greet().\n");
}

int main(void) {
    // Basic integer types
    bool is_learning = true;
    char letter = 'C';
    signed char signed_small_number = -10;
    unsigned char unsigned_small_number = 250;
    short short_number = -32000;
    unsigned short unsigned_short_number = 65000;
    int integer_number = -100;
    unsigned int unsigned_integer_number = 100U;
    long long_number = -100000L;
    unsigned long unsigned_long_number = 100000UL;
    long long very_long_number = -10000000000LL;
    unsigned long long unsigned_very_long_number = 10000000000ULL;

    // Floating-point types
    float decimal_number = 2.5f;
    double precise_decimal_number = 2.5;
    long double very_precise_decimal_number = 2.5L;

    // Derived and user-defined types
    int numbers[3] = {10, 20, 30};
    int *number_pointer = numbers;
    struct Student student = {1, 'A'};
    union Number number = {.whole_number = 25};
    enum Day today = WEDNESDAY;
    void (*function_pointer)(void) = greet;

    printf("BASIC DATA TYPES\n");
    printf("----------------\n");
    SHOW_TYPE(is_learning);
    SHOW_TYPE(letter);
    SHOW_TYPE(signed_small_number);
    SHOW_TYPE(unsigned_small_number);
    SHOW_TYPE(short_number);
    SHOW_TYPE(unsigned_short_number);
    SHOW_TYPE(integer_number);
    SHOW_TYPE(unsigned_integer_number);
    SHOW_TYPE(long_number);
    SHOW_TYPE(unsigned_long_number);
    SHOW_TYPE(very_long_number);
    SHOW_TYPE(unsigned_very_long_number);
    SHOW_TYPE(decimal_number);
    SHOW_TYPE(precise_decimal_number);
    SHOW_TYPE(very_precise_decimal_number);

    printf("\nDERIVED AND USER-DEFINED DATA TYPES\n");
    printf("-----------------------------------\n");

    // Arrays need a manual label because _Generic treats an array like a pointer.
    show_type_and_size("numbers", "array of 3 int", sizeof(numbers));
    SHOW_TYPE(number_pointer);
    SHOW_TYPE(student);
    SHOW_TYPE(number);

    // An enum is its own type, but the compiler stores it using an integer type.
    show_type_and_size("today", "enum Day", sizeof(today));
    SHOW_TYPE(function_pointer);

    printf("\nNO SIZE AVAILABLE\n");
    printf("-----------------\n");
    printf("void and function types cannot be used with sizeof in standard C.\n");

    printf("\nA FEW VALUES\n");
    printf("------------\n");
    printf("bool: %d, char: %c, int: %d, float: %.1f\n",
           is_learning, letter, integer_number, decimal_number);
    printf("array first value: %d, struct grade: %c, union value: %d, enum value: %d\n",
           numbers[0], student.grade, number.whole_number, today);

    function_pointer();

    return 0;
}
