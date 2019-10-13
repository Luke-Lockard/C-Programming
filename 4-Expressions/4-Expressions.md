# 4 Expressions

- Arithmetic operators

- Relational operators

- Logical operators

---

## 4.1 Arithmetic Operators

| ***Unary*** | ***Binary*** | |
| --- | --- | --- |
| | ***Additive*** | ***Multiplicative*** |
| `+` unary plus | `+` addition | `*` multiplication |
| `-` unary minus | `-` subtraction | `/` division |
| | | `%` remainder |

The additive and multiplicative operators are said to be ***binary*** because they require *two* operands. The ***unary*** operators require *one* operand.

The binary operators, except `%`, allow integer or floating-point operands, with mixing allowed.

If `int` and `float` operands are mixed, the result has type `float`.

The `/` and `%` operators require special care:

- When both operands of `/` are integers, the result is an integer, and the `/` operator "truncates" the result by dropping the fraction part.

- The `%` operator requires integer operands: if either operand is not an integer, the program won't compile.

- Using zero as the right operand of either `/` or `%` causes undefined behavior.

- When using negative operands with `/` or `%`:

  - C89 states that if either operand is negative, the result can be rounded up or down. If `i` or `j` is negative, the sign of `i % j` depends on the implementation. (`-9 % 7` could be either -2 or 5)

  - C99 says the result of division is always truncated toward 0 and the value of `i % j` has the same sign as `i` (hence the value of `-9 % 7` is -2)

---
### Implementation-Defined Behavior

The term ***implementation-defined*** means the parts of the C standard deliberately left to the "implementation" -- the software needed to compile, link, and execute the program on a particular platform.

The behavior of a program may vary somewhat according to different implementations.

It's best to avoid writing programs that depend on implementation-defined behavior.

---

### Operator Precedend and Associativity

The arithmetic operators have the following relative precedence:

| | | | |
| --- | --- | --- | --- |
| Highest: | `+` | `-` | (unary) |
| | `*` | `/` | `%` |
| Lowest: | `+` | `-` | (binary) |

Operators listed on the same line have equal precedence.

Parentheses can be used to give an expression higher precedence, just like in mathematics.

Operators have ***associativity***, which also applies:

- ***left assicative***: groups from left to right

  - `i - j - k` is equivalent to `(i - j) - k`
  
  - `i * j / k` is equivalent to `(i * j) / k`

- ***right associative***: groups from right to left

  - The unary arithmetic operators ( + and -) are both right associative

  - `- + i` is equvalent to `-(+i)`

---

## 4.2 Assignment Operators

### Simple Assignment

The effect of the assignment `v = 3` is to evaluate the expression `e` and copy its value into `v`.

If `v` and `e` don't have the same type, then the value of `e` is converted to the type of `v` as the assignment takes place:

```c
int i;
float f;

i = 72.99f;     /* i is now 72 */
f = 136;        /* f is now 136.0 */
```

In many programming languages, assignment is a *statement*; in C, it is an *operator*, just like `+`.

---

### ***Side Effects***

Operators that modify their operands are said to have ***side effects***, since they do more than just compute a value. The assignment operator has side effects, as it modifies its left operand.

Evaluating the expressions `i = 0` produces the result `0` and -- as a side effect -- assigns `0` to `i`.

---

Since assignment is an operator, several assignments can be chained together:

```c
i = j = k = 0;
```

The operator is right associative, so the assignment is equivalent to

```c
i = (j = (k = 0));
```

The effect is to assigne 0 first to `k`, then to `j`, and finally to `i`.

---

***!!! PITFALL WARNING!!!***

```C
int i;
float f;

f = i = 33.3f;
```

`i` is assigned the value 33, the `f` is assigned 33.0 (not 33.3)

---

### Lvalues

The assignment operator requires an ***lvalue*** as its left operand.

An lvalue represents an object stored in computer memory.

Variables are lvallues. It is illegal to put any other kind of expression on the left side of an assignment expression:

```c
12 = i;     /*** WRONG ***/
i + j = 0   /*** WRONG ***/
-i = j;     /*** WRONG ***/
```

### Compound Assignemnt

Assignments that use the old value of a variable to compute its new value are common: `i = i + 2`.

C's ***compound assignment*** operators allow us to shorten this statement:

```c
i += 2;     /* same as i = i + 2; */
```

There are 10 compound assignments which include:

```c
+=  -=  *=  /=  %=
```

Compound assignment operators are right associative.

---

## 4.3 Increment and Decrement Operators

- `++` ***increment***

- `--` ***decrement***

Can be used as ***prefix*** operators (`++i` and `--i`) or ***postfix*** operators (`i++` and `i--`).

`++` and `--` have side effects: 

- `++i` (a "pre-increment") yields `i + 1` and -- as a side effect -- increments i:

- `i++` (a "post-increment") produces the result `i`, but causes `i` to be incremented afterwards.

`i++` will increment `i` before the next statement is executed.

---

## 4.4 Expression Evaluation

| ***Precedence*** | ***Name*** | ***Symbol(s)*** | ***Associativity*** |
| --- | --- | --- |--- |
| 1 | increment (postfix) | `++` | left |
| | decrement (postfix) | `--` | |
| 2 | increment (prefix) | `++` | right |
| | decrement (prefix) | `--` | |
| | unary plus | `+` | |
| | unary minus | `-` | |
| 3 | multiplicative | `* / %` | left |
| 4 | additive | `+ -` | left |
| 5 | assignment | `= *= /= %= += -=` | right |

### Order of Subexpression Evaluation

The rules of operator precedence and associativity allow us to break any C expression into subexpressions.

C doesn't define the order in which subexpressions are evaluated (except when involving the logical *and*, logical *or*, conditional, and comma operators). Thus, in the expression `(a + b) * (c - d)` we don't know whether `(a + b)` will be evaluated before `(c - d)`.

```c
a = 5;
c = (b = a + 2) (a = 1);
```

The value of the second statement is undefined; C standard doesn't say what will happen.

---
***!!! PITFALL WARNING!!!***

Avoid writing expressions that access the value of a variable and also modify the variable elsewhere in the expression.

---

## 4.5 Expression Statements

C has an unusual rule that *any* expression can be used as a statement.

```c
++i;
```

`i` is first incremented, then the new value of `i` is fetched, but then discarded since it is not used. The change to `i` is permanent.

There's little point in using an expression as a statement unless the expression has side effects.
