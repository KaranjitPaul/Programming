# C Pointers

Parent: [C Language](../C-Language.md)  
Previous: [C Functions And Recursion](../05Function&Recursion/C-Function-Recursion.md)  
Next: None

Pointers are variables that store memory addresses. At first they can feel strange because we usually think about values, like `72` or `'a'`, but a pointer focuses on where that value is kept in memory.

Practice files:

- [Basic pointer and address](01pointer.c)
- [Value at address operator](02valueAtAddressOperator.c)
- [Pointer with another data type](03otherTypes.c)
- [Pointer to pointer](04pointerToPointer.c)

This chapter talks only about pointer basics. Function calls using pointers, like call by reference, will be handled later.

## Contents

- [What Is A Pointer?](#what-is-a-pointer)
- [Memory Address](#memory-address)
- [Address Of Operator](#address-of-operator)
- [Declaring A Pointer](#declaring-a-pointer)
- [Value At Address Operator](#value-at-address-operator)
- [Pointer Type Matters](#pointer-type-matters)
- [Address Of A Pointer Variable](#address-of-a-pointer-variable)
- [Pointer To Pointer](#pointer-to-pointer)
- [Printing Pointers](#printing-pointers)
- [Important Points](#important-points)
- [Summary](#summary)

## What Is A Pointer?

A pointer is a variable that stores the address of another variable.

Normal variable:

```c
int i = 72;
```

Pointer variable:

```c
int *j = &i;
```

Here:

- `i` stores the value `72`
- `&i` gives the address of `i`
- `j` stores that address
- `j` is called a pointer because it points to `i`

So the simple meaning of this line is:

```text
j stores the address of i.
```

## Memory Address

Every variable is stored somewhere in memory. That place has an address.

In [01pointer.c](01pointer.c):

```c
int i = 72;
int *j = &i;
```

The program prints:

```c
printf("The address of i: %p\n", &i);
printf("The address of i stored in j: %p\n", j);
```

Both print the same address because `j` is storing the address of `i`.

The actual address will not be the same every time. It depends on how the program is loaded in memory.

## Address Of Operator

The `&` operator means address of.

```c
&i
```

This means:

```text
address of i
```

Do not confuse this with the `&` used in `scanf`.

```c
scanf("%d", &num);
```

In `scanf`, we give the address of `num` because `scanf` needs to put the input value inside that variable. The idea is still the same: `&num` means address of `num`.

## Declaring A Pointer

A pointer is declared using `*`.

```c
int *j;
```

This means `j` can store the address of an `int` variable.

Then:

```c
j = &i;
```

stores the address of `i` in `j`.

You can also write it together:

```c
int *j = &i;
```

Spacing does not change the meaning:

```c
int *j;
int* j;
int * j;
```

All of these are accepted, but `int *j` is often easier to read as:

```text
*j is an int value, so j is a pointer to int.
```

## Value At Address Operator

The `*` operator can also mean value at address.

In [02valueAtAddressOperator.c](02valueAtAddressOperator.c):

```c
int i = 72;
int *j = &i;
```

Here:

```c
*j
```

means:

```text
go to the address stored in j and read the value there
```

Since `j` stores the address of `i`, `*j` gives the value of `i`.

So:

```c
printf("%d\n", *j);
```

prints:

```text
72
```

This is also why:

```c
*(&i)
```

is the same as:

```c
i
```

`&i` gets the address of `i`, then `*` goes to that address and gets the value back.

## Pointer Type Matters

Pointers should match the type of variable they point to.

For an `int`:

```c
int i = 72;
int *j = &i;
```

For a `char`:

```c
char i = 'a';
char *j = &i;
```

In [03otherTypes.c](03otherTypes.c), `j` is a `char *` because it stores the address of a `char`.

The type matters because the pointer must know how to read the value stored at that address.

For example:

- `int *` reads an integer value
- `char *` reads a character value
- `float *` reads a floating-point value

## Address Of A Pointer Variable

A pointer is also a variable. That means it also has its own address.

In [01pointer.c](01pointer.c):

```c
printf("The address of j is: %p\n", &j);
```

Here:

- `j` gives the address stored inside `j`
- `&j` gives the address of the pointer variable `j` itself

These are different things.

Simple way to think:

```text
j  -> address of i
&j -> address of j
```

## Pointer To Pointer

A pointer to pointer stores the address of another pointer.

In [04pointerToPointer.c](04pointerToPointer.c):

```c
int i = 72;
int *j = &i;
int **k = &j;
```

Here:

- `i` stores `72`
- `j` stores the address of `i`
- `k` stores the address of `j`

So:

```c
*j
```

gives the value of `i`.

```c
*k
```

gives the value stored in `j`, which is the address of `i`.

```c
**k
```

goes two levels:

```text
k -> j -> i
```

So `**k` gives the value of `i`.

## Printing Pointers

Addresses should be printed using `%p`.

```c
printf("%p\n", &i);
```

For now, remember this simply: use `%p` when printing addresses.

Use these formats for the examples in this chapter:

| Thing | Format |
| --- | --- |
| `int` value | `%d` |
| `char` value | `%c` |
| Address / pointer | `%p` |

Avoid printing addresses with `%d` or `%u`. Addresses are not normal integer values, and using the wrong format can give warnings or confusing output.

## Important Points

- A pointer stores an address, not the normal value directly.
- `&` means address of.
- `*` in declaration creates a pointer variable.
- `*` outside declaration usually means value at address.
- A pointer should match the data type it points to.
- `j` and `&j` are different: one is the stored address, the other is the pointer variable's own address.
- `int **k` is a pointer to pointer.
- Do not worry about using pointers in function calls yet. That will make more sense after the basic pointer idea feels comfortable.

## Summary

- `int *j = &i;` means `j` stores the address of `i`.
- `&i` gives the address of `i`.
- `*j` gives the value stored at the address inside `j`.
- `*(&i)` gives back the value of `i`.
- `int **k = &j;` means `k` stores the address of pointer `j`.
- `**k` reaches the original value through two pointer levels.
