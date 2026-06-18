# C Functions And Recursion

Parent: [C Language](../C-Language.md)  
Previous: [C Loops](../04Loops/C-Loops.md)  
Next: [C Projects](../Projects/Projects.md)

Functions let a program divide work into smaller named blocks. Instead of writing every statement inside `main`, a function lets one part of the program handle one clear task.

Practice files:

- [Basic user-defined function](01function.c)
- [Calling multiple functions](02multipleFunction.c)
- [Types of functions](03functionType.c)
- [Using a math library function](04mathLibrary.c)
- [Recursion using factorial](05recursion.c)

Practice set:

- [Problem 1: Average of three numbers](C-Function-Recursion-practiceSet1/01problem.c)
- [Problem 2: Celsius to Fahrenheit](C-Function-Recursion-practiceSet1/02problem.c)
- [Problem 3: Force of attraction](C-Function-Recursion-practiceSet1/03problem.c)
- [Problem 4: Fibonacci using recursion](C-Function-Recursion-practiceSet1/04problem.c) - code pending
- [Problem 5: Expression output question](C-Function-Recursion-practiceSet1/05problem.c)
- [Problem 6: Sum of first n natural numbers](C-Function-Recursion-practiceSet1/06problem.c)
- [Problem 7: Pattern using function](C-Function-Recursion-practiceSet1/07problem.c) - code pending

This chapter continues from [C Loops](../04Loops/C-Loops.md). Loops repeat work, while functions organize work.

## Contents

