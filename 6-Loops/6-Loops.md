# 6 Loops

This chapter introduces C's iteration statements.

A ***loop*** is a statement whose job is to repeatedly execute some other statement (the ***loop body***).

Every loop has a ***controlling expression***. The controlling expression is evaluated each ***iteration*** of the loop.

C has three iteration statements: `while`, `do`, and `for`.

The `while` satement is for loops whose controlling expression is ested *before* the loop body is executed.

The `do` statement is used if the expression is tests *after* the loop body is executed.

The `for` statement is convenient for loops that increment or decrement a counting variable.

---

## 6.1 The `while` Statement

```c
while ( expression ) statement
```

The expression in the parentheses is the controlling expression.

The control expression is evalutated before each loop itereation. If its value is nonzero (true), the loop runs until the control expression becomes 0 (false).

This loop computes the smallest power of 2 that is greater than or equal to a number `n`:

```c
i = 1;
while (i < n)
    i = i * 2;
```

ex:

```c
i = 10;
while (i > 0) {
    printf("T minus %d and counting\n", i);
    i--;
}
```

### Infinite Loops

A `while` statement won't terminate if the controlling expression always has a nonzero value.

C programmers might deliberately create an *infinite loop* by using a nonzero constant as tthe controlling expression:

```c
while (1) ...
```

This loop will execute forever unless its body contains a statement that transfers control out of the loop (`break`, `goto`, `return`) or calls a function that causes the program to terminate.

---

## 6.2 The `do` Statement

The `do` statement is essentially a `while` statement whose controlling expression is tested *after* each execution of the loop body.

```c
do statement while ( expression ) ;
```

ex:

```c
i = 10;
do {
    printf("T minus %d and counting\n", i);
    --i;
} while (i > 0);
```

---

## 6.3 The `for` Statement

The `for` statement is ideal for loops that have a "counting" variable, but it's versatile enough to be used for other kinds of loops as well.

```c
for ( expr1 ; expr2 ; expr3 ) statement
```

ex:

```c
for (i = 10; i > 0; i--)
    printf("T minus %d and counting\n", i);
```

*expr1* is executed only once before the loop; generally initializes the counting variable before the loop.

*expr2* is the controlling expression, tested for truthiness before each loop.

*expr3* is runs after each iteration of the loop; generally increments/decrements the counting variable.

Except in a few rare cases, a `for` loop can always be replaced with an equivalent `while` loop:

```c
expr1
while ( expr2 )
    statement
    expr3;
)
```

Since the first and third expressions in a `for` statement are executed as statements, their values are irrelivant -- they're useful only for their side effects. Consequently, these two expressions are usually assignments or increment/decrement expressions.

### `for` Statement Idioms

- ***Counting from 0 to `n`-1:***
  - `for (i = 0; i < n; i++) ...`

- ***Counting up from 1 to `n`:***
  - `for (i = 1; i <= n; i++) ...`

- ***Counting down from `n`-1 to 0:***
  - `for (i = n - 1; i >= 0; i--) ...`

- ***Counting down from `n` to 1:***
  - `for (i = n; i > 0; i--) ...`

Common errors are using the wrong comparison operator in the controlling expression, and being "off-by-one" with the counting (ex: using `i <= n` instead of `i < n`)

### Omitting Expressions in a `for` Statement

Some `for` loops may not need all three of the expressions, so C allows us to omitt any or all of the expressions.

```c
i = 10;
for (; i > 0; --i)
    printf("T minus %d and counting\n", i);
```

The *first* expression has been omitted, but `i` has been initialized by a separate assignment.

Notice the semicolon between he first and second expressions remains. The two semicolons must always be present, even if any or all of the expressions have been omitted.

If the *third* expression is omitted, the loop body is responsible for ensuring the value of the second expression eventually becomes zero:

```c
for (i = 10; i > 0;)
    printf("T minus %d and counting\n", i--);
```

When the *first* and *third* expressions are both omitted, the loop is nothing more than a `while` statement in disguise:

```c
for (; i > 0;)
    printf("T minus %d and counting\n", i--);
```

is the same as

```c
while (i > 0)
    printf("T minus %d and counting\n", i--);
```

If the *second* expression is missing, it defaults to a true value, to the `for` statement doesn't terminate (unless stopped in some other fashion).

Some programmers use the following `for` statement to establish an infinite loop:

```c
for (;;) ...
```

### `for` Statements in C99

In C99, the first expression can be a declaration.

```c
for (int i = 0; i < n; i++)
    ...
```

`i` need not be declared prior to this statement.

If declaration of `i` already exists, this statement creates a *new* version of `i` that will be used solely within the loop.

A variable declared by a `for` statement can't be accessed outside the loop body (not ***visible** outside the loop):

```c
for (int i = 0; i < n; i++) {
    ...
    printf("%d", i);       /* legal; i is visible inside loop */
}
printf("%d", i);        /*** WRONG ***/
```

A `for` statement may declare more than one variable, provided that all variables have the same type:

```c
for (int i = 0, j = 0,; i < n; i++)
```

### The Comma Operator

A ***comma expression*** has the form

```c
expr1 , expr2
```

A comma expression is evaluated in two steps: First, *expr1* is evaluated and its value discarded. Second, *expr2* is evaluated; its value is the value of the entire expression.

Evaluating *expr1* should always have a side effect, otherwise it is pointless.

Comma operators can be chained:

```c
i = 1, j = 2, k = i + j
```

The precedence of the comma operator is less than that of all other operators.

The comma operator is left associative.

The assignments in the example above will be performed left to right, so `k` will have a value of 3.

The comma operator is mostly used in the `for` statement, an usually to initialize multiple variables.

```c
for (sum = 0, i = 1; i <= N; i++)
    sum += i;
```

---

## 6.4 Exiting from a Loop

We may want a loop with an exit point in the middle, or with more than one exit point. We can do that with a `break` statement.

The `continue` statement makes it possibleto skip part of a loop iteration without jumping out of the loop.

The `goto` statemen allows a program to jump fom one statement to another. `goto` is rarely used, because `break` and `continue` are usually better suited.

### The `break` Statement

The `break` statement has already been shown in a `switch` statement, and it can be used in the same way to jump out of a `while`, `do`, or `for` loop.

This program checks whether a number `n` is prime by dividing it by every number between 2 and `n` - 1, breaking out of the loop as soon as a divisor is found:

```c
for (d = 2; d < n; d++)
    if (n % d == 0)
        break;

if (d < n)
    printf("%d is divisible by %d\n", n, d);
else
    printf("%d is prime\n", n);
```

`break` is useful writing loops that terminate in the middle of the body. Such as loops that read user input:

```c
for (;;) {
    printf("Enter a number (enter 0 to stop): ");
    scanf("%d", &n);
    if (n == 0)
        break;
    printf("%d cubed is %d\n", n, n * n * n);
}
```

A `break` statement transfers control out of the *innermost* enclosing `while`, `do`, `for`, or `switch` statement. When these statements are nested, it only escapes on level of nesting.

```c
while (...) {
    switch (...) {
        ...
        break;
        ...
    }
}
```

### The `continue` Statement

`continue` transfers control just *before* the end of the loop body.

```c
n = 0;
sum = 0;
while (n < 10) {
    scanf("%d", &i);
    if (i == 0)
        continue;
    sum += i;
    n++;
    /* continues jumps to here */
}
```

### The `goto` Statement

The `goto` statement is capable of jumping to *any* statement in a function, provided that the statement has a ***label***.

**Labeled Statement:**

```c
identifier : statement
```

**`goto` Statement:**

```c
goto identifier ;
```

Executing the statement `goto` ***`L`***`;` transfers control to the statement that follows the label ***`L`***.

***`L`*** must be in the same function as the `goto` statement itself.

```c
for (d = 2; d < n; d++)
    if (n % d == 0)
        goto done;

done:
if (d < n)
    printf("%d is divisible by %d\n", n, d);
else
    printf("%d is prime\n", n);
```

`goto` is rarely needed. One scenario it would be usedful is exiting a loop inside a switch statement, or exiting from nested loops.

```c
while (...) {
    switch (...) {
        ...
        goto loop_done; /* break won't work here */
        ...
    }
}
loop_done: ...
```

## 6.5 The Null Statement

A statement can be ***null*** -- devoid of symbols except for the semicolon at the end.

The null statement is primarily good for one thing: writing loops whose bodies are empty. Recall the prime-finding loop from Section 6.4:

```c
for (d = 2; d < n; d++)
    if (n % d == 0)
        break;
```

If we move the `n % d == 0` condition into the loop's controlling expression, the body of the loop becomes empty:

```c
for (d = 2; d < n && n % d != 0; d++)
    /* empty loop body */ ;
```

---

***!!! PITFALL WARNING !!!***

Accidentally putting a semicolon at the end of an `if`, `while`, or `for` statement creates a null statement, thus ending the `if`, `while`, or `for` prematurely.

- Putting a semicolon after the parentheses of an `if` statement creates an `if` statement that apparently performs the same action regardless of the value of the controlling expression:
  - ```c
    if (d == 0);        /*** WRONG ***/
        printf("Error: Division by zero\n");
    ```

- A semicolon after the parentheses of a `while` statement creates an infinite loop, or a loop that only terminates once.
  - ```c
    i = 10;
    while (i > 0);      /*** WRONG ***/
    {
        printf("T minus %d and counting\n", i);
    }
    ```

  - ```c
    i = 11;
    while (--i > 0);        /*** WRONG ***/
        printf("T minus %d and counting\n", i);
    ```

- Putting a semicolon after a parentheses of a `for` statement causes the loop to only be executed once.
  - ```c
    for (i = 10; i > 0; i++);       /*** WRONG ***/
        printf("T minus %d and counting\n", i);
    ```

---
