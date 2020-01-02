# 9.5 Program Termination

`main` is a function, so it must have a return type. Normally it is `int`:

```c
int main(void)
{
    ...
}
```

Older C programs often omit `main`'s return type, since it defaults to `int`:

```c
main()
{
    ...
}
```

---

***`C99`***

Omitting the return type isn't legal in C99. Omitting `void` in the parameter list remains legal, but it's best to be explicit about the fact.

---

`main` returns a status code that can be tested when the program terminates. Returns 0 if program terminates normally, any other value indicates abnormal termination.

## The `exit` Function

The `exit` function, which belongs to `<stdlib.h>`, is another way to terminate a program. Argument passed to `exit` is the same as `main`'s return value.

```c
exit(0);        /* normal termination */
```

Macros defined in `<stdlib.h>` such as `EXIT_SUCCESS` (0) and `EXIT_FAILURE` (1) can be used.

```c
exit(EXIT_SUCCESS);     /* normal termination */
```

```c
exit(EXIT_FAILURE);     /* abnormal termination */
```

`return expression` is equivalent to `exit(expression);`.

The difference between `return` and `exit` is that `exit` causes program termination regardless of which function calls it. The `return` function is only used for program termination when it is in the `main` function.