- [What Is A Function?](#what-is-a-function)
- [Components Of A Function](#components-of-a-function)
- [Declaration Or Prototype](#declaration-or-prototype)
- [Function Definition](#function-definition)
- [Function Call](#function-call)
- [Library Functions And User-Defined Functions](#library-functions-and-user-defined-functions)
- [Types Of Functions](#types-of-functions)
- [Parameters And Arguments](#parameters-and-arguments)
- [Passing Values To A Function](#passing-values-to-a-function)
- [Return Value](#return-value)
- [Important Points](#important-points)
- [Math Library Function](#math-library-function)
- [Recursion](#recursion)
- [Summary](#summary)

## What Is A Function?

A function is a named block of code that performs a task.

```c
void display(void) {
    printf("Hello\n");
}
```

Here, `display` is a function. When it is called, the code inside its body runs.

Functions help because they:

- make code easier to read
- avoid repeating the same code many times
- divide a program into smaller tasks
- make testing and fixing code easier

## Components Of A Function

A function usually has these parts:

```c
int sum(int a, int b) {
    return a + b;
}
```

| Part | Example | Meaning |
| --- | --- | --- |
| Return type | `int` | Type of value the function sends back |
| Function name | `sum` | Name used to call the function |
| Parameters | `int a, int b` | Placeholder variables that receive values |
| Body | `{ return a + b; }` | Statements that run when the function is called |
| Return statement | `return a + b;` | Sends a value back to the caller |

If a function does not return a value, its return type is `void`.

If a function does not receive values, write `void` inside the parentheses:

```c
void display(void)
```

This clearly means the function takes no parameters.

## Declaration Or Prototype

A function declaration, also called a prototype, tells the compiler that a function exists.

```c
void display(void);
```

The declaration usually contains:

- return type
- function name
- parameter types
- semicolon

It does not contain the function body.

The prototype is useful when the function definition appears after `main`.

```c
void display(void);

int main(void) {
    display();
    return 0;
}

void display(void) {
    printf("Hello\n");
}
```

Without the prototype, the compiler may reach `display()` inside `main` before it knows what `display` is.

## Function Definition

A function definition contains the actual body of the function:

```c
void display(void) {
    printf("Hello\n");
}
```

This is where the task is written.

The definition does not end with a semicolon after the closing brace.

## Function Call

A function call runs the function:

```c
display();
```

When the program reaches this line, control moves to the `display` function. After `display` finishes, control returns to the next line after the call.

In [02multipleFunction.c](02multipleFunction.c), `main` calls three functions in order:

```c
morning();
noon();
night();
```

So the messages print in that same order.

## Library Functions And User-Defined Functions

C has library functions, such as:

- `printf`
- `scanf`
- `pow`

These are already written somewhere else. Header files give the compiler the information needed to use them.

```c
#include <stdio.h>
#include <math.h>
```

User-defined functions are functions written by the programmer:

```c
void display(void) {
    printf("Hello\n");
}
```

Important note: `main` is special because program execution starts from it. It is written by the programmer, but it has a special role in C.

## Types Of Functions

Functions can be grouped by whether they return a value and whether they take parameters.

See [03functionType.c](03functionType.c).

| Type | Return Value? | Parameters? | Example |
| --- | --- | --- | --- |
| Type 1 | No | No | `void display_message(void)` |
| Type 2 | Yes | Yes | `int sum(int a, int b)` |
| Type 3 | No | Yes | `void print_char(char a)` |
| Type 4 | Yes | No | `float pi(void)` |

### Type 1: No Return Value And No Parameters

```c
void display_message(void) {
    printf("Hello\n");
}
```

This function does not receive anything and does not send anything back.

Use this type when the function only performs an action, such as printing a message.

### Type 2: Return Value And Parameters

```c
int sum(int a, int b) {
    return a + b;
}
```

This function receives two values and returns one result.

Use this type when a function needs input and should give back an answer.

### Type 3: No Return Value But Has Parameters

```c
void print_char(char a) {
    printf("%c\n", a);
}
```

This function receives a value but does not return anything.

Use this type when the function needs input only to perform an action.

### Type 4: Return Value But No Parameters

```c
float pi(void) {
    return 3.145f;
}
```

This function does not receive anything, but it returns a value.

Use this type when the function can produce a value by itself.

## Parameters And Arguments

Parameters are the placeholder variables written in the function definition:

```c
int sum(int a, int b)
```

Here, `a` and `b` are parameters.

Arguments are the actual values passed during the function call:

```c
sum(num1, num2);
```

Here, `num1` and `num2` are arguments.

Simple way to remember:

- Parameters are written when the function is defined.
- Arguments are sent when the function is called.

## Passing Values To A Function

In the current programs, values are passed by value.

That means the function receives a copy of the value, not the original variable itself.

```c
int sum(int a, int b) {
    return a + b;
}
```

When this is called:

```c
int num1 = 25;
int num2 = 20;

sum(num1, num2);
```

The values of `num1` and `num2` are copied into `a` and `b`.

Changing `a` or `b` inside the function would not directly change `num1` or `num2`.

Changing original variables through functions requires pointers, which should be studied later.

## Return Value

`return` sends a value back to the place where the function was called.

```c
return a + b;
```

A function can return only one value directly.

The returned value can be stored:

```c
int result = sum(25, 20);
```

Or used directly:

```c
printf("%d\n", sum(25, 20));
```

If the function return type is `void`, it does not return a value.

## Important Points

- A function should usually do one clear task.
- A function must be declared before it is called, unless its full definition appears before the call.
- The function return type should match the value returned.
- A `void` function should not return a normal value.
- A non-`void` function should return a value of the correct type.
- A function can call another function.
- Execution starts from `main`.
- Other functions run only when they are called directly or indirectly from `main`.

## Math Library Function

[04mathLibrary.c](04mathLibrary.c) uses:

```c
pow(side_a, 2)
```

`pow` comes from `math.h`.

```c
#include <math.h>
```

`pow(a, b)` calculates `a` raised to the power of `b`.

Example:

```c
pow(7, 2)
```

This means:

```text
7 to the power 2
```

Result:

```text
49
```

`pow` returns a floating-point value, so storing it in a `double` is cleaner than storing it in an `int`.

## Recursion

Recursion means a function calls itself.

```c
int factorial(int num) {
    if (num <= 1) {
        return 1;
    }

    return num * factorial(num - 1);
}
```

The function keeps calling itself with a smaller value.

For `factorial(5)`:

```text
factorial(5)
= 5 * factorial(4)
= 5 * 4 * factorial(3)
= 5 * 4 * 3 * factorial(2)
= 5 * 4 * 3 * 2 * factorial(1)
= 5 * 4 * 3 * 2 * 1
= 120
```

### Base Case

The base case is the condition that stops recursion.

```c
if (num <= 1) {
    return 1;
}
```

Without a base case, the function would keep calling itself and eventually crash.

### Recursive Case

The recursive case is the part where the function calls itself:

```c
return num * factorial(num - 1);
```

Each call should move closer to the base case.

## Recursion Important Points

- Recursion needs a base case.
- Each recursive call should move toward the base case.
- Recursion can sometimes be replaced with loops.
- Recursion may use more memory than a loop because each call must wait for the next call to finish.
- Recursion is useful when a problem naturally breaks into smaller versions of itself.

## Summary

- A function is a named block of code that performs a task.
- A prototype tells the compiler about a function before it is used.
- A definition contains the actual function body.
- A call runs the function.
- Parameters receive values; arguments are the values sent.
- Current examples pass values by value.
- Functions may return a value or return nothing using `void`.
- Recursion is a function calling itself with a stopping condition.
