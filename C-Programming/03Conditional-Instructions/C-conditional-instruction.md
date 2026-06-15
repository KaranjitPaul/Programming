# C Conditional Instructions

Conditional instructions let a program make decisions instead of always running every statement.

Practice files:

- [`if` with separate conditions](01if.c)
- [`if...else`](02if-else.c)
- [`if...else if...else`](03if-elseif-else.c)
- [Ternary operator](04ternaryOperator.c)
- [`switch` and `case`](05switchCase.c)
- [Logical operators](06logicalOperator.c)
- [Nested `if`](07nestedIf.c)
- [Grade calculator quiz](08quiz.c)
- [Conditional instructions problem set 1](C-Cond_Inst-ProblemSet1/)

The first conditional problem set applies the chapter through:

- [Assignment inside a condition](C-Cond_Inst-ProblemSet1/01problem.c)
- [Student pass or fail requirements](C-Cond_Inst-ProblemSet1/02problem.c)
- [Progressive income-tax slabs](C-Cond_Inst-ProblemSet1/03problem.c)
- [Leap-year conditions](C-Cond_Inst-ProblemSet1/04problem.c)
- [Lowercase character checking](C-Cond_Inst-ProblemSet1/05problem.c)
- [Finding the greatest of four numbers](C-Cond_Inst-ProblemSet1/06problem.c)
- [Displaying and classifying ASCII characters](C-Cond_Inst-ProblemSet1/07problem.c)

## Conditions And Truth Values

A condition is an expression that C checks as either false or true.

In C:

- `0` means **false**.
- Any non-zero value means **true**, including positive and negative numbers.
- Relational and logical operators produce either `0` for false or `1` for true.

```c
printf("%d\n", 5 > 2);   // 1
printf("%d\n", 5 < 2);   // 0

if (-4) {
    printf("-4 is treated as true\n");
}
```

Although any non-zero value is true, writing clear conditions such as `age >= 18` is easier to understand than placing an unrelated number directly inside `if`.

## `if`

An `if` statement runs its block only when its condition is true:

```c
if (age >= 18) {
    printf("Adult\n");
}
```

Separate `if` statements are checked separately, so more than one can run. See [01if.c](01if.c).

## `if...else`

`if...else` chooses exactly one of two paths:

```c
if (age >= 18) {
    printf("Adult\n");
} else {
    printf("Not an adult\n");
}
```

When the `if` condition is true, the `else` block is skipped. Otherwise, the `else` block runs. See [02if-else.c](02if-else.c).

## `if...else if...else`

An `else if` chain checks conditions from top to bottom. Once one condition is true, its block runs and the remaining conditions are skipped.

This makes the order important. In the [grade calculator](08quiz.c), checking `marks >= 90` before `marks >= 80` ensures that a mark of `95` receives grade `A`.

The final `else` is optional and handles values that did not match an earlier condition.

## Nested `if`

A nested `if` is an `if` statement placed inside another `if` block.

The inner condition is reached only when the outer condition is true. It is useful when the second decision depends on the first one. See [07nestedIf.c](07nestedIf.c).

Too many nested levels can become difficult to read, so use them only when the decisions genuinely depend on each other.

## Relational Operators

Relational operators compare two values. Their result is `1` when the comparison is true and `0` when it is false.

| Operator | Meaning | Example |
| --- | --- | --- |
| `<` | Less than | `age < 18` |
| `>` | Greater than | `score > 50` |
| `<=` | Less than or equal to | `marks <= 100` |
| `>=` | Greater than or equal to | `age >= 18` |
| `==` | Equal to | `choice == 1` |
| `!=` | Not equal to | `remainder != 0` |

Do not confuse `==` with `=`:

```c
score = 10;  // Assigns 10 to score
score == 10; // Checks whether score equals 10
```

An assignment expression also produces the value that was assigned:

```c
if (score = 10) {
    printf("This runs because the assigned value 10 is non-zero.\n");
}
```

This is valid C, but it is commonly an accidental mistake when `score == 10` was intended. Compilers can warn about it. The [assignment condition problem](C-Cond_Inst-ProblemSet1/01problem.c) uses extra parentheses to show that the assignment is intentional.

Comparisons should not be chained like they are in mathematics:

```c
18 <= age && age < 60 // Correct
18 <= age < 60        // Does not perform the intended range check
```

The second expression first produces `0` or `1` from `18 <= age`, then compares that result with `60`.

Characters can also be compared because C stores them using numeric character codes. Character literals keep these comparisons readable:

```c
ch >= 'a' && ch <= 'z'
```

This checks whether `ch` falls within the lowercase-letter range without writing the ASCII values `97` and `122` directly.

## ASCII And Character Values

ASCII stands for **American Standard Code for Information Interchange**. It is a character-encoding standard that gives numeric codes to letters, digits, symbols, and control characters.

Some useful ASCII ranges are:

| Characters | ASCII Values |
| --- | ---: |
| Digits `'0'` to `'9'` | `48` to `57` |
| Uppercase letters `'A'` to `'Z'` | `65` to `90` |
| Lowercase letters `'a'` to `'z'` | `97` to `122` |

A `char` stores a numeric character code. The format specifier decides whether `printf` shows it as a character or a number:

```c
char ch = 'A';

printf("%c\n", ch); // Prints A
printf("%d\n", ch); // Prints 65 on an ASCII-based system
```

Using character literals such as `'A'` and `'z'` is usually clearer than writing their numeric codes directly:

```c
if (ch >= 'A' && ch <= 'Z') {
    printf("Uppercase letter\n");
}
```

ASCII defines values from `0` to `127`. Modern systems can represent many more characters using encodings such as Unicode, but the basic English letters, digits, and common symbols used in these programs follow ASCII values. See the [ASCII character problem](C-Cond_Inst-ProblemSet1/07problem.c).

## Logical Operators

Logical operators combine or reverse conditions. See [06logicalOperator.c](06logicalOperator.c).

### Logical AND `&&`

`&&` is true only when both conditions are true:

```c
age >= 18 && age < 60
```

| Left condition | Right condition | Result |
| --- | --- | --- |
| False | False | False |
| False | True | False |
| True | False | False |
| True | True | True |

### Logical OR `||`

`||` is true when at least one condition is true:

```c
age < 18 || age >= 60
```

| Left condition | Right condition | Result |
| --- | --- | --- |
| False | False | False |
| False | True | True |
| True | False | True |
| True | True | True |

### Logical NOT `!`

`!` reverses a truth value:

```c
!(age < 60)
```

- `!0` produces `1`.
- `!` applied to any non-zero value produces `0`.

### Short-Circuit Evaluation

Logical operators stop as soon as the final answer is known:

- With `&&`, if the left condition is false, the right condition is not checked.
- With `||`, if the left condition is true, the right condition is not checked.

This can avoid unnecessary work and can protect an operation that should happen only after an earlier condition succeeds.

## Ternary Operator

The ternary or conditional operator chooses between two expressions:

```c
int bigger = a > b ? a : b;
```

Its form is:

```text
condition ? value_when_true : value_when_false
```

It is useful for a short, simple decision that produces a value. Nested ternary operators are valid, but an `if...else` statement is usually clearer when the decision becomes difficult to read. See [04ternaryOperator.c](04ternaryOperator.c).

## `switch`, `case`, And `default`

A `switch` selects a path by comparing one value with several constant `case` values:

```c
switch (choice) {
    case 1:
        printf("One\n");
        break;
    default:
        printf("Unknown choice\n");
}
```

- `switch` provides the value to check.
- `case` marks a possible matching value.
- `default` runs when no case matches. It is optional.

Each `case` matches one exact constant value. A `switch` is useful for choices such as menu numbers or character commands, but an `if...else` chain is better for ranges such as `marks >= 90`.

### Why `break` Is Used In `switch`

After a matching `case` is found, C continues running the following statements until the `switch` ends or it reaches `break`.

`break` exits the `switch`, preventing the next cases from running accidentally:

```c
case 2:
    printf("Two\n");
    break;
case 3:
    printf("Three\n");
    break;
```

Without the first `break`, choosing `2` would print both `Two` and `Three`. This behavior is called **fall-through**.

Fall-through can sometimes be intentional, such as letting several cases share the same code:

```c
case 1:
case 2:
    printf("One or two\n");
    break;
```

The final `case` or `default` does not require `break` when the `switch` ends immediately afterward, but including one can make the intended ending clear. See [05switchCase.c](05switchCase.c).

## Operator Precedence

Precedence decides which operator is grouped first. Associativity decides grouping when operators share the same precedence.

The table includes every operator used in the programs so far. Operators near the top have higher precedence.

| Precedence | Operators | Purpose | Associativity |
| ---: | --- | --- | --- |
| Highest | `()` | Grouping and function calls | Left to right |
|  | `(type)`, `!`, `sizeof`, `&variable` | Type cast, logical NOT, size, address-of | Right to left |
|  | `*`, `/`, `%` | Multiplication, division, remainder | Left to right |
|  | `+`, `-` | Addition, subtraction | Left to right |
|  | `<`, `<=`, `>`, `>=` | Relational comparisons | Left to right |
|  | `==`, `!=` | Equality comparisons | Left to right |
|  | `&&` | Logical AND | Left to right |
|  | `||` | Logical OR | Left to right |
|  | `?:` | Ternary conditional operator | Right to left |
| Lowest | `=` | Assignment | Right to left |

For example:

```c
age >= 18 && age < 60
```

The relational comparisons happen before `&&`, so C understands it as:

```text
(age >= 18) && (age < 60)
```

Parentheses are still useful when they make the intended grouping easier to see.

Arithmetic operators, assignment, type casts, `sizeof`, and address-of `&` were introduced in the earlier [C Basics](../01Basics/C-Basic.md) and [C Instructions And Operators](../02Instructions&Operators/C-instructions_operators.md) notes. Their place in the table matters when they are combined with conditions.

## Summary

- `0` is false, while every non-zero value is true.
- Relational operators compare values and produce `0` or `1`.
- `&&`, `||`, and `!` combine or reverse conditions.
- Separate `if` statements can all run, while an `else if` chain stops after its first true condition.
- A ternary operator is useful for a short decision that produces a value.
- `switch` selects among constant cases.
- `break` prevents unwanted fall-through into later cases.
- Character literals can be used in relational comparisons.
- ASCII gives numeric codes to basic characters.
