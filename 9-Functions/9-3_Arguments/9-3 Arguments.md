# 9.3 Arguments

*Parameters* are the dummy names in function *definitions*.

*Arguments* are the actual values passed in function *calls*.

In C, arguments are ***passed by value***:

- when a function is called, each argument is evaluated and its value assigned to the corresponding parameter.

- Parameter contains copy of argument's value.

- Any changes to parameter during execution don't effect the argument.

- Each parameter behaves like a variable on its own.

Advantageous when you don't want to edit the values of arguments passed in.

Dissadvantageous when you do want to edit the values of arguments and keep the effects.

Ex: Function that decomposes a double value into an integer part and a fraction all part.

```c
void decompose(double x, long int_part, double frac_part)
{
    int_part = (long) x;    /* drops the fractional part of x */
    frac_part = x - int_part;
}
```

The variables passed in as arguments to `int_part` and `frac_part` won't get effected by this function.

We need more C features to make this possible (Section 11.4).

---

## Argument Conversion

C allows function calls where the types of the arguments don't match the types of the parameters. Rules governing how args are converted depends on if the compiler has seen the function prototype or definition prior to the call:

- ***The compiler has encountered a prototype proper to the call.*** The value of each argument is implicitly converted to the type of the corresponding parameter as if by assignement (`=`).

- ***The compiler has not encountered a prototype prior to the call.*** Compiler performs ***default argument promotions:*** (1) `float` converts to `double`. (2) Integral promotions are performed, `char` and `short` arguments converted to `int`. (In C99, integer promotions are performed.)

---

### PITFALL WARNING

Relying on default argument promotions is dangerous.

```c
#include <stdio.h>

int main(void)
{
    double x = 3.0;
    printf("Square: %d\n", square(x));

    return 0;
}

int square(int n)
{
    return n * n;
}
```

When `square` is called, the compiler doesn't know that it expects an `int`, and it is given a `double`. The compiler's default argument promotion does nothing. So the effect of calling square is undefined.

---

## Array Arguments

Arrays are often used as arguments. When a parameter is a one-dimensional array, the length of the array can be (and normally is) left unspecified:

```c
int f(int a[])  /* no length specified */
{
    ...
}
```

How will `f` know how long the array is? C doesn't provide any easy way for a function to determine the length of an array passed to it. It can be provided as an additional argument.

---

### PITFALL WARNING

Using `sizeof` operator to determine the length of an array *parameter* doesn't work:

```c
int f(int a[])
{
    int len = sizeof(a) / sizeof(a[0])   /*** WRONG: not the number of elements in a ***/
    ...
}
```

Section 12.3 explains why.

---

```c
int sum_array(int a[], int n)
{
    int i, sum = 0;

    for (i = 0; i < n; i++)
        sum += a[i];

    return sum;
}
```

Prototype for this function:

```c
int sum_array(int a[], int n);
```

Or without the parameter names:

```c
int sum_array(int [], int);
```

When `sum_array` is called, the first argument will be the name of an array, the second will be its length:

```c
#define LEN 100

int main(void)
{
    int b[LEN], total;
    ...
    total = sum_array(b, LEN);
    ...
}
```

A function has no way to check that we've passed it the correct array length. Passing a number smaller than the length will make `sum_array` only sum those elements, passing one larger than its length can cause undefined behavior!

If an array is passed in as an argument, changes to the array elements in the function will modify the actual array.

```c
void store_zeros(int a[], int n)
{
    int i;

    for (i = 0; i < n; i++)
        a[i] = 0;
}
```

If a parameter is a multidimensional array, only the length of the first dimension may be omitted when the parameter is declared.

```c
#define LEN 10

int sum_two_dimensional_array(int a[][LEN], int n)
{
    int i, j, sum = 0;

    for (i = 0; i < n; i++)
        for (j = 0; j < LEN; j++)
            sum += a[i][j];

    return sum;
}
```

## `C99` Variable-Length Array Parameters

Using a variable-length array parameter, we can explicitly state that `a`'s length is `n`:

```c
int sum_array(int n, int a[n])
{
    ...
}
```

Notice the order has been switched. The compiler must see `n` before seeing `a[n]`. In the opposite order it will cause an error.

A prototype for our new version of `sum_array` could be any of the following:

```c
int sum_array(int n, int a[n]);     /* Version 1 */
```

```c
int sum_array(int n, int a[*]);     /* Version 2a */
```

The `*` notation is because parameter names are optional, but the `*` provides a clue that the length of the array is related to parameters that come earlier in the list.

```c
int sum_array(int, int [*]);    /* Version 2b */
```

Also legal to have the bracket emtpy:

```c
int sum_array(int n, int a[]);  /* Version 3a */
int sum_array(int, int []);     /* Version 3b */
```

Leaving the brackets empty isn't a good choice, because it doesn't expose the relationship between `n` and `a`.

Function that concatenates two arrays `a` and `b` by copying elements of `a`, followed by elements of `b`, into a third array `c`:

```c
int concatenate (int m, int n, int a[m], int b[n], int c[m+n])
{
    ...
}
```

Variable-length array parameters are most useful for multidimensional arrays. Previous version was limited to arrays with fixed number of columns. We can generalize the function to any number of columns:

```c
int sum_two_dimensional_array(int n, int m, int a[n][m])
{
    int i, j, sum = 0;
    
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
            sum += a[i][j];
    
    return sum;
}
```

Prototypes for this function include the following:

```c
int sum_two_dimensional_array(int n, int m, int a[n][m]);
int sum_two_dimensional_array(int n, int m, int a[*][*]);
int sum_two_dimensional_array(int n, int m, int a[][m]);
int sum_two_dimensional_array(int n, int m, int a[n][*]);
```

---

## `C99` Using `static` in Array Parameter Declarations

C99 allows use of the keyword `static` in the declaration of array parameters.

Putting `static` in front of the number 3 indicates that the length of a is guaranteed to be at least 3:

```c
int sum_array(int a[static 3], int n)
{
    ...
}
```

This has no effect on the behavior of the program, it is merely a hint that may allow a C compiler to generate faster instructions for accessing the array. (If the compiler knows that an array will always have a certain minimum length, it can arrange to "prefetch" these elements from memory when the function is called, before the elements are actually needed by statements within the function.)

If an array parameter has more than one dimension, `static` can be used only in the first dimension.

---

## `C99` Compound Literals

The `sum_array` function might be called like this:

```c
int b[] = {3, 0, 3, 4, 1};
total = sum_array(b, 5);
```

`b` must be declared as a variable, then initialized prior to to the call. This might be annoying if `b` isn't needed for any other purpose than calling `sum_array`.

***Compound Literal***: An unnamed array that's created "on the fly" by simple specifying which elements it contains.

The following call of `sum_array` has a compound literal as its first argument:

```c
total = sum_arary((int []){3, 0, 3, 4, 1}, 5);
```

We didn't supply a length, so it is determined by the literal, but a length is optional: `(int [4]){1, 9, 2, 1}` is the same as `(int [4]){1, 9, 2, 1}`.

In general, a compound literal consists of a type name within parentheses, followed by a set of values enclosed in braces. Resembles a cast applied to an initializer.

Compound literals and initializers obey the same rules. A compount literal may contain designators, and it may fail to provide full initialization (uninitialized elements default to zero): `(int [10]){8, 6}` has 10 elements.

Compound literals created inside functions can contain arbitrary expressions:

```c
total = sum_array((int []){2 * i, i + j, j * k}, 3);
```

A compound literal is an lvalue, so its elements can be changed.

A compound literal can be made "read-only" by adding `const` to its type: `(const int []){5, 4}`.