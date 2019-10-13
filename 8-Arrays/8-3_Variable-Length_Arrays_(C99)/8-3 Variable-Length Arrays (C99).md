# 8.3 Variable-Length Arrays (C99)

Section 8.1 stated that the length of an array variable must be specified by a constant expression. In C99, it's sometimes possible to use an expression that's *not* constant.

The following modification of the `reverse.c` program (Section 8.1) illustrates this ability:

***`reverse2.c`***

```c
/* Reverses a series of numbers using a variable-length array - C99 only */
#include <stdio.h>

int main(void)
{
    int i, n;

    printf("How many numbers do you want to reverse? ");
    scanf("%d", &n);

    int a[n];   /* C99 only - length of array depends on n */

    printf("Enter %d numbers: ", n);
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    printf("In reverse order:");
    for (i = n - 1; i >= 0; i--)
        printf(" %d", a[i]);
    printf("\n");

    return 0;
}
```

The array `a` is an example of a ***variable-length array*** (or ***VLA*** for short).

The length of a VLA is computed when the program is executed, not when it's compiled.

**Advantages of VLAs**

- The programmer doesn't have to pick an arbitrary length, the length can be computed.
  - The array won't be too long (wasted memory)
  - or too short (program fails).

Arbitrary expressions, possibly containing operators, are also legal:

```c
int a[3*i+5];
int b[j+k];
```

VLAs can be multidimensional:

```c
int c[m][n];
```

**Restrictions on VLAs**

- Can't have static storage duration (not seen yet: Section 18.2).

- May not have an initializer

VLAs are usually seen in functions other than `main`. A VLA that belongs to a function `f` can have a different length each time `f` is called. (Section 9.3).