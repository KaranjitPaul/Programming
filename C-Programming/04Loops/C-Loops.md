# C Loops

Loops repeat a block of code while a condition allows it. They are useful when the same action must happen several times, such as printing a sequence, checking multiple values, or repeating a menu until the user chooses to exit.

Practice files:

- [`while` loop](01whileLoop.c)
- [`do...while` loop](02do-whileLoop.c)
- [`for` loop](03forLoop.c)
- [`continue` and `break`](04continue-break.c)
- [Multiple variables in a `for` loop](05multi-var-forLoop.c)
- [Increment and decrement iteration](06iteration.c)
- [Loops practice set 1](C-Loops-practiceSet1/)

The first loops practice set applies:

- [Multiplication table of a given number](C-Loops-practiceSet1/01problem.c)
- [Reverse multiplication table of 10](C-Loops-practiceSet1/02problem.c)
- [Sum of first 10 natural numbers using `while`](C-Loops-practiceSet1/03problem.c)
- [Same sum using `for` and `do...while`](C-Loops-practiceSet1/04problem.c)
- [Sum of products in the table of 8](C-Loops-practiceSet1/05problem.c)
- [Factorial using `for`](C-Loops-practiceSet1/06problem.c)
- [Factorial using `while`](C-Loops-practiceSet1/07problem.c)
- [Prime number check using `for`](C-Loops-practiceSet1/08problem.c)
- [Prime number check using `while` and `do...while`](C-Loops-practiceSet1/09problem.c)

Loops are a type of control instruction. They continue the ideas introduced in [C Conditional Instructions](../03Conditional-Instructions/C-conditional-instruction.md), because every loop also uses a condition to decide whether it should continue.

## Iteration

One complete execution of a loop body is called an **iteration**.

If a loop prints five values, its body normally runs for five iterations. A loop commonly needs:

1. A starting value.
2. A condition that decides whether another iteration should run.
3. An update that moves the loop toward ending.

```c
int i = 0;

while (i < 5) {
    printf("%d\n", i);
    i++;
}
```

Here, `i = 0` is the starting value, `i < 5` is the condition, and `i++` is the update.

If the condition never becomes false, the program creates an **infinite loop**. For example, forgetting `i++` above would leave `i` equal to `0` forever.

## `while` Loop

A `while` loop checks its condition before running the body:

```c
while (condition) {
    // repeated statements
}
```

If the condition is false at the beginning, the body does not run at all.

Use a `while` loop when repetition depends mainly on a condition and the number of iterations may not be known beforehand.

Example scenario: keep asking for a valid value while the entered value is invalid.

See [01whileLoop.c](01whileLoop.c).

## `do...while` Loop

A `do...while` loop runs its body before checking the condition:

```c
do {
    // repeated statements
} while (condition);
```

Because the condition is checked afterward, the body always runs at least once. Notice the required semicolon after `while (condition)`.

Example scenario: show a menu once, then keep showing it while the user wants to continue.

See [02do-whileLoop.c](02do-whileLoop.c).

## `for` Loop

A `for` loop keeps its initialization, condition, and update together:

```c
for (int i = 0; i < 5; i++) {
    printf("%d\n", i);
}
```

Its three parts are:

| Part | Example | When It Runs |
| --- | --- | --- |
| Initialization | `int i = 0` | Once, before the loop begins |
| Condition | `i < 5` | Before every iteration |
| Update | `i++` | After every completed iteration |

Use a `for` loop when a counter or a known range controls the repetition.

Example scenario: print the numbers from `1` to `100`.

### Already Declared Variables In A `for` Loop

If a variable is already declared before the loop, do not write its data type again inside the `for` parentheses. But if you want the loop to start from a specific value, you still assign that value in the initialization part.

```c
int num;

for (num = 5; num <= 10; num++) {
    printf("%d\n", num);
}
```

Here, `num` already exists, but `num = 5` is still needed because the loop must know where to begin. The initialization part does not always mean "create a new variable"; it can also mean "set the starting value."

This is valid C, but it can be confusing because the loop creates a new `num` only for the loop:

```c
int num;

for (int num = 5; num <= 10; num++) {
    printf("%d\n", num);
}
```

The `num` inside the loop is different from the `num` outside. For beginner code, prefer assigning the already-declared variable clearly:

```c
for (num = 5; num <= 10; num++) {
    printf("%d\n", num);
}
```

See [03forLoop.c](03forLoop.c).

## `break`

`break` immediately exits the nearest loop, even when the normal loop condition is still true:

```c
for (int i = 0; i < 100; i++) {
    if (i == 7) {
        break;
    }
}
```

Example scenarios:

- Stop searching after the required value is found.
- Exit a menu when the user chooses the exit option.
- Stop processing when an invalid or dangerous condition appears.

`break` exits only the nearest loop. In nested loops, an outer loop continues unless it is also stopped.

## `continue`

`continue` skips the remaining statements in the current iteration and moves to the next iteration:

```c
for (int i = 0; i < 10; i++) {
    if (i == 5) {
        continue;
    }

    printf("%d\n", i);
}
```

This prints every value except `5`.

Example scenarios:

- Skip invalid records but continue processing the rest.
- Ignore values that do not match a requirement.
- Skip one unwanted number in a sequence.

In a `for` loop, `continue` moves to the update part before checking the condition again. In `while` and `do...while` loops, it moves toward the condition check, so required updates must be placed carefully to avoid an infinite loop.

