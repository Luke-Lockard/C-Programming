# 4.1 Arithmetic Operators

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

## Operator Precedend and Associativity

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
