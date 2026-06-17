# C Projects

Parent: [C Language](../C-Language.md)  
Previous: None
Next: None

This folder stores small C projects that combine multiple concepts from earlier chapters.

Project code can be a little playful, but the documentation here stays formal so the learning is easy to review later.

## Contents

- [Random Number Guessing Game](#1-random-number-guessing-game)
- [Random Number Generation](#random-number-generation)
- [Limiting The Random Number Range](#limiting-the-random-number-range)

## Projects

### 1. Random Number Guessing Game

Code: [01project.c](01project.c)

This project generates a random number between `1` and `100`, then gives the user up to `10` attempts to guess it.

The program gives feedback after each guess:

- If the guess is lower than the random number, it asks the user to try higher.
- If the guess is higher than the random number, it asks the user to try lower.
- If the guess is correct, it prints the number of attempts used.
- If all attempts are used, it reveals the correct number.

Concepts practiced:

- Header files: `stdio.h`, `stdlib.h`, and `time.h`
- Random number generation using `rand()`
- Random seed setup using `srand(time(0))`
- Modulus `%` for limiting the random number range
- `for` loop with a fixed number of attempts
- `if`, `else if`, and `else` decision flow
- Range validation for user input
- Early program exit using `return 0`

New learning from this project:

- A loop can represent limited chances in a game-like program.
- `return 0` can end the program early after the player wins.

### Random Number Generation

`rand()` produces a pseudo-random integer.

Pseudo-random means the number looks random, but it is actually produced by a formula inside C. Each call to `rand()` gives the next number from that generated sequence:

```c
int value = rand();
```

If the program always starts the sequence from the same point, it can produce the same numbers every time the program runs. That is not useful for a guessing game because the answer may repeat.

`srand()` sets the starting point, also called the seed, for the random sequence:

```c
srand(1);
```

Using the same seed can produce the same sequence again. To make the starting point change, the project uses the current time:

```c
srand(time(0));
```

`time(0)` returns the current time in seconds. Since that value changes as time passes, `srand(time(0))` usually gives a different random sequence each time the program starts.

### Limiting The Random Number Range

`rand()` can produce a large integer, but the guessing game needs only numbers from `1` to `100`.

The modulus operator `%` gives the remainder after division:

```c
rand() % 100
```

When any integer is divided by `100`, the possible remainders are from `0` to `99`. So `rand() % 100` gives a value in this range:

```text
0 to 99
```

The game needs `1` to `100`, so `1` is added:

```c
(rand() % 100) + 1
```

Now the range shifts:

```text
0 becomes 1
1 becomes 2
...
99 becomes 100
```

So this line:

```c
int random_number = (rand() % 100) + 1;
```

means:

```text
Generate a pseudo-random number between 1 and 100.
```

Possible future improvements:

- Handle invalid non-number input safely.
- Let the user choose the guessing range.
- Let the user choose the number of attempts.
- Add a replay option using a loop.