See [04continue-break.c](04continue-break.c).

## Increment And Decrement

Increment `++` adds `1`, and decrement `--` subtracts `1`.

| Form | Meaning |
| --- | --- |
| `++a` | Increase `a` first, then produce the new value |
| `a++` | Produce the old value, then increase `a` |
| `--a` | Decrease `a` first, then produce the new value |
| `a--` | Produce the old value, then decrease `a` |

When the produced value is not used, such as the update part of a simple loop, `i++` and `++i` both increase `i` before the next iteration.

Do not modify and separately read the same variable inside one complicated expression. Separate steps are clearer and avoid undefined behavior. See [06iteration.c](06iteration.c).

## Compound Assignment Operators

Compound assignment operators are shortcuts for updating a variable using its current value.

```c
sum += i;
```

This means:

```c
sum = sum + i;
```

The practice set uses this style in sum and factorial programs:

```c
sum += i;
fact *= i;
```

Common compound assignment operators are:

| Operator | Meaning | Same As |
| --- | --- | --- |
| `+=` | Add and assign | `a = a + b` |
| `-=` | Subtract and assign | `a = a - b` |
| `*=` | Multiply and assign | `a = a * b` |
| `/=` | Divide and assign | `a = a / b` |
| `%=` | Take remainder and assign | `a = a % b` |

Examples:

```c
int score = 10;
score += 5; // score becomes 15

int lives = 3;
lives -= 1; // lives becomes 2

int product = 1;
product *= 5; // product becomes 5

int total = 20;
total /= 4; // total becomes 5

int remainder = 17;
remainder %= 5; // remainder becomes 2
```

They are useful when a variable is being updated repeatedly, especially inside loops:

```c
int sum = 0;

for (int i = 1; i <= 10; i++) {
    sum += i;
}
```

For beginner code, use compound assignment when it makes the update easier to read. If it hides the calculation, write the full version instead.

## Multiple Variables In A `for` Loop

A `for` loop can initialize and update more than one variable using commas:

```c
for (int i = 0, j = 10; i < 10 && j > 1; i++, j--) {
    printf("%d %d\n", i, j);
}
```

Use `&&` when both conditions must remain true.

If multiple conditions should matter, use a logical operator such as `&&` or `||`.

If conditions are separated using commas, C evaluates all of them from left to right, but only takes the final condition seriously when deciding whether the loop should continue:

```c
i < 10, j > 1
```

Here, `i < 10` is checked but its result is ignored. Only `j > 1`, the last condition, controls the loop.

Reversing their positions changes which condition controls the loop:

```c
j > 1, i < 10
```

Now `j > 1` is checked and ignored, while the final condition `i < 10` decides whether the loop continues.

This is different from `i < 10 && j > 1`, where both conditions matter. Using commas in the condition is valid, but logical operators usually make the intended behavior clearer.

See [05multi-var-forLoop.c](05multi-var-forLoop.c).

## Choosing A Loop

| Loop | Useful When |
| --- | --- |
| `while` | The condition controls repetition and the body may run zero times |
| `do...while` | The body must run at least once |
| `for` | A counter or known range controls repetition |

All three loops can often solve the same problem. Choose the form that makes the intended repetition easiest to understand.

## Tricky Results And Common Mistakes

Some loop code is valid C but does not behave the way a beginner may expect.

### Uninitialized Accumulator

Before using a variable to collect a sum or product, give it a starting value:

```c
int sum = 0;
int fact = 1;
```

If `sum` is not initialized, it contains an unknown value, so `sum += i` starts from garbage.

Use `0` for addition and `1` for multiplication.

### Changing And Reading A Variable In The Same Expression

This can produce unexpected or undefined behavior:

```c
printf("%d %d\n", i--, i * 10);
```

The problem is that `i` is changed and also read again inside the same function call. The order is not safe to depend on.

Write it in separate steps:

```c
printf("%d x 10 = %d\n", i, i * 10);
i--;
```

### Comma In A Loop Condition

This condition does not mean both conditions matter:

```c
i < 3, j > 5
```

C checks `i < 3`, ignores that result, then uses only `j > 5`.

If the order is reversed:

```c
j > 5, i < 3
```

Now only `i < 3` controls the loop.

Use logical operators when multiple conditions should control the loop:

```c
i < 3 && j > 5
```

### `do...while` Runs At Least Once

A `do...while` loop runs once before checking its condition. This is useful for menu programs, but it can create wrong logic if the first run should not happen.

For example, when checking whether `2` is prime, a `do...while` loop should not divide by `2` before checking whether any divisor needs to be tested. That is why the prime example first checks whether the loop condition is needed before entering the `do...while` block.

### Prime Numbers Less Than 2

`0`, `1`, and negative numbers are not prime. If the loop only checks divisibility from `2` onward, these values need to be handled before the loop:

```c
if (num < 2) {
    is_prime = 0;
}
```

## Summary

- A loop repeats code, and each repetition is an iteration.
- A loop needs a condition that eventually becomes false unless an infinite loop is intentional.
- `while` checks before the body; `do...while` checks after it.
- `for` keeps initialization, condition, and update together.
- `break` exits the nearest loop.
- `continue` skips the rest of the current iteration.
- Prefix and postfix operators differ when their produced values are used.
- In a comma-separated loop condition, only the final expression controls repetition.
- Compound assignment operators such as `+=` and `*=` update a variable using its current value.
- Initialize sum and product variables before updating them inside loops.
