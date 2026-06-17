# C Instructions And Operators

Parent: [C Language](../C-Language.md)  
Previous: [C Basics](../01Basics/C-Basic.md)  
Next: [C Conditional Instructions](../03Conditional-Instructions/C-conditional-instruction.md)

C programs are made of instructions that tell the computer what to do.

Practice files:

- [Type declaration practice](01typeDeclaration.c)
- [Type casting practice](02typeCasting.c)
- [Arithmetic practice](03arithmetic.c)
- [Associativity practice](04associativity.c)
- [Instructions and operators problem set 1](C-Inst-Oper-ProblemSet1/)

The next chapter, [C Conditional Instructions](../03Conditional-Instructions/C-conditional-instruction.md), continues with relational, logical, and conditional operators.

The first problem set practices:

- [Finding the invalid declaration](C-Inst-Oper-ProblemSet1/01problem.c)
- [Finding an expression's result type](C-Inst-Oper-ProblemSet1/02problem.c)
- [Checking divisibility using remainder](C-Inst-Oper-ProblemSet1/03problem.c)
- [Evaluating an expression step by step](C-Inst-Oper-ProblemSet1/04problem.c)

## Contents

- [Type Declaration Instructions](#type-declaration-instructions)
- [Arithmetic Instructions](#arithmetic-instructions)
- [Operations, Operators, And Operands](#operations-operators-and-operands)
- [Spaces Around Operators And Operands](#spaces-around-operators-and-operands)
- [Basic Arithmetic Operators](#basic-arithmetic-operators)
- [Assignment Operator](#assignment-operator)
- [Division And Modulus](#division-and-modulus)
- [Type Conversion In Arithmetic](#type-conversion-in-arithmetic)
- [Operator Precedence](#operator-precedence)
- [Associativity](#associativity)
- [Control Instructions](#control-instructions)
- [Summary](#summary)

At a high level, C instructions can be grouped into:

1. Type declaration instructions
2. Arithmetic instructions
3. Control instructions

## Type Declaration Instructions

Type declaration instructions create variables and tell C what kind of values they will store.

```c
int age;
float price = 25.5f;
char grade = 'A';
```

A variable should be declared before it is used. The selected data type affects what values it can store and how much memory it needs.

## Arithmetic Instructions

Arithmetic instructions perform calculations using values, variables, and operators.

```c
int total = price * quantity;
float average = total / 2.0f;
```

### Operations, Operators, And Operands

An **operation** is the calculation being performed.

An **operator** is the symbol that performs the operation.

An **operand** is a value or variable used by the operator.

```c
total = price + tax;
```

Here:

- Addition is the operation.
- `+` is the operator.
- `price` and `tax` are operands.

### Spaces Around Operators And Operands

Spaces around operators are optional in C. They are valid whether the operands are variables, constants, or decimal values:

```c
result=a+b;
result = a + b;
result = a + 5;
result = 2.5f + a;
```

All four statements are valid. Adding spaces usually makes an expression easier to read.

Spaces cannot replace a required operator:

```c
result = a b; // Invalid: no operator between a and b
result = a 5; // Invalid: no operator between a and 5
```

Spaces also cannot split one identifier or number:

```c
big number = 10; // Invalid: a variable name cannot contain a space
float value = 2 . 5; // Invalid: 2.5 must remain one number
```

### Basic Arithmetic Operators

| Operator | Meaning | Example |
| --- | --- | --- |
| `+` | Addition | `a + b` |
| `-` | Subtraction | `a - b` |
| `*` | Multiplication | `a * b` |
| `/` | Division | `a / b` |
| `%` | Remainder after integer division | `a % b` |

### Assignment Operator

The assignment operator `=` stores the value from its right side in the variable on its left side.

```c
total = price + tax;
```

The addition is calculated first, then its result is assigned to `total`.

`=` means assignment. It does not mean "is equal to" in a mathematical comparison.

### Division And Modulus

The result of `/` depends on the types of the values being divided.

**Integer division** happens when both values are integers:

```c
int result = 7 / 2;
```

The result is `3`. C removes the decimal part by truncating toward zero. For positive integers, this gives the same result as floor division.

**Real or floating-point division** happens when at least one value is a floating-point value:

```c
float result = 7.0f / 2;
```

The result is `3.5`.

The modulus operator `%` gives the remainder after integer division:

```c
int remainder = 7 % 2;
```

The remainder is `1`. The `%` operator is used with integer values, not `float` or `double`.

Modulus can be used to check divisibility. If `number % divisor` gives `0`, the number is divisible by that divisor:

```c
int remainder = number % 97;
```

Division or modulus by zero is not allowed.

#### Negative Division And Modulus

In `a / b` or `a % b`:

- `a` is the **dividend** or numerator.
- `b` is the **divisor** or denominator.

Integer division in C truncates the result toward zero:

| Expression | Division Result | Modulus Result |
| --- | ---: | ---: |
| `7 / 2` and `7 % 2` | `3` | `1` |
| `-7 / 2` and `-7 % 2` | `-3` | `-1` |
| `7 / -2` and `7 % -2` | `-3` | `1` |
| `-7 / -2` and `-7 % -2` | `3` | `-1` |

Key points:

- Changing the sign of either operand changes the sign of the division result.
- The modulus result follows the sign of the dividend or numerator.
- Changing only the divisor's sign does not change the modulus result's sign.
- C keeps this relationship true:

```text
dividend = (division result * divisor) + remainder
```

### Type Conversion In Arithmetic

Type conversion changes a value from one data type to another. It can happen automatically or be requested by the programmer.

#### Implicit Conversion

Implicit conversion happens automatically when C works with different compatible types.

```c
int whole_number = 5;
float decimal_number = 2.5f;
float result = whole_number + decimal_number;
```

Before addition, C converts `whole_number` from `int` to `float` so both operands can take part in floating-point arithmetic.

A floating-point value affects the operation it takes part in, but it does not change earlier operations that have already been evaluated:

```c
float result = 2 * 2 / 4 + 1.0f;
```

Here, `2 * 2 / 4` uses integer arithmetic first and becomes `1`. The later addition with `1.0f` produces the final floating-point value `2.0`.

For the basic number types covered so far, arithmetic generally moves toward the type that can keep more information:

```text
char -> int -> float -> double
```

This is a simplified beginner view. The complete conversion rules include more types and will be easier to understand after those types are studied.

Implicit conversion also happens during assignment:

```c
float value = 10;
```

The integer `10` is automatically converted to `float` before being stored.

Converting in the other direction can lose information:

```c
int value = 3.9;
```

The decimal part is removed, so `value` becomes `3`.

The expression is calculated before assignment. For example, `3.0 / 8 - 2` produces the `double` value `-1.625`, but storing it in an `int` removes the decimal part:

```c
int result = 3.0 / 8 - 2; // Stores -1
```

#### Explicit Conversion Or Type Casting

Explicit conversion is written by the programmer using the required type inside parentheses:

```c
float result = 15 / (float)4;
```

`(float)4` converts `4` from `int` to `float`. Because one operand is now floating-point, the division produces `3.75` instead of integer result `3`.

The arithmetic practice file uses this same idea:

```c
float floating_division = big_num / (float)small_num;
```

A cast affects the value used in that expression. It does not permanently change the original variable's declared type.

Changing a value's type does not change the format specifier required by `printf`. The specifier must match the value actually passed:

```c
printf("%.2f\n", (float)num); // Correct: the cast produces a floating-point value
printf("%f\n", num);          // Incorrect: num is still an int
```

#### Key Points

- Arithmetic between two integers produces an integer result.
- If one arithmetic operand is floating-point, C converts the other operand for floating-point arithmetic.
- Assignment can convert the calculated value to the destination variable's type.
- Explicit casts make the requested conversion visible in the code.
- Conversion to a type that cannot represent the full value may lose information.

### Operator Precedence

Precedence decides which operator is evaluated first in an expression.

```c
int result = 2 + 3 * 4;
```

Multiplication has higher precedence than addition, so `3 * 4` is calculated first.

The result is `14`, not `20`.

Parentheses can make the intended order clear:

```c
int result = (2 + 3) * 4;
```

This result is `20`.

As more operators are introduced, the precedence table is continued in [C Conditional Instructions](../03Conditional-Instructions/C-conditional-instruction.md#operator-precedence).

For the operators covered in this chapter, the order is:

| Precedence | Operators | Purpose | Associativity |
| ---: | --- | --- | --- |
| Highest | `()` | Group an expression | Left to right |
|  | `*`, `/`, `%` | Multiplication, division, remainder | Left to right |
|  | `+`, `-` | Addition, subtraction | Left to right |
| Lowest | `=` | Assignment | Right to left |

Assignment has lower precedence than the arithmetic operators, so the calculation on the right side happens before its result is stored.

### Associativity

Associativity decides how operators with the same precedence are grouped.

Most basic arithmetic operators are evaluated from left to right:

```c
int result = 20 / 5 * 2;
```

This is evaluated as:

```text
(20 / 5) * 2
```

Assignment is evaluated from right to left:

```c
a = b = 10;
```

The value `10` is first assigned to `b`, then to `a`.

Use parentheses when an expression may be unclear.

## Control Instructions

Control instructions decide the order in which program statements run.

There are four common control-flow types:

### Sequence Control

Statements run one after another from top to bottom. The beginner programs written so far mainly use sequence control.

### Decision Control

Decision control chooses which code should run based on a condition.

- `if` - Runs code when a condition is true.
- `if...else` - Selects between two paths.
- `else if` - Checks another condition when an earlier condition was false.
- `else` - Runs when the earlier conditions were false.

### Loop Control

Loop control repeats a block of code while a condition allows it.

- `for` - Repeats code with a starting step, condition, and update.
- `while` - Repeats code while a condition remains true.
- `do...while` - Runs the code once before checking whether it should repeat.

### Case Control

Case control selects one option from multiple possible values.

- `switch` - Starts the selection using one value.
- `case` - Defines one possible matching value.
- `default` - Defines the fallback when no case matches.
- `break` - Exits the switch after a matching case finishes.

This is only a high-level view. Decision, loop, and case control will be explained properly in their upcoming chapters and practice programs.

## Summary

- Type declaration instructions create variables and define their data types.
- Arithmetic instructions perform calculations using operators and operands.
- Spaces around operators improve readability but do not change the calculation.
- Integer division removes the decimal part, while floating-point division keeps it.
- Modulus gives the remainder after integer division.
- A remainder of `0` can be used to check divisibility.
- With negative integers, division truncates toward zero and the remainder follows the dividend's sign.
- Type conversion can happen automatically or be requested with a cast.
- Precedence decides which operator runs first.
- Associativity decides how operators with equal precedence are grouped.
- Control instructions change the order in which statements run.
- Sequence, decision, loop, and case are common control-flow types.
