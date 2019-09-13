# 2.2 The General Form of a Simple Program

Simple C programs have the form:

```c
directives

int main(void)
{
    statements
}
```

## Directives

Commands intended for the preprocessor are called directives.

Directives always begin with a `#` character, are one line long, and do not end with a semicolon or any other special marker.

Chapters 14 and 15 discuss directives in detail. For now, we're only interested in the `#include` directive.

```c
#include <stdio.h>
```

This directive states that the information included in `<stdio.h>`  is to be "included" before compile.

C has a number of ***headers*** like `<stdio.h>`, each containing information about some part of the standard library.

## Functions

The `main` function is mandatory. It gets called automatically when the program is executed. Until chapter 9 we will only use the `main` function.

```c
#include <stdio.h>

int main(void)
{
    printf("To C, or not to C: that is the question.\n");
    return 0;
}
```

The word `int` just before `main` indicates that `main` returns an integer value.

The word `void` in parentheses indicates that `main` has no arguments.

The statement

```c
return 0;
```

has 2 effects: it causes the main function to terminate, and indicates that the `main` function returns the value of 0.

If there's no `return` statement at the end of `main`, the function still terminates.

## Statements

A ***statement*** is a command to be executed.

C requires that each statement ends with a semicolon. (One exception is the compound statement.) The semicolon shows the compiler where the statement ends.

## Printing Strings

We've used `printf` to display a ***string literal*** - a series of characters enclosed in double quotation marks.

To instruct `printf` to advance the next ouput line, we must include `\n` (the ***new-line character***) in the string to be printed.

```c
printf("To C, or not to C: ");
printf("that is the question.\n");
```

Prints everything on one line, then advances to the next line at the end.

```c
printf("Brevity is the soul of wit.\n  --Shakespear\n");
```

ouputs:

```
Brevity is the soul of wit.
  --Shakespear
```
