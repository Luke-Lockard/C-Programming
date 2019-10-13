# 3.1 The `printf` Function

*printf* displays contents of a ***format string*** with values possibly inserted at specific points in the string:

```c
printf(string, expr1, expr2, ...);
```

***conversion specifications*** begin with the `%` character

- placeholder representing a value to be filled in during printing

```c
int i, j;
float x, y;

i = 10;
j = 20;
x = 43.2892f;
y = 5527.0f;

printf("i = %d, j = %d, x = %f, y = %f\n", i, j, x, y);
```

Produces output:

```c
i = 10, j = 20, x = 43.289200, y = 5527.000000
```

---

### ***!!! PITFALL WARNING !!!***

C compilers aren't required to check that the number of conversion specifiers matches the number of output items.

```c
printf("%d %d\n", i);   /*** WRONG ***/
```

This will print out value of `i`, then a second (meaningless) integer

```c
printf("%d\n", i, j);   /*** WRONG ***/
```

Prints value of `i` but not `j`.

Also, compilers aren't required to check that a conversion specifier matches the type of the item being printed.

---

## Conversion Specifications

Converstion specifications control the appearance of the output.

Can have the form:

`%m.pX` or `-%m.pX`

where `m` and `p` are integer constants and `X` is a letter.

`m` is ***minimum field width***: Specifies minimum number of characters to print.

- If value to print requires fewer than `m` characters, the value is right-justified with spaces added on the left.

- If value to print has more than`m` characters, the field width automatically expands to the necessary size.

`p` is the ***precision***: depends on the choice of `X`

`X` is the ***conversion specifier***: indicates which type conversion should be applied to the value before printing.

- `d` -- Decimal (base 10) form. `p` indicates minimum number of digits to display (extra 0's added to begining of number if necessary)

- `e` -- Displays floating-point number in exponential form (scientific notation). `p` indicates how many digits after decimal point (default is 6).

- `f` -- Displays a floating point number in "fixed decimal" format, without an exponent. `p` has the same meaning as for the `e` specifier.

- `g` -- Display floating-point number in either exponential format or fixed decimal format, depending on the number's size. `p` indicates maximum number of significant digits. `g` conversion won't allow trailing zeros.

## Escape Sequences

Sample of escape sequences:

- Alert (bell) `\a`

- Backspace `\b`

- New Line `\n`

- Horizontal tab `\t`

- The `"` character `\"`

- The `\` character `\\`
