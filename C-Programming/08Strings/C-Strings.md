# C Strings

Parent: [C Language](../C-Language.md)  
Previous: [C Arrays](../07Arrays/C-Arrays.md)  
Next: None

A string in C is a character array that ends with a special character called the null character, written as `'\0'`. Strings are closely connected to arrays and pointers, so this chapter continues naturally after arrays.

Practice files:

- [String initialization](01string.c)
- [String input using scanf](02scanfString.c)
- [String output using puts](03gets-puts.c)
- [String input using fgets](04fgets.c)
- [String using pointer](05stringUsingPointer.c)
- [String length using strlen](06strlen.c)
- [Copy string using strcpy](07strcpy.c)
- [Join strings using strcat](08strcat.c)

## Contents

- [What Is A String?](#what-is-a-string)
- [Null Character](#null-character)
- [String As A Character Array](#string-as-a-character-array)
- [Two Ways To Initialize A String](#two-ways-to-initialize-a-string)
- [Printing Strings With `%s`](#printing-strings-with-s)
- [Input With `scanf`](#input-with-scanf)
- [Why `gets` Should Not Be Used](#why-gets-should-not-be-used)
- [Input With `fgets`](#input-with-fgets)
- [Using `printf` And `puts`](#using-printf-and-puts)
- [Removing Newline From `fgets`](#removing-newline-from-fgets)
- [String Using Pointer](#string-using-pointer)
- [String Library Header](#string-library-header)
- [`strlen`](#strlen)
- [`strcpy`](#strcpy)
- [`strcat`](#strcat)
- [Buffer Size And Safety](#buffer-size-and-safety)
- [Important Points](#important-points)
- [Summary](#summary)

## What Is A String?

A string is a sequence of characters.

Example:

```c
"HELLO"
```

In C, a string is stored as a character array:

```c
char s[] = "HELLO";
```

Even though it looks like one word, internally it is stored character by character.

## Null Character

C needs to know where a string ends. For that, it uses the null character:

```c
'\0'
```

So this string:

```c
"HELLO"
```

is stored like:

```text
H  E  L  L  O  \0
```

The `'\0'` marks the end of the string.

Without `'\0'`, C would not know where to stop while printing with `%s`.

## String As A Character Array

From [01string.c](01string.c):

```c
char s[] = {'H', 'E', 'L', 'L', 'O', '\0'};
```

This is a character array where the last element is `'\0'`.

Memory idea:

```text
s[0] = 'H'
s[1] = 'E'
s[2] = 'L'
s[3] = 'L'
s[4] = 'O'
s[5] = '\0'
```

So the array needs `6` spaces to store a `5` letter word.

One extra space is needed for `'\0'`.

## Two Ways To Initialize A String

### Manual Character Array

```c
char s[] = {'H', 'E', 'L', 'L', 'O', '\0'};
```

Here we manually add `'\0'`.

### Double Quote String

```c
char s2[] = "WORLD!";
```

Here C automatically adds `'\0'` at the end.

So this:

```c
char s2[] = "WORLD!";
```

is like:

```text
W O R L D ! \0
```

For normal strings, double quotes are easier and cleaner.

## Printing Strings With `%s`

To print a string using `printf`, use `%s`.

```c
printf("%s", s);
```

`%s` tells `printf`:

```text
print characters until '\0' is found
```

That is why the null character matters.

## Input With `scanf`

From [02scanfString.c](02scanfString.c):

```c
char firstName[20];
scanf("%19s", firstName);
```

For strings, we usually do not write `&firstName`.

Reason:

```c
firstName
```

already behaves like the address of the first character:

```c
&firstName[0]
```

So this is correct:

```c
scanf("%19s", firstName);
```

The `19` means:

```text
read at most 19 characters
```

The array size is `20`, so one space is left for `'\0'`.

### Limitation Of `scanf("%s")`

`scanf("%s")` reads only one word.

If input is:

```text
Karanjit Paul
```

then first `%s` reads:

```text
Karanjit
```

and stops at the space.

That is why [02scanfString.c](02scanfString.c) takes first name and last name separately.

## Why `gets` Should Not Be Used

The file name [03gets-puts.c](03gets-puts.c) mentions `gets`, but the code uses `fgets`.

Old C programs used:

```c
gets(fullName);
```

But `gets` is unsafe because it does not know the size of the array. If the user enters too many characters, it can write outside the array.

That can break the program.

So modern C should use:

```c
fgets(fullName, 25, stdin);
```

Simple rule:

```text
Do not use gets. Use fgets.
```

## Input With `fgets`

From [04fgets.c](04fgets.c):

```c
char name[100];
fgets(name, 10, stdin);
```

`fgets` takes three things:

```c
fgets(array_name, size, stdin);
```

Meaning:

- `array_name` - where the input will be stored
- `size` - maximum storage limit
- `stdin` - input from keyboard

If size is `10`, `fgets` reads at most `9` characters and keeps one space for `'\0'`.

So:

```c
fgets(name, 10, stdin);
```

can store:

```text
9 input characters + '\0'
```

This is safer than `gets` because it respects the array size.

## Using `printf` And `puts`

Both can print strings.

### `printf`

```c
printf("%s\n", name);
```

`printf` prints exactly according to the format string. If you want a newline, you add `\n`.

### `puts`

```c
puts(name);
```

`puts` prints the string and automatically adds a newline at the end.

So:

```c
puts(name);
```

is like:

```text
print name, then move to next line
```

One small thing: if the string already contains `\n` from `fgets`, then `puts` may appear to add an extra blank line.

## Removing Newline From `fgets`

When the user presses Enter, `fgets` may store that newline character `\n` inside the string.

In [03gets-puts.c](03gets-puts.c):

```c
fullName[strcspn(fullName, "\n")] = '\0';
```

This removes the newline if it exists.

Simple meaning:

```text
Find '\n' in fullName and replace it with '\0'.
```

This makes the string cleaner before printing with `puts`.

This line uses `strcspn`, which comes from:

```c
#include <string.h>
```

You do not need to master `strcspn` right now. Just remember it is a common way to remove the newline after `fgets`.

## String Using Pointer

From [05stringUsingPointer.c](05stringUsingPointer.c):

```c
char str[] = "Cant be re-initialized";
char *canChange;
canChange = "Karanjit";
```

There are two different ideas here.

### Character Array String

```c
char str[] = "Cant be re-initialized";
```

This creates an array and stores the characters inside it.

You can change individual characters:

```c
str[0] = 'c';
```

But you cannot reassign the whole array like:

```c
str = "New text";
```

Array name is fixed.

### Pointer To String Literal

```c
char *canChange;
canChange = "Karanjit";
canChange = "Paul";
```

Here `canChange` is a pointer. It can point to one string literal first, then point to another string literal later.

So pointer can be re-pointed:

```text
canChange -> "Karanjit"
canChange -> "Paul"
```

Important beginner note:

```text
Pointer can point somewhere else, but string literal text itself should not be modified.
```

So this should be avoided:

```c
canChange[0] = 'X';
```

## String Library Header

Some string functions come from:

```c
#include <string.h>
```

Examples:

- `strlen`
- `strcpy`
- `strcat`
- `strcspn`

These functions help work with strings without writing everything manually.

## `strlen`

From [06strlen.c](06strlen.c):

```c
strlen(name)
```

`strlen` returns the number of characters before `'\0'`.

Example:

```c
char name[] = "Karan";
```

Length is:

```text
5
```

because:

```text
K a r a n \0
```

`'\0'` is not counted.

But if input comes from `fgets`, the newline may be counted:

```text
Karan\n\0
```

Then `strlen` may count `\n` too.

`strlen` returns `size_t`, so the clean modern format specifier is:

```c
%zu
```

Example:

```c
printf("%zu\n", strlen(name));
```

Some older Windows compilers may warn on `%zu`. In that case, this beginner-friendly form also works:

```c
printf("%lu\n", (unsigned long)strlen(name));
```

## `strcpy`

From [07strcpy.c](07strcpy.c):

```c
strcpy(target, source);
```

This copies the string from `source` into `target`.

Simple meaning:

```text
target becomes a copy of source
```

Example:

```c
char source[30] = "Hello";
char target[30];

strcpy(target, source);
```

After copying:

```text
target = "Hello"
```

Important: `target` must have enough space to store the copied string.

## `strcat`

From [08strcat.c](08strcat.c):

```c
strcat(firstName, lastName);
```

`strcat` joins the second string at the end of the first string.

Example:

```c
char firstName[30] = "Karanjit";
char lastName[] = " Paul";

strcat(firstName, lastName);
```

After this:

```text
firstName = "Karanjit Paul"
```

Important: the first array must have enough extra space.

This is safe:

```c
char firstName[30] = "Karanjit";
```

This is not safe for `strcat`:

```c
char firstName[] = "Karanjit";
```

because it creates only enough space for:

```text
Karanjit\0
```

There is no extra space for `" Paul"`.

## Buffer Size And Safety

A buffer is just an area of memory used to store data.

For strings:

```c
char name[20];
```

`name` is a buffer that can hold `20` characters total.

But because a string needs `'\0'`, it can hold at most:

```text
19 visible characters + '\0'
```

Important habits:

- use width in `scanf`, like `%19s` for `char name[20]`
- prefer `fgets` for full-line input
- make destination arrays large enough before `strcpy`
- make first array large enough before `strcat`
- remember that `fgets` may store `\n`

## Important Points

- A C string is a `char` array ending with `'\0'`.
- Double quotes add `'\0'` automatically.
- `%s` prints characters until `'\0'`.
- `scanf("%s", str)` reads one word only.
- For string input with `scanf`, do not use `&` before the array name.
- `gets` is unsafe and should not be used.
- `fgets` is safer because it knows the array size.
- `puts` automatically adds a newline.
- `strlen` counts characters before `'\0'`.
- `strcpy` copies one string into another.
- `strcat` joins one string at the end of another.
- Array strings cannot be reassigned as a whole.
- String pointers can point to different string literals.

## Summary

- `char s[] = "HELLO";` creates a string.
- Internally, it is stored as `H E L L O \0`.
- `'\0'` marks the end of the string.
- `scanf("%19s", name);` reads one word safely into `char name[20]`.
- `fgets(name, 20, stdin);` can read spaces and respects the buffer size.
- `printf("%s", name);` prints a string using a format specifier.
- `puts(name);` prints a string and adds a newline.
- `strlen(name)` gives the string length before `'\0'`.
- `strcpy(target, source)` copies a string.
- `strcat(first, second)` joins `second` at the end of `first`.
