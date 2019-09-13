# 2.5 Reading Input

`scanf` is used to read input. The `f` in `scanf` and `printf` stands for "formatted".

Both `scanf` and `printf` require a ***format string*** to specify the appearance of the input or output data.

```c
scanf("%d", &i);    /* reads an integer; stores into i */
```

The `"%d"` string tells `scanf` to read input that represents an integer.

The `&` sign will be explained later, but is usually needed for `scanf`.

```c
scanf("%f", &x);    /* reads a float value; stores into x */
```

