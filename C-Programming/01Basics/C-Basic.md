# C Basics

Parent: [C Language](../C-Language.md)  
Previous: None  
Next: [C Instructions And Operators](../02Instructions&Operators/C-instructions_operators.md)

These notes follow the C programs I have written so far:

- [01helloWorld.c](01helloWorld.c)
- [02variable.c](02variable.c)
- [03dataTypes.c](03dataTypes.c)
- [04constants.c](04constants.c)
- [05input.c](05input.c)
- [06escapeSequence.c](06escapeSequence.c)
- [Basic Problem Set 1](C-Basic-ProblemSet1/)

They explain the ideas used in those programs without moving ahead of the code.

## Contents

- [Basic Problem Practice](#basic-problem-practice)
- [What Is C?](#what-is-c)
- [From Source Code To A Running Program](#from-source-code-to-a-running-program)
- [Preprocessor Directives](#preprocessor-directives)
- [Header Files And `stdio.h`](#header-files-and-stdioh)
- [The `main` Function](#the-main-function)
- [Using `printf`](#using-printf)
- [Taking Input With `scanf`](#taking-input-with-scanf)
- [Variables](#variables)
- [Basic Data Types](#basic-data-types)
- [Type Conversion](#type-conversion)
- [Format Specifiers](#format-specifiers)
- [Escape Sequences](#escape-sequences)
- [Constants](#constants)
- [C Keywords](#c-keywords)
- [Comments](#comments)
- [Lessons So Far](#lessons-so-far)

## Basic Problem Practice

The first problem set applies the basics learned so far:

- [Rectangle area](C-Basic-ProblemSet1/01problem.c) - hard-coded values and user input
- [Circle area and cylinder volume](C-Basic-ProblemSet1/02problem.c) - constants and calculations
- [Celsius to Fahrenheit](C-Basic-ProblemSet1/03problem.c) - input and floating-point calculation
- [Simple interest](C-Basic-ProblemSet1/04problem.c) - input, formulas, and readable variable names

These solutions are practice records. They can be improved as more C concepts are learned.

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

Writing the source file is only the first step. The computer cannot directly run C source code. It must first be translated into an executable program.

The compiler used for the current programs is GCC.

### What Is A Compiler?

A compiler is a program that translates source code written by humans into lower-level instructions that a computer can use.

While translating the code, the compiler also checks for many mistakes, such as:

- Incorrect syntax
- Using undeclared variables
- Passing the wrong kinds of values
- Other problems that can produce warnings or errors

An **error** usually stops the executable from being created. A **warning** means the compiler found something suspicious, but it may still create the executable.

### Compilation Process

When GCC builds a C program, the source code passes through these main stages:

1. **Preprocessing**
   - Handles directives beginning with `#`.
   - Includes header-file content and replaces simple `#define` names.
   - Produces expanded C source code.

2. **Compilation**
   - Checks the preprocessed C code.
   - Translates it into assembly language, which is closer to machine instructions.

3. **Assembly**
   - Translates the assembly code into machine-code instructions.
   - Produces an object file, commonly ending with `.o`.

4. **Linking**
   - Combines object files with required library code.
   - Connects calls such as `printf` to their implementations.
   - Produces the final executable file, such as an `.exe` file on Windows.

5. **Running**
   - The operating system loads the executable into memory.
   - The computer's CPU executes the program's machine instructions.
   - For the current programs, execution begins from `main`.

A simple view of the process:

```text
Source code (.c)
    -> Preprocessor
    -> Compiler
    -> Assembler
    -> Linker
    -> Executable (.exe)
    -> Running program
```

### Does The Compiler Execute Code Line By Line?

No. The compiler does not normally execute the C source code one line at a time.

The compiler reads and translates the program before it runs. It may process different parts in multiple stages and can even rearrange or optimize instructions while keeping the program's required behavior.

After compilation and linking, the finished executable is run. The CPU executes machine instructions, not the original C lines.

Inside a simple `main` function, statements usually appear to run from top to bottom:

```c
printf("First\n");
printf("Second\n");
```

Output:

```text
First
Second
```

Later, conditions, loops, and function calls can change which statements run and in what order.

### Basic GCC Commands

Compile a C source file into an executable:

```powershell
gcc 01helloWorld.c -o hello.exe
```

Run the executable in PowerShell:

```powershell
.\hello.exe
```

Compile while asking GCC to show useful warnings:

```powershell
gcc -Wall -Wextra -pedantic 01helloWorld.c -o hello.exe
```

Warnings are useful because a program can compile and run while still containing mistakes.

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

## Taking Input With `scanf`

`scanf` reads formatted input entered by the user.

```c
int age;

printf("Enter your age: ");
scanf("%d", &age);
```

In this example:

- `%d` tells `scanf` to read an integer.
- `&age` tells `scanf` where the entered integer should be stored.
- After the input is stored, the program can use the value inside `age`.

`scanf` is declared in `stdio.h`, just like `printf`.

### Why Is `&` Used?

The `&` symbol placed before a variable means **address of**.

```c
&age
```

A variable stores a value somewhere in the computer's memory. `&age` gives the memory address of the place where `age` is stored.

`scanf` needs this address because it must place the user's input into the variable:

```c
scanf("%d", &age);
```

For now, remember:

- `age` means the value stored in the variable.
- `&age` means the address where that variable is stored.
- `printf` normally uses the value, such as `age`.
- `scanf` normally needs the address, such as `&age`, so it can change the variable's value.

The `&` symbol is connected to pointers, but pointers can be studied properly later.

### Matching Input Format Specifiers

The format specifier given to `scanf` must match the variable's data type.

| Data Type | `scanf` Specifier | Example |
| --- | --- | --- |
| `int` | `%d` | `scanf("%d", &age);` |
| `float` | `%f` | `scanf("%f", &height);` |
| `double` | `%lf` | `scanf("%lf", &price);` |
| `char` | `%c` | `scanf(" %c", &grade);` |

There is a small but important difference between `printf` and `scanf` for `double`:

- `printf` uses `%f` to print a `double`.
- `scanf` uses `%lf` to read a `double`.

The space before `%c` in `scanf(" %c", &grade)` tells `scanf` to skip leftover spaces or newlines before reading the character.

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

## Naming Variables

Variable names in C:

- Can contain letters, digits, and underscores
- Cannot begin with a digit
- Cannot be a C keyword
- Are case-sensitive

For example, `age`, `student_age`, and `score2` are valid names.

`score` and `Score` are treated as different names.

Meaningful names are usually better than single-letter names once a program becomes larger.

## Basic Data Types

`03dataTypes.c` demonstrates the basic C data types learned so far:

| Data Type | Purpose |
| --- | --- |
| `char` | Stores one character |
| `int` | Stores a whole number |
| `float` | Stores a decimal number |
| `double` | Stores a decimal number with more precision than `float` |
| `void` | Represents no value |

Examples:

```c
int whole_number = 25;
float decimal_number = 2.5f;
double precise_number = 2.5;
char character = 'C';
```

The `f` suffix marks `2.5f` as a `float` literal. Without `f`, a decimal literal such as `2.5` is a `double` by default.

For now, `void` can be seen inside `main(void)`. The `void` between the brackets means that `main` is not receiving any values.

Functions and other uses of `void` can be studied later.

## Type Conversion

Type conversion changes a value from one data type to another.

- **Implicit conversion** happens automatically when C needs compatible values to work together.
- **Explicit conversion**, also called type casting, is requested by the programmer.

```c
float result = 7 / (float)2;
```

Here, `(float)` explicitly converts `2` before division.

Conversions can change or lose part of a value, so they should be used carefully. Type conversion is explained further in [C Instructions And Operators](../02Instructions&Operators/C-instructions_operators.md) and will be understood better through later practice chapters.

## Checking Types And Sizes

`sizeof` reports how many bytes a variable or type uses on the current system:

```c
sizeof(int)
```

`sizeof` returns a value with the type `size_t`.

`size_t` is an unsigned integer type made for representing sizes and counts. Its actual underlying type can differ between computers and compilers.

Because `sizeof` returns `size_t`, `%zu` should be used when printing its result:

```c
printf("int takes %zu bytes\n", sizeof(int));
```

- `z` tells `printf` that the value has the type `size_t`.
- `u` tells `printf` to display it as an unsigned whole number.

The size of a C type can differ between compilers and computers, so it is better to check instead of assuming.

`void` has no value, so `sizeof(void)` is not allowed in standard C.

## Single Quotes And Double Quotes

They have different meanings in C:

```c
char letter = 'e';
```

Single quotes represent one character.

Internally, a `char` stores a numeric character code. Basic English letters, digits, and symbols commonly use ASCII values. This is introduced properly in [C Conditional Instructions](../03Conditional-Instructions/C-conditional-instruction.md#ascii-and-character-values).

```c
printf("Hello");
```

Double quotes represent a string literal, which is a sequence of characters.

Writing this is incorrect because `"e"` is a string, not one character:

```c
char letter = "e";
```

## Format Specifiers

Format specifiers are placeholders inside a `printf` format string. They tell `printf` how to understand and display the values provided after the string.

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
| `%s` | A string |
| `%zu` | A `size_t` value, such as the result of `sizeof` |
| `%%` | Prints the `%` symbol |

The value after the comma replaces the matching format specifier in the output.

```c
int age = 20;
printf("Age: %d\n", age);
```

Here, `%d` is replaced by the value stored in `age`.

The format specifier must match the value being printed. Using the wrong one can print incorrect output or cause undefined behavior.

```c
printf("%d", age); // Correct because age is an int
printf("%f", age); // Incorrect because %f does not expect an int
```

## Escape Sequences

Escape sequences begin with a backslash and represent special characters inside strings.

| Escape Sequence | Meaning |
| --- | --- |
| `\n` | Starts a new line |
| `\t` | Adds a horizontal tab |
| `\"` | Adds a double quote inside a string |
| `\\` | Adds a backslash |
| `\0` | Represents the null character |

Using `\n`:

```c
printf("Hello\nWorld");
```

Output:

```text
Hello
World
```

Using quotes inside a string:

```c
printf("He said, \"Hello\".\n");
```

The backslash changes how C understands the character that follows it.

The null character `\0` marks the end of a C string. If `printf` reaches `\0`, it stops printing the string:

```c
printf("Hello\0World");
```

Only `Hello` is printed because `\0` appears before `World`.

## Constants

A constant is a value that should not change while the program runs.

The programs already contain literal constants:

```c
25
2.5f
'C'
"Hello World"
```

These values are written directly in the code.

### Using `const`

The `const` keyword makes a variable read-only after it is initialized:

```c
const int DAYS_IN_WEEK = 7;
```

Trying to assign another value later causes a compiler error:

```c
DAYS_IN_WEEK = 8; // Error
```

The type is still written normally. For example, `const int` stores an integer and `const float` stores a floating-point value.

### Using `#define`

`#define` creates a named value during preprocessing:

```c
#define MAX_SCORE 100
```

The preprocessor replaces `MAX_SCORE` with `100` before compilation.

Unlike a normal declaration:

- `#define` does not use `=`.
- `#define` does not end with a semicolon.
- A simple `#define` constant does not have a C data type.

### `const` And `#define` Difference

Both can give a name to a value that should not change, but they work differently:

| `const` | `#define` |
| --- | --- |
| Creates a real, read-only C variable | Creates a preprocessor replacement |
| Has a data type | Does not have a C data type |
| Uses normal declaration syntax | Does not use `=` or a semicolon |
| Follows normal variable scope rules | Remains available until it is undefined or the file ends |
| Is checked by the compiler like a variable | Is replaced before normal compilation |

Example:

```c
const int DAYS_IN_WEEK = 7;
#define MAX_SCORE 100
```

For most normal fixed values, prefer `const` because it has a type and follows normal C rules. Use `#define` when a preprocessor replacement is specifically useful.

### Naming Constants

Uppercase names are commonly used for constants:

```c
const float PI = 3.14159f;
#define MAX_SCORE 100
```

Uppercase is a naming convention, not a rule enforced by C. It helps constants stand out from normal variables.

For beginner programs:

- Use `const` when creating a typed value that should not change.
- Use simple `#define` constants when learning how named values can be created by the preprocessor.
- Avoid replacing clear one-time values with constants when a name would not improve the code.

## C Keywords

Keywords are words reserved by the C language. They have special meanings and cannot be used as names for variables or other identifiers.

### Standard 32 C Keywords

These are the 32 keywords commonly taught as the standard C keyword list. Some belong to topics that will be learned later.

- `auto` - Gives a local variable automatic storage duration. This is already the default for normal local variables, so it is rarely written.
- `break` - Immediately exits the nearest loop or `switch` statement.
- `case` - Defines one possible matching value inside a `switch` statement.
- `char` - Declares a character or small integer type.
- `const` - Marks an object as read-only through that name after initialization.
- `continue` - Skips the remaining code in the current loop iteration and starts the next iteration.
- `default` - Defines the fallback branch inside a `switch` when no `case` matches.
- `do` - Starts a `do...while` loop, which runs its body at least once.
- `double` - Declares a double-precision floating-point type.
- `else` - Provides the alternative branch of an `if` statement.
- `enum` - Defines a type containing named integer constants.
- `extern` - Declares that a variable or function is defined elsewhere.
- `float` - Declares a single-precision floating-point type.
- `for` - Creates a loop with initialization, condition, and update parts.
- `goto` - Jumps directly to a labeled statement inside the same function.
- `if` - Runs code only when a condition is true.
- `int` - Declares an integer type.
- `long` - Modifies an integer or floating-point type to support a longer range or precision.
- `register` - Suggests that a variable will be used frequently. Modern compilers usually make this decision themselves.
- `return` - Ends a function and optionally sends a value back to its caller.
- `short` - Modifies an integer type to use a range no greater than `int`.
- `signed` - Declares an integer type that can represent negative and positive values.
- `sizeof` - Produces the size of a type or object in bytes.
- `static` - Gives different storage or visibility behavior depending on where it is used.
- `struct` - Groups multiple related values into one user-defined type.
- `switch` - Selects one branch from multiple `case` values.
- `typedef` - Creates another name for an existing type.
- `union` - Groups members that share the same memory location.
- `unsigned` - Declares an integer type that represents zero and positive values.
- `void` - Represents no value or no function parameters.
- `volatile` - Tells the compiler that a value may change unexpectedly and must be read when requested.
- `while` - Repeats code while a condition remains true.

`#include` and `#define` are not C keywords. They are preprocessor directives handled before normal compilation.

### Keywords Added In Later C Versions

Later versions of C added more keywords. These are only listed for awareness and do not need to be learned yet.

**Added in C99:**

- `inline`
- `restrict`
- `_Bool`
- `_Complex`
- `_Imaginary`

**Added in C11:**

- `_Alignas`
- `_Alignof`
- `_Atomic`
- `_Generic`
- `_Noreturn`
- `_Static_assert`
- `_Thread_local`

## Comments

Comments explain code and are ignored by the compiler.

### Single-Line Comments

A single-line comment begins with `//` and continues until the line ends:

```c
// This is a comment
```

### Multi-Line Comments

A multi-line or block comment begins with `/*` and ends with `*/`:

```c
/*
This comment can continue
across multiple lines.
*/
```

It can also be written on one line:

```c
/* This is also a block comment. */
```

Block comments cannot be placed inside other block comments.

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
- `const` and `#define` can give meaningful names to values that should not change.
- `scanf` reads input, and `&variable` gives it the address where the input should be stored.
- Compiler warnings can reveal mistakes even when a program still runs.
