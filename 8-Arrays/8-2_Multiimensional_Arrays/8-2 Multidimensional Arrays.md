# 8.2 Multidimensional Arrays

An array may have any number of dimensions. The following declaration creates a two-dimensional array:

```c
int m[5][9];
```

The array has 5 rows and 9 columns.

To access the element of `m` in frow `i`, column `j`, we must write `m[i][j]`, which selects element `j` in the array of element `i`.

---

### !!! PITFALL WARNING !!!

Do not write `m[i, j]` instead of `m[i][j]`. C treats the comma an an operator in this context, so `m[i,j]` is the same as `m[j]`.

---

C stores arrays in ***row-major order***, with row 0 first, then row 1, and so forth.

Nested `for` loops go hand in hand with multidimensional arrays. This example creates an *identity matrix* (1's on the diagonal where column & row indexes match, 0's everywhere else).

```c
#define N 10

double ident[N][N];
int row, col;

for (row = 0; row < N; row++)
    for (col = 0; col < N; col++)
        if (row == col)
            ident[row][col] = 1.0;
        else
            ident[row][col] = 0.0;
```

Multidimensional arrays play a lesser role in C than in many other languages, primarily because C provides a more flexible way to store multidimensional data: arrays of pointers (Section 13.7).

## Initializing a Multidimensional Array

Create a multidimensional array by nesting one-dimensional initializers:

```c
int m[5][9] = {{1, 1, 1, 1, 1, 0, 1, 1, 1},
               {0, 1, 0, 1, 0, 1, 0, 1, 0},
               {0, 1, 0, 1, 1, 0, 0, 1, 0},
               {1, 1, 0, 1, 0, 0, 0, 1, 0},
               {1, 1, 0, 1, 0, 0, 1, 1, 1}};
```

Ways to abbreviate initializers for multidimensional arrays:

- If the initializer isn't large enough to fill a multidimensional array, the remaining elements are given the value 0.

- If an inner list isn't long enough to fill a row, the remaining elements in the row are initialized to 0.

- Inner braces can be omitted. Once the compiler sees enough values to fill one row, it begins filling the next. This is risky: an extra or missing element will effect the whole initializer.

### C99

C99's designated initializers work with multidimensional arrays. This creates a 2x2 identity matrix:

```c
double ident[2][2] = {[0][0] = 1.0, [1][1] = 1.0};
```

## Constant Arrays

Any array can be made "constant" by starting its declaration with the word `const`:

```c
const char hex_chars[] = 
    {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
```

An array that's been declared `const` should not be modified by the program; the compiler will detect direct attempts to modify the array.

`const` documents that the program won't change the array,  helpful for other programmers, and helps the compiler catch errors.

`const` works with any variable (Section 18.3), but is particularly useful with arrays, because arrays may contain reference information that won't change during program execution.