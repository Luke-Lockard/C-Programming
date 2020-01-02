# 10.1 Local Variables

A variable declared in the body of a function is said to be ***local*** to the function.

In the following function, `sum` is a local variable:

```c
int sum_digits(int n)
{
    int sum = 0;    /* local variable */

    while (n > 0) {
        sum += n % 10;
        n /= 10;
    }

    return sum;
}
```

By default, local variables have the following properties:

- ***Automatic storage duration***. The ***storage duration*** (or ***extent***) of a variable is the portion of program execution during which storage for the variable exists.
  - Storage for a local variable is "automatically" allocated when the enclosing function is called and deallocated when the function returns. When the function is called again, there's no guarantee that the variable will still have its old value.

- ***Block scope***. The ***scope*** of a variable is the portion of the program text in which the variable can be referenced.
  - A local variable has ***block scope***: it is visible from its point of declaration to the end of the enclosing function body.

***C99***

Since C99 doesn't require variable declarations to come at the beginning of a funciton, it's possible for a local variable to have a very small scope.

The scope of `i` doesn't begin until the line on which it's declared, which could be near the end of the function body:

```c
void f(void)
{
    ...
    int i;
    ...
}
```

---

## Static Local Variables

Putting `static` in the declaration of a local variable causes it to have ***static storage duration*** instead of automatic storage duration.

A `static` variable has a permanent storage location, so it retains its value throughout the execution of the program.

```c
void f(void)
{
    static int i;   /* static local variable */
    ...
}
```

When `f` returns, `i` won't lose it's value.

A static local variable still has block scope, so it's not visible to other functions but retains it for future calls of the same function.

---

## Parameters

Parameters have the same properties - automatic storage duration and block scope - as local variables.

The only difference between parameters and local variables is that each parameter is initialized automatically when a function is called.
