# C Basics

These notes follow the C programs I have written so far:

- [01helloWorld.c](01helloWorld.c)
- [02variable.c](02variable.c)
- [03dataTypes.c](03dataTypes.c)

They explain the ideas used in those programs without moving ahead of the code.

## What Is C?

C is a general-purpose programming language developed by Dennis Ritchie at Bell Labs in the early 1970s. It was closely connected to the development of the Unix operating system.

C gives a programmer a lot of control over how a program uses the computer. It is still widely used for operating systems, embedded systems, compilers, and other software where performance and low-level control matter.

Many later languages borrowed C's syntax, so learning C also makes parts of languages such as C++, Java, and C# more familiar.

## Advantages Of C

- C programs can be fast and use memory efficiently.
- The language is small enough to learn its core rules without learning a huge framework.
- It gives more control over the computer than many higher-level languages.
- C compilers are available on many systems.
- Learning C helps build an understanding of how programs work closer to the machine.

## Disadvantages Of C

- C gives the programmer a lot of responsibility.
- The language has fewer safety checks than many modern languages.
- Small mistakes can cause crashes or unexpected behavior.
- Some tasks require more manual work than they would in a higher-level language.
- Large C programs can become difficult to maintain without careful structure.

## From Source Code To A Running Program

A C source file usually ends with `.c`.

Writing the source file is only the first step. Before the computer can run it, the code goes through a few stages:

1. **Preprocessing** handles instructions that begin with `#`, such as `#include`.
2. **Compilation** translates the C code into lower-level code and checks for many errors.
3. **Linking** connects the compiled code with required library code.
4. **Running** starts the finished executable program.

The compiler used for the current programs is GCC.

## Preprocessor Directives

A preprocessor directive is an instruction handled before the main compilation step.

```c
#include <stdio.h>
```

The `#include` directive makes declarations from a header file available to the current source file.

Directives begin with `#` and do not end with a semicolon.

## Header Files And `stdio.h`

A header file usually contains declarations that tell the compiler about functions, types, and other names.

`stdio.h` means **standard input/output header**.

```c
#include <stdio.h>
```

It declares standard input and output functions, including `printf`.

`stdio.h` is a standard-library header, not the complete library implementation itself. The required library code is connected during linking.

Angle brackets are used for standard or system headers:

```c
#include <stdio.h>
```

## The `main` Function

```c
int main(void) {
    return 0;
}
```

Every current program starts running from `main`.

- `int` says that `main` returns an integer value.
- `main` is the function name.
- `void` says that this version of `main` does not receive arguments.
- `{` and `}` mark the function's body and scope.

The statements inside the braces run from top to bottom.

## Statements And Semicolons

A statement tells the program to perform an action.

```c
printf("Hello World\n");
```

Most C statements end with a semicolon:

```c
;
```

Preprocessor directives such as `#include` are not normal C statements, so they do not use semicolons.

## Using `printf`

`printf` prints formatted output to the terminal.

```c
printf("Hello World\n");
```

The text between double quotes is a string literal.

`\n` is a newline escape sequence. It moves the next output to a new line.

Because `printf` is declared in `stdio.h`, the program includes that header before using the function.

## Variables

A variable is a named place used to store a value.

### Declaration

A declaration introduces a variable and its type:

```c
int a;
```

This declares an integer variable named `a`.

### Assignment

Assignment gives a value to an existing variable:

```c
a = 6;
```

### Initialization

Initialization gives a variable its first value at the same time it is declared:

```c
float b = 2.5f;
```

Declaration followed by assignment:

```c
int a;
a = 6;
```

Declaration with initialization:

```c
int a = 6;
```

## Basic Data Types Used So Far

### `int`

`int` stores whole numbers.

```c
int a = 6;
```

### `float`

`float` stores numbers with a fractional part.

```c
float b = 2.5f;
```

The `f` suffix marks `2.5f` as a `float` literal.

### `char`

`char` stores one character.

```c
char c = 'e';
```

A single character uses single quotes.

## Basic Data Types

`03dataTypes.c` demonstrates the basic C data types learned so far:

| Data Type | Purpose |
| --- | --- |
| `char` | Stores one character |
| `int` | Stores a whole number |
| `float` | Stores a decimal number |
| `double` | Stores a decimal number with more precision than `float` |
| `void` | Represents no value |

For now, `void` can be seen inside `main(void)`. The `void` between the brackets means that `main` is not receiving any values.

Functions and other uses of `void` can be studied later.

## Checking Types And Sizes

`sizeof` reports how many bytes a variable or type uses on the current system:

```c
sizeof(int)
```

The size of a C type can differ between compilers and computers, so it is better to check instead of assuming.

`void` has no value, so `sizeof(void)` is not allowed in standard C.

## Single Quotes And Double Quotes

They have different meanings in C:

```c
char letter = 'e';
```

Single quotes represent one character.

```c
printf("Hello");
```

Double quotes represent a string literal, which is a sequence of characters.

Writing this is incorrect because `"e"` is a string, not one character:

```c
char letter = "e";
```

## Format Specifiers

Format specifiers tell `printf` what type of value to print.

```c
printf("Integer: %d\n", a);
printf("Float: %.1f\n", b);
printf("Character: %c\n", c);
```

The format specifiers used so far are:

| Specifier | Used For |
| --- | --- |
| `%d` | An integer |
| `%f` | A floating-point number |
| `%.1f` | A floating-point number shown with one digit after the decimal point |
| `%c` | One character |

The value after the comma replaces the matching format specifier in the output.

## Naming Variables

Variable names in C:

- Can contain letters, digits, and underscores
- Cannot begin with a digit
- Cannot be a C keyword
- Are case-sensitive

For example, `age`, `student_age`, and `score2` are valid names.

`score` and `Score` are treated as different names.

Meaningful names are usually better than single-letter names once a program becomes larger.

## Comments

Comments explain code and are ignored by the compiler.

A single-line comment begins with `//`:

```c
// This is a comment
```

Comments are useful when they explain why something is done or clarify a new idea. They do not need to repeat every obvious line.

## Returning From `main`

```c
return 0;
```

`main` has an `int` return type, so it returns an integer.

Returning `0` tells the operating system that the program finished successfully.

## Lessons So Far

- A C program starts from `main`.
- `#include <stdio.h>` makes the declaration of `printf` available.
- `printf` displays formatted output.
- Variables have types that describe the kind of value they store.
- Declaration, assignment, and initialization are related but different.
- Single quotes are for one character; double quotes are for strings.
- Format specifiers must match the values being printed.
- Compiler warnings can reveal mistakes even when a program still runs.
