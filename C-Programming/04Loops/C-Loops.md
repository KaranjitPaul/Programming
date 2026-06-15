# C Loops

Loops repeat a block of code while a condition allows it. They are useful when the same action must happen several times, such as printing a sequence, checking multiple values, or repeating a menu until the user chooses to exit.

Practice files:

- [`while` loop](01whileLoop.c)
- [`do...while` loop](02do-whileLoop.c)
- [`for` loop](03forLoop.c)
- [`continue` and `break`](04continue-break.c)
- [Multiple variables in a `for` loop](05multi-var-forLoop.c)
- [Increment and decrement iteration](06iteration.c)

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

## Summary

- A loop repeats code, and each repetition is an iteration.
- A loop needs a condition that eventually becomes false unless an infinite loop is intentional.
- `while` checks before the body; `do...while` checks after it.
- `for` keeps initialization, condition, and update together.
- `break` exits the nearest loop.
- `continue` skips the rest of the current iteration.
- Prefix and postfix operators differ when their produced values are used.
- In a comma-separated loop condition, only the final expression controls repetition.
