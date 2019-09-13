# 7.6 The `sizeof` Operator

`sizeof` determines how much memory is required to store values of a particular type.

```c
sizeof ( **type-name** )
```

Value is an unsigned integer

Number of bytes

```c
sizeof i /* parentheses not required for expressions */
sizeof i + j /* order of precedence makes this (sizeof i) + j */
sizeof (i + j)
```

Printing a `sizeof` value:

- type of a `sizeof` expression is an implementation-defined type named `size_t`
- C89: best to convert to known type before printing
  - safest to convert to `unsigned long`, then print with `%lu`

```c
printf("Size of int: %lu\n", (unsigned long) sizeof(int));
```

### C99

`size_t` can be larger than `unsigned long`

However, `printf` in C99 is capable of displaying `size_t` values directly, without needing a cast.

Use letter `z` in the conversion specification, followed by one of the usual integer codes (typically `u`):

```c
printf("Size of int: %zu\n", sizeof(int));  /* C99 only */
```

