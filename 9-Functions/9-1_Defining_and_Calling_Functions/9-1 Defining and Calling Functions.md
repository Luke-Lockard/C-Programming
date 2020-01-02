# 9.1 Defining and Calling Functions

## `PROGRAM` Computing Averages

Program the computes the average of two `double` values:

```c
double average(double a, double b)
{
    return (a + b) / 2;
}
```

The word `double` at the beginning is `average`'s ***return type***: The type of data that the function returns.

The identifiers `a` and `b` are the function's ***parameters***: supplied when `average` is called.

Each parameter must have a type. In this example, both `a` and `b` have type `double`.

A function parameter is essentially a variable whose initial value will be supplied later, when the function is called.

The function ***body***: executable part, which is enclosed in braces. Executing this statement causes the function to "return" to the place from which is was called.

To call a function, we write the function name, followed by a list of ***arguments***. Ex, `average(x, y)`. The values of `x` and `y` are copied into parameters `a` and `b`, then the body of `average` is executed.

Looking at `average.c`, notice that the definition of `average` comes before `main`. 9.2 will show that putting `average` after `main` causes problems.

---

## `PROGRAM` Printing a Countdown

Not every function returns a value. To indicate that a function has no return value, specify its return as type `void`.

```c
void print_count(int n)
{
    printf("T minus %d and counting\n", n);
}
```

## `PROGRAM` Printing a Pun (Revisited)

Some functions have no parameters.

```c
void print_pun(void)
{
    printf("To C, or not to C: that is the question.\n");
}
```

The word `void` in parentheses indicates that `print_pun` has no arguments.

---

## Function Definitions

General form of a ***function definition***:

```c
return-type function-name ( parameters )
{
    declerations
    statements
}
```

- Functions may not return arrays, but there are no other restrictions on the return type.

- Specifying that the return type is `void` indicates that the function doesn't return a value.

- If the return type is omitted in C89, the function is presumed to return type `int`. In C99, it's illegal to omit the return type of a function.

The return type may be written *above* the function name:

```c
double
average(double a, double b)
{
    return (a + b) / 2;
}
```

This is especially useful if the return type is lengthy, like `unsigned long int`.

Variables declared in the body of a function belong exclusively to that function; they can't be examined or modified by other functions.

In C89, variable declarations must come first, before all statements in the body of a function.

In C99, variable declarations and statements can be mixed, as long as each variable is declared before it is used.

The body of a function whose return type is `void` can be empty:

```c
void print_pun(void)
{
}
```

Useful during program development; leave room for the function without taking time to complete it, then come back to it later.

## Function Calls

Function call consists of name of function followed by a list of arguments enclosed in parentheses.

```c
average(x, y);
print_count(i);
print_pun();
```

---

### ***PITFALL WARNING***

If the parentheses are missing, the function wont get called:

```c
print_pun;      /*** WRONG ***/
```

The result is a legal, meaningless expression statement that looks correct, but has no effect.

---

A call of a `void` function is always followed by a semicolon to turn it into a statement:

```c
print_count(i);
print_pun();
```

A call of a non-`void` function produces a value that can be stored in a variable, tested, printed, or used in some other way.

Ignoring the return value of a non-`void` function is odd, but sometimes it is not needed. The return value will be discarded:

```c
average(x, y);  /* discards return value */
```

To make it clear we're deliberately discarding the return value of a funciton, C allows us to put `(void)` before the call:

```c
(void) printf("Hi, Mom!\n");
```