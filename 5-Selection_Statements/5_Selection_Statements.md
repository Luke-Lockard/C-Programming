# 5 Selection Statements

We've seen just two statements so far: the `return` statement, and the expression statement. Most of the remaining statements fall into three categories, depending on how they affect the order in which statements are executed:

- ***Selection statements.*** The `if` and `switch` statements allow a program to select a particular execution path from a set of alternatives.

- ***Iteration statements.*** The `while`, `do`, and `for` statements support iteration (looping)

- ***Jump statements.*** The `break`, `continue`, and `goto` statements cause an unconditional jump to some other place in the program. (The `return` statement belongs in this category as well.)

The only other statements in C are the compund statement, which groups several statements into a single statement, and the null statement, which performs no action.

---

## 5.1 Locigal Expressions

The `if` statement must test the value of an expression to see if it is "true" or "false".

### Relational Operators

| Symbol | Meaning |
| --- | --- |
| `<` | less than |
| `>` | greater than |
| `<=` | less than or equal to |
| `>=` | greather than or equal to |

These operators produce 0 (false) or 1 (true).

other programming languages would have a "Boolean" or "logical" type, but in C these yield an integer.

Relational operators allow mixing floats and integers.

The precedence of relational operators is lower than that of arithmetic operators.

Relational operators are left associative.

### Equality Operators

| Symbol | Meaning |
| --- | --- |
| `==` | equal to |
| `!=` | not equal to |

Equality operators are left associative.

Has lower precedence than the relational operators:

```c
i < j == j < k
```

is equivalent to

```c
(i < j) == (j < k)
```

### Logical Operators

| Symbol | Meaning | Association |
| --- | --- | --- |
| `!` | logical negative | left |
| `&&` | logical *and* | right |
| `||` | logical *or* | |

`!` is unary, `&&` and `||` are binary.

- `!expr` has the value 1 if `expr` has the value 0.

- `expr1 && expr2` has the value 1 if the values of `expr1` and `expr2` are both non-zero

- `expr1 || expr2` has the value 1 if either `expr1` or `expr2` (or both) has a nonzero value.

In all other cases, they have the value 0.

***Short circuit evaluation***: `&&` and `||` evaluate the left operand first, and if the value of the expression can be deduced from the left operand alone, it doesn't continue to evaluate the right operand.

---

***!!! PITFALL WARNING!!!***

Short circuiting can cause the right operand to not be evaluated, so in an expression like this:

```C
i > 0 && ++j > 0;
```

if the left operand is 0, then j will not be incremented!

The `!` operator has the same precedence as the unary plus and minus operators. `&&` and `||` have lower precedence than relational and equality operators. So `i < j && k == m` means `(i < j) && (k == m)`.

---

## 5.2 The `if` statement

Allows a program to choose between two alternatives by testing the value of an expression.

In it's simplist form:

```C
if ( expression ) statement
```

If the evaluation of the expression is not 0, the statement is executed.

### Compound Statements

A ***compound statement*** has the form

```C
{ statements }
```

By putting braces around a group of statements, we can force the compiler to treat it as a single statment.

A compound statement can replace the singular statement of the `if` statement.

### The `else` Clause

An `if` statement may have an `else` clause:

```C
if ( expression ) statement else statement
```

If the statements are short, they can be written on the same line as the `if` and `else`:

```C
if (i > j) max = i;
else max = j;
```

If statements can be nested. Aligning each matching `if` and `else` together helps readability, and braces can be used for further clarity.

### Cascading `if` Statments

Cascaded `if` statements are often the best way write a series of tests:

```C
if (n < 0)
    printf("n is less than 0\n");
else
    if (n == 0)
        printf("n is equal to 0\n");
    else
        printf("n is greater than 0\n");
```

The second `if` statement doesn't have to be indented like above:

```c
if (n < 0)
    printf("n is less than 0\n");
else if (n == 0)
    printf("n is equal to 0\n");
else
    printf("n is greater than 0\n");
```

This avoids excessive indentation. It isn't some new kind of statement; it's just an ordinary `if` statement that happens to have another `if` statement as its `else` clause.

### The "Dangling `else`" Problem

```c
if (y != 0)
    if (x != 0)
        result = x / y;
else
    printf("Error: y is equal to 0\n");
```

To which `if` statement does the `else` clause belong?

C follows the rule that an `else` clause belongs to the nearest `if` statement that hasn't already been paired with an `else`. So the `else` clause here actually belongs to the inner `if` statement.

To make the `else` clause part of the outer `if` statement, enclose the inner `if` in braces:

