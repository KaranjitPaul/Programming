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
- [Function call with pointer](05functionCall.c)
- [Swapping values using pointers](06swap.c)

This chapter starts with pointer basics, then uses pointers with functions to show how a function can work with original variables through their addresses.

## Contents

- [What Is A Pointer?](#what-is-a-pointer)
- [Memory Address](#memory-address)
- [Address Of Operator](#address-of-operator)
- [Declaring A Pointer](#declaring-a-pointer)
- [Value At Address Operator](#value-at-address-operator)
- [Pointer Type Matters](#pointer-type-matters)
- [Address Of A Pointer Variable](#address-of-a-pointer-variable)
- [Pointer To Pointer](#pointer-to-pointer)
- [Multiple Pointer Levels](#multiple-pointer-levels)
- [Function Calls With Values And Addresses](#function-calls-with-values-and-addresses)
- [Changing Original Variables Through Pointers](#changing-original-variables-through-pointers)
- [Swapping Two Values](#swapping-two-values)
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

## Multiple Pointer Levels

You can use more than one `*` or `&` when the types match.

From [04pointerToPointer.c](04pointerToPointer.c):

```c
int i = 72;
int *j = &i;
int **k = &j;
int ***n = &k;
```

Read it step by step:

- `j` stores the address of `i`
- `k` stores the address of `j`
- `n` stores the address of `k`

So the chain looks like:

```text
n -> k -> j -> i
```

That means:

```c
***n
```

reaches the value of `i`.

You can also combine `*` and `&` in one expression:

```c
**(&j)
```

Here is the simple breakdown:

```text
&j     -> address of j
*(&j)  -> value at address of j, so it becomes j
**(&j) -> value at address stored in j, so it becomes i
```

So if `i` is `72`, then `**(&j)` gives `72`.

There is no small fixed limit like "only one star" or "only two stars". C allows multiple pointer levels if the type is written correctly. But in real code, too many levels become hard to understand, so most beginner programs should stay around one or two levels unless there is a clear reason.

Common pattern:

| Expression | Meaning |
| --- | --- |
| `i` | value of `i` |
| `&i` | address of `i` |
| `j` | address stored in `j` |
| `*j` | value at address stored in `j` |
| `&j` | address of pointer variable `j` |
| `*(&j)` | same as `j` |
| `**(&j)` | same as `*j`, so it gives value of `i` |
| `***n` | reaches `i` through `n -> k -> j -> i` |

## Function Calls With Values And Addresses

In [05functionCall.c](05functionCall.c), two functions are used to compare what happens when a normal value is sent and when an address is sent.

These two styles are usually called:

- **Call by value** - sending normal values to a function
- **Call by reference** - sending addresses so the function can work with original variables

Small C note: C technically passes everything by value. So in true C wording, "call by reference" means we pass the address by value and use pointers to reach the original variable. But while learning, saying call by value and call by reference is okay as long as the meaning is clear.

### Call By Value

```c
int sum_by_value(int a, int b) {
    a = 5;

    return a + b;
}
```

When this function is called:

```c
sum_by_value(a, b);
```

the function receives copies of the values. This is called **call by value**.

If `a` in `main` is `2`, then the function receives a copied `a`. Changing that copied `a` to `5` does not change the original `a` in `main`.

Simple way to think:

```text
main's a  -> original value
function a -> copied value
```

So after this call, the original `a` is still `2`.

### Call By Reference

```c
int sum_by_reference(int *a, int *b) {
    *a = 10;

    return *a + *b;
}
```

When this function is called:

```c
sum_by_reference(&a, &b);
```

we are not sending the normal values directly. We are sending the addresses of `a` and `b`. This is commonly called **call by reference**.

Inside the function:

```c
*a = 10;
```

means:

```text
go to the address stored in pointer a and put 10 there
```

That is why the original `a` in `main` changes.

## Changing Original Variables Through Pointers

A function normally cannot directly change a variable from `main` if it receives only a copy.

But if the function receives an address, it can use `*` to change the value at that address.

Example:

```c
int a = 2;
sum_by_reference(&a, &b);
```

Here:

- `&a` sends the address of `a`
- `int *a` receives that address
- `*a = 10` changes the value stored at that address

So the original variable changes because the function is not working only with a copy anymore.

This is one major reason pointers are useful in C.

## Swapping Two Values

[06swap.c](06swap.c) uses pointers to swap two original variables.

The function receives addresses:

```c
void swap(int *a, int *b)
```

The call sends addresses:

```c
swap(&a, &b);
```

Inside the function, `*a` and `*b` mean the original values stored at those addresses.

Current code:

```c
*a = *a + *b;
*b = *a - *b;
*a = *a - *b;
```

If `a = 10` and `b = 12`:

```text
*a = 10 + 12 = 22
*b = 22 - 12 = 10
*a = 22 - 10 = 12
```

After this:

```text
a = 12
b = 10
```

This works for the small integer values in the example. In real programs, using a temporary variable is usually safer and easier to read, because addition can overflow if numbers are very large.

The main pointer lesson is not the math trick. The main lesson is this:

```text
Pointers let the function swap the original variables from main.
```

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
- `int ***n = &k;` is possible because `n` stores the address of `k`.
- More stars mean more levels to travel through, but too many levels can make code confusing.
- If a function receives normal values, it works with copies.
- If a function receives addresses, it can use pointers to work with original variables.
- `swap(&a, &b)` sends the addresses of `a` and `b`, so the function can change both original values.

## Summary

- `int *j = &i;` means `j` stores the address of `i`.
- `&i` gives the address of `i`.
- `*j` gives the value stored at the address inside `j`.
- `*(&i)` gives back the value of `i`.
- `int **k = &j;` means `k` stores the address of pointer `j`.
- `**k` reaches the original value through two pointer levels.
- `**(&j)` first gets the address of `j`, then comes back through it to reach the value of `i`.
- `int ***n = &k;` creates one more pointer level above `k`.
- Passing `&a` to a function gives the function access to the original variable's address.
- A function can change the original value by using `*` on the received pointer.
- Swapping with pointers works because the function changes the values at the original addresses.
