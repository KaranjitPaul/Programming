# C Arrays

Parent: [C Language](../C-Language.md)  
Previous: [C Pointers](../06Pointers/C-Pointers.md)  
Next: None

An array stores multiple values of the same type under one name. Instead of creating many separate variables like `mark1`, `mark2`, `mark3`, an array lets us store related values together and access them using indexes.

Practice files:

- [Basic array declaration and initialization](01array.c)
- [Student marks using array input](02quiz.c)
- [Array memory address and pointer movement](03memoryAddress.c)
- [Accessing arrays using pointers](04accessArrayByPointer.c)
- [Passing array to function](05passingArrayInFunction.c)
- [Multidimensional arrays](06multiDimentionalArray.c)

## Contents

- [What Is An Array?](#what-is-an-array)
- [Why Arrays Are Useful](#why-arrays-are-useful)
- [Declaring An Array](#declaring-an-array)
- [Array Indexing](#array-indexing)
- [Assigning Values To An Array](#assigning-values-to-an-array)
- [Array Initialization](#array-initialization)
- [Partial Initialization](#partial-initialization)
- [Reading And Printing Arrays With Loops](#reading-and-printing-arrays-with-loops)
- [Array Bounds](#array-bounds)
- [Array Memory Layout](#array-memory-layout)
- [Array Name And First Element Address](#array-name-and-first-element-address)
- [Pointer Arithmetic With Arrays](#pointer-arithmetic-with-arrays)
- [Accessing Arrays Using Pointers](#accessing-arrays-using-pointers)
- [Passing Arrays To Functions](#passing-arrays-to-functions)
- [Multidimensional Arrays](#multidimensional-arrays)
- [2D Array Memory Layout](#2d-array-memory-layout)
- [3D Array Memory Layout](#3d-array-memory-layout)
- [N-Dimensional Array Memory Layout](#n-dimensional-array-memory-layout)
- [Important Points](#important-points)
- [Summary](#summary)

## What Is An Array?

An array is a collection of values of the same data type.

Example:

```c
int marks[5];
```

This creates an integer array named `marks` that can store `5` integer values.

Simple meaning:

```text
marks can store 5 int values together.
```

## Why Arrays Are Useful

Without an array, storing marks of five students may look like:

```c
int mark1;
int mark2;
int mark3;
int mark4;
int mark5;
```

With an array:

```c
int marks[5];
```

Now all five values are grouped together.

Arrays are useful when:

- values belong to the same category
- the number of values is fixed or known
- we want to use loops to process many values
- we want cleaner code instead of many separate variables

## Declaring An Array

Basic syntax:

```c
data_type array_name[size];
```

Example from [01array.c](01array.c):

```c
int arr[2];
```

This means:

```text
Create an int array named arr with 2 elements.
```

Because the size is `2`, the valid elements are:

```c
arr[0]
arr[1]
```

## Array Indexing

Array index starts from `0`, not `1`.

For:

```c
int arr[2];
```

The elements are:

| Element | Meaning |
| --- | --- |
| `arr[0]` | first element |
| `arr[1]` | second element |

The last valid index is always:

```text
size - 1
```

So for an array of size `5`, valid indexes are:

```text
0, 1, 2, 3, 4
```

## Assigning Values To An Array

In [01array.c](01array.c):

```c
int arr[2];
arr[0] = 11;
arr[1] = 22;
```

Here:

- `arr[0]` stores `11`
- `arr[1]` stores `22`

You can assign array values one by one like normal variables.

## Array Initialization

An array can be initialized when it is created:

```c
int arr1[] = {33, 44, 55};
```

Here the size is not written manually. C counts the values and creates an array of size `3`.

So this:

```c
int arr1[] = {33, 44, 55};
```

is similar to:

```c
int arr1[3] = {33, 44, 55};
```

## Partial Initialization

In [01array.c](01array.c):

```c
int arr2[4] = {66, 77, 88};
```

The array size is `4`, but only `3` values are given.

C fills the remaining element with `0`.

So `arr2` becomes:

| Element | Value |
| --- | --- |
| `arr2[0]` | `66` |
| `arr2[1]` | `77` |
| `arr2[2]` | `88` |
| `arr2[3]` | `0` |

Then your code changes:

```c
arr2[2] = 99;
```

After that:

| Element | Value |
| --- | --- |
| `arr2[0]` | `66` |
| `arr2[1]` | `77` |
| `arr2[2]` | `99` |
| `arr2[3]` | `0` |

## Reading And Printing Arrays With Loops

[02quiz.c](02quiz.c) uses an array for marks of five students:

```c
int student[5];
```

Input loop:

```c
for (int i = 0; i < 5; i++) {
    scanf("%d", &student[i]);
}
```

Output loop:

```c
for (int i = 0; i < 5; i++) {
    printf("Student(%d) marks: %d\n", i + 1, student[i]);
}
```

Notice two things:

- `student[i]` accesses each array element.
- `i + 1` is only for user-friendly display, because users usually count students from `1`.

The actual array indexes are still `0` to `4`.

## Array Bounds

Array bounds means the valid index range of an array.

For:

```c
int arr[2];
```

valid indexes are:

```text
0 and 1
```

So this is valid:

```c
arr[0]
arr[1]
```

But these are invalid:

```c
arr[2]
arr[3]
```

C does not automatically stop you from using invalid indexes. If you access outside the array, the program may read nearby memory and produce strange values.

That is called undefined behavior.

Your updated [01array.c](01array.c) protects against this using conditions:

```c
if (i < 2)
    printf("arr(%d): %d\n", i, arr[i]);

if (i < 3)
    printf("arr1(%d): %d\n", i, arr1[i]);
```

This keeps `arr` and `arr1` inside their valid index range.

## Array Memory Layout

Array elements are stored continuously in memory.

For:

```c
int arr[3] = {12, 15, 36};
```

memory is arranged like:

```text
arr[0]  arr[1]  arr[2]
 12      15      36
```

If an `int` takes `4` bytes and `arr[0]` starts at address `1000`, then:

| Element | Example Address |
| --- | --- |
| `arr[0]` | `1000` |
| `arr[1]` | `1004` |
| `arr[2]` | `1008` |

The exact address changes every run, but the gap between two `int` elements is usually `sizeof(int)`.

Formula:

```text
address of arr[i] = base address + i * sizeof(element_type)
```

For an `int` array:

```text
address of arr[i] = base address + i * sizeof(int)
```

[03memoryAddress.c](03memoryAddress.c) prints addresses of array elements to show this.

## Array Name And First Element Address

For most expressions:

```c
arr
```

behaves like the address of the first element:

```c
&arr[0]
```

So these ideas are closely related:

```c
int *a = &arr[0];
int *a = arr;
```

Both point to the first element of the array.

Important beginner note:

```text
arr behaves like &arr[0] in many places, but arr itself is not a normal pointer variable.
```

That means you can do this:

```c
int *ptr = arr;
ptr++;
```

But you cannot do this:

```c
arr++;
```

because the array name is fixed.

## Pointer Arithmetic With Arrays

In [03memoryAddress.c](03memoryAddress.c):

```c
int *a = &arr[1];
++a;
```

If `a` points to `arr[1]`, then `++a` moves it to the next `int` element.

So now:

```c
*a
```

gives:

```c
arr[2]
```

Pointer arithmetic moves according to the pointer type.

For `int *`:

```text
ptr + 1 moves by sizeof(int)
```

For `char *`:

```text
ptr + 1 moves by sizeof(char)
```

Usually:

```text
int jumps by 4 bytes
char jumps by 1 byte
```

But it is better to think in terms of `sizeof(type)`, not fixed numbers.

## Accessing Arrays Using Pointers

[04accessArrayByPointer.c](04accessArrayByPointer.c) uses:

```c
int *ptr = &num[0];
char *chPtr = &ch[0];
```

Then:

```c
*ptr
```

accesses the current integer value.

```c
ptr++;
```

moves to the next integer element.

The expression:

```c
*ptr++
```

means:

```text
use the value at ptr first, then move ptr to the next element
```

So inside a loop, `*ptr++` can print the current element and prepare the pointer for the next element.

Useful relationships:

```c
arr[i] == *(arr + i)
```

and:

```c
ptr[i] == *(ptr + i)
```

So array indexing and pointer arithmetic are connected.

## Passing Arrays To Functions

[05passingArrayInFunction.c](05passingArrayInFunction.c) passes an array to a function:

```c
printMarks(marks, 5);
```

The function receives:

```c
void printMarks(int marksArray[], int arraySize)
```

Inside function parameters:

```c
int marksArray[]
```

behaves like:

```c
int *marksArray
```

So when an array is passed to a function, the function receives access to the original array elements.

This is why array size should be passed separately:

```c
printMarks(marks, 5);
```

The function does not automatically know how many elements the original array has.

Simple rule:

```text
When passing an array to a function, also pass its size.
```

## Multidimensional Arrays

A multidimensional array is an array with more than one index.

In [06multiDimentionalArray.c](06multiDimentionalArray.c):

```c
int arr1[3] = {12, 24, 35};
int arr2[2][3] = {{24, 54, 42}, {34, 45, 75}};
int arr3[2][3][2] = {{{2, 4}, {5, 6}, {7, 8}}, {{9, 10}, {11, 12}, {13, 14}}};
```

Here:

- `arr1` is a 1D array
- `arr2` is a 2D array
- `arr3` is a 3D array

## 2D Array Memory Layout

A 2D array can be imagined like rows and columns.

Example:

```c
int arr2[2][3] = {
    {24, 54, 42},
    {34, 45, 75}
};
```

Visual form:

```text
row 0: 24  54  42
row 1: 34  45  75
```

Access:

```c
arr2[row][column]
```

Examples:

```c
arr2[0][0] == 24
arr2[0][1] == 54
arr2[0][2] == 42
arr2[1][0] == 34
```

But memory is still continuous. C stores 2D arrays in row-major order:

```text
arr2[0][0], arr2[0][1], arr2[0][2], arr2[1][0], arr2[1][1], arr2[1][2]
```

So if `arr2[0][0]` starts at address `1000` and `int` is `4` bytes:

| Element | Offset | Example Address |
| --- | --- | --- |
| `arr2[0][0]` | `0 * 4` | `1000` |
| `arr2[0][1]` | `1 * 4` | `1004` |
| `arr2[0][2]` | `2 * 4` | `1008` |
| `arr2[1][0]` | `3 * 4` | `1012` |
| `arr2[1][1]` | `4 * 4` | `1016` |
| `arr2[1][2]` | `5 * 4` | `1020` |

Formula for:

```c
int arr2[rows][cols];
```

address of:

```c
arr2[i][j]
```

is:

```text
base address + ((i * cols) + j) * sizeof(int)
```

For `arr2[2][3]`, `cols` is `3`.

So:

```text
arr2[1][2]
= base + ((1 * 3) + 2) * sizeof(int)
= base + 5 * sizeof(int)
```

## 3D Array Memory Layout

A 3D array uses three indexes.

Example:

```c
int arr3[2][3][2];
```

Think of it as:

```text
2 blocks, each block has 3 rows, each row has 2 columns
```

Index style:

```c
arr3[block][row][column]
```

From [06multiDimentionalArray.c](06multiDimentionalArray.c):

```c
int arr3[2][3][2] = {
    {{2, 4}, {5, 6}, {7, 8}},
    {{9, 10}, {11, 12}, {13, 14}}
};
```

Visual idea:

```text
block 0:
row 0: 2   4
row 1: 5   6
row 2: 7   8

block 1:
row 0: 9   10
row 1: 11  12
row 2: 13  14
```

Memory order is still continuous:

```text
arr3[0][0][0], arr3[0][0][1],
arr3[0][1][0], arr3[0][1][1],
arr3[0][2][0], arr3[0][2][1],
arr3[1][0][0], arr3[1][0][1],
...
```

Formula for:

```c
int arr3[d1][d2][d3];
```

address of:

```c
arr3[i][j][k]
```

is:

```text
base address + ((i * d2 * d3) + (j * d3) + k) * sizeof(int)
```

For:

```c
int arr3[2][3][2];
```

`d2 = 3` and `d3 = 2`.

So:

```text
arr3[1][2][1]
= base + ((1 * 3 * 2) + (2 * 2) + 1) * sizeof(int)
= base + (6 + 4 + 1) * sizeof(int)
= base + 11 * sizeof(int)
```

That means `arr3[1][2][1]` is the 12th integer in memory, because counting starts from offset `0`.

## N-Dimensional Array Memory Layout

The same idea continues for more dimensions.

For:

```c
type arr[d0][d1][d2]...[dn];
```

C still stores everything continuously in row-major order.

To find the position of:

```c
arr[i0][i1][i2]...[in]
```

the earlier indexes have bigger jumps, because they skip whole blocks of later dimensions.

General idea:

```text
offset =
i0 * d1 * d2 * ... * dn
+ i1 * d2 * ... * dn
+ i2 * d3 * ... * dn
+ ...
+ in
```

Final address:

```text
base address + offset * sizeof(type)
```

For beginners, the important idea is:

```text
The rightmost index changes fastest.
```

Example in 3D:

```text
arr3[0][0][0]
arr3[0][0][1]
arr3[0][1][0]
arr3[0][1][1]
```

The last index moves first. Then row changes. Then block changes.

## Important Points

- An array stores multiple values of the same type.
- Array indexing starts from `0`.
- Last valid index is `size - 1`.
- Partial initialization fills remaining elements with `0`.
- Local arrays without initialization may contain garbage values until assigned.
- Array elements are stored continuously in memory.
- `arr` often behaves like `&arr[0]`.
- `arr[i]` is related to `*(arr + i)`.
- Pointer arithmetic moves by the size of the pointed type.
- When passing arrays to functions, pass the size separately.
- Multidimensional arrays are also stored continuously.
- C stores multidimensional arrays in row-major order.
- The rightmost index changes fastest in memory.

## Summary

- `int arr[5];` creates an array of five integers.
- `arr[0]` is the first element.
- `arr[4]` is the last element of an array of size `5`.
- Accessing outside the array causes undefined behavior.
- `int arr2[4] = {66, 77, 88};` makes `arr2[3]` equal to `0`.
- `&arr[i]` gives the address of the element at index `i`.
- `arr` usually behaves like the address of `arr[0]`.
- `ptr++` moves to the next array element according to pointer type.
- A 2D array like `arr2[2][3]` is stored row by row in memory.
- A 3D array like `arr3[2][3][2]` is stored block by block, row by row, column by column.
