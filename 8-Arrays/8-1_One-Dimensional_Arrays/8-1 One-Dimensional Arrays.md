# 8.1 One-Dimensional Arrays

***scalar*** variables only hold a single data item.

***aggragate*** variables can store collections of values.

There are two kinds of aggragate varialbes in C: arrays and structures.

An ***array*** is a data structure containing a number of data values, all which have the same type.

Values are called ***elements***. Can be individually accessed by their index.

Declare an array `a` to have 10 elements of type `int`:

```c
int a[10];
```

Elements of an array can be any type.

The length of the array can be specified by any (integer) constant expression.

Using a macro to define the length of an array is good practice; array lengths may need to be adjusted when program is later changed.

```c
#define N 10
...
int a[N];
```

---

## Array Subscripting

***Subscripting*** or ***indexing***: accessing elements of an array:

```c
a[0] a[1] a[2]...
```

Arrays are numbered starting at 0 to `n`-1.

Expressions of the form `a[i]` are lvalues, so they can be used the same way as ordinary variables:

```c
a[0] = 1;
printf("%d\n", a[5]);
++a[i];
```

If an array contains elements of type *T*, then each element of the array is treated as if it were a variable of type *T*.

Many programs contain for loops that perform some operation on every element of an array:

### idioms

```c
for (i = 0; i < N; i++)
    a[i] = 0;               // clears a
```

```c
for (i = 0; i < N; i++)
    scanf("%d", &a[i]);     // reads data into a
```

```c
for (i = 0; i < N; i++)
    sum += a[i];            // sums the elements of a
```

---

### !!! PITFALL WARNING !!!

C doesn't require that subscript (index) bounds be checked; if a subscript goes out of range, behavior is undefined.

That is, accessing an array outside the range of 0 to `n` - 1 (commonly `a[n]`).

```c
int a[10], i;

for (i = 1; i <= 10; i++)
    a[i] = 0;
```

`i` may very likely be in memory right after the array, so when the loop accesses `a[10]`, it will set `i` to 0, restarting the loop. Thus, an infinite loop!

---

An array subscript may be any integer expression.

```c
a[i+j*10] = 0;
```

The expression can even have side effects:

```c
i = 0;
while (i < N)
    a[i++] = 0;
```

---

### !!! PITFALL WARNING !!!

Be careful when an array subscript has a side effect. This loop is supposed to copy elements of array `b` into array `a`, but may not work correctly:

```c
i = 0;
while ( i < N)
    a[i] = b[i++];
```

Recall from Section 4.4 that accessing and modifying a variable in the same expression can lead to undefined behavior.

```c
for (i = 0; i < N; i++)
    a[i] = b[i];
```

---
---

## Array Initialization

An ***array initializer*** in its most common form; a list of constant expressions enclosed in braces and seperated by commas:

```c
int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10);
```

If the initializer is *shorter* than the array, the remaining elements are given the value 0.

```c
int a[10] = {1, 2, 3, 4, 5, 6}; /* initial value => {1, 2, 3, 4, 5, 6, 0, 0, 0, 0} */
```

Initialize an array to all zeros:

```c
int a[10] = {0} /* initial value => {0, 0, 0, 0, 0, 0, 0, 0, 0, 0} */
```

I'ts illegal to put empty braces, `{}`, and illegal for the initializer to be longer than the array's declared length.

If an initializer is present, the length of the array may be ommitted:

```c
int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
```

The compiler will determine the array length from the intializer. The array is still has a fixed number of elements.

---

## C99 Designated Initializers

C99's ***designated initializers*** allow you to pick which elements of an array to iniiailize.

```c
int a[15] = {[2] = 29, [9] = 7, [14] = 48};
```

Each number in brackets is said to be a ***designator***.

The order of the designated elements does not matter.

Designators must be integer constant expressions, between 0 and `n` - 1. Unless the length is not specified, then any nonnegative integer is allowed. In that case, the length of the array will be deduced by the largest designator.

An initializer can have both techniques:

```c
int c[10] = {5, 1, 9, [4] = 3, 7, 2, [8] = 6};
/* result: {5, 1, 9, 0, 3, 7, 2, 0, 6} */
```

Notice the 7 and 2 come immediately after element 4.

---

## Using the `sizeof` Operator with Arrays

The `sizeof` operator can determine the size of an array in bytes. Dividing the array size by the size of one of its elments gives the length of the array:

```c
sizeof(a) / sizeof(a[0]);
```

This expression can be used for the length of the array instead of a macro. It still doesn't have to be modified if the program changes, and its impossible to get a macro wrong.

```c
for (i = 0; i < sizeof(a) / sizeof(a[0]); i++)
    a[i] = 0;
```

Some compilers may produce a warning, since `i` is type `int` and `sizeof` produces a value of type `size_t` (an unsigned type). Section 7.4 explains that comparing a signed integer with an unsigned integer is a dangerous practice (though in this case it's ok, both are positive). To avoid a warning, use an `int` cast:

```c
for (i = 0; i < (int) (sizeof(a) / sizeof(a[0])); i++)
    a[i] = 0;
```

Defining a macro can make it less unweildy:

```c
#define SIZE ((int) (sizof(a) / sizeof(a[0]))

for (i = 0; i < SIZE; i++)
    a[i] = 0;
```

If using a macro, what's the advantage of `sizeof`? This is answered in Section 14.3 (add a parameter to the macro);