```c
if (y != 0) {
    if (x != 0)
        result = x / y;
} else
    printf("Error: y is equal to 0\n");
```

### Conditional Expressions

The ***conditional operator*** consists of two symbols (`?` and `:`), which must be used together in the following way:

```c
expr1 ? expr2 : expr3
```

This expression is a ***conditional expression***. Refered to as a ***tenery*** operator because it requires *three* operands.

Should be read: "if *expr1* then *expr2* else *expr3*."

*expr1* is evaluated first. If its value isn't 0, then *expr2* is evaluated and returned. If its value is 0, then *expr3* is evaluated and returned.

```c
int i, j, k;

i = 1;
j = 2;
k = i > j ? i : j;          /* k is now 2 */
k = (i >= 0 ? i : 0) + j;   /* k is now 3 */
```

### Boolean Values in C89

There is no Boolean type defined in the C89 standard.

One work around is to declare an `int` variable and assign it to either 0 or 1:

```c
int flag;

flag = 0;
...
flag = 1;
```

To make it more understandable, C89 programmers often define macros with names such as `TRUE` and `FALSE`:

```c
#define TRUE 1
#define FALSE 0
```

Assignmens to flag would have a more natural appearance:

```c
flag = FALSE;
...
flag = TRUE;
```

To test if flag is true:

```c
if (flag == TRUE) ...
```

or just

```c
if (flag) ...
```

To test if it is false:

```c
if (flag == FALSE) ...
```

or 

```c
if (!flag)
```

Could even define a macro that can be used as a type:

```c
#define BOOL int
```

`BOOL` can take he place of `int` when defining Boolean variables:

```c
BOOL flag;
```

It's now clear that `flag` isn't an ordinary integer variable, but instead represents a Boolean condition. (The compiler still treats `flag` as an `int`.)

### Boolean Values in C99

C99 provides the `_Bool` type. A boolean can be declared by writing:

```c
_Bool flag;
```

_Bool is an unsigned integer type, but it can only be assigned 0 or 1.

Attempting to store a nonzero value into a _Bool variable will cause the variable to be assigned to 1.

C99 also provides a new header, `<stdbool.h>`. It provides a macro, `bool`, that stands for `_Bool`. If `<stdio.h>` is included, we can write:

```c
bool flag:      /* same as _Bool flag; */
```

It also provides macros named `true` and `false`, which stand for 1 and 0, respectively, making it possible to write:

```c
flag = false;
...
flag = true;
```

---

## 5.3 The `switch` Statement

The switch statement is good for comparing an expression against a series of values to see which one it currently matches.

The most common form:

```c
switch ( expression ) {
    case constant-expression : statements
    ...
    case constant-expression : statements
    default : statements
}
```

```c
switch (grade) {
    case 4: printf("Excellent");
            break;
    case 3: printf("Good");
            break;
    case 2: printf("Average");
            break;
    case 1: printf("Poor");
            break;
    case 0: printf("Failing");
            break;
    default: printf("Illegal grade");
            break;
}
```

- ***Controlling expression.*** The word `switch` must be followed by an integer expression in parentheses. Characters are treated as integers in C and thus can be tested in `switch` statements. Floating-point numbers and strings cannot.

- ***Case labels.*** Each case begins with a label of the form
  - `case constant-expression :`

  - A ***constant expression*** is like an ordinary expression except it can't contain variables or function calls. The constant expression in a case label must evaluate to an integer (characters also acceptable).

- ***Statements.*** After each case label comes any number of statements, with no braces required. The last statement is normally `break`.

Duplicate case labels aren't allowed. The order of the cases doesn't matter; the default case doesn't need to come last.

Only one constant expression may follow the word `case`; however several labels may precede the same group of statements:

```c
switch (grade) {
    case 4:
    case 3:
    case 2:
    case 1:     printf("Passing");
                break;
    case 0:     printf("Failing");
                break;
    default:    printf("Illegal grade");
                break;
}
```

A `switch` statement isn't required to have a `default` case. If there is no `default` and the value of the controlling statement doesn't match any of the case labels, control simply passes to the next statement after the `switch`.

### The Role of the `break` Statement

`break` causes the program to break out of the `switch` statement; execution continues to the next statement after the `switch`.

Without `break`, control will flow to the next case statement.

This is useful for when you want multiple cases to have the same output.

If you deliberately leave out `break`, it's good to point out the deliberate omission:

```c
switch (grade) {
    case 4: case 3: case 2: case 1:
            num_passing++;
            /* FALL THROUGH */
    case 0: total_grades++;
            break;
}
```

Without the comment, it could be mistaken for an error, which fixed would change the program.
