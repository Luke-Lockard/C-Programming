# 7.4 Type Conversion

The compiler handles *implicit conversions* automatically.
C also allows the programmer to perform *explicit conversions*, using the cast operator.

Implicit conversions are performed when:

- **Arithmetic**: the operands in an arithmetic expressions don't have the same type
- **Assignment**: the type of the expression on the right side of an assignment doesn't match the type of the variable on the left side
- **Function Parameters**: type of argument in a function call doesn't match the type of the corresponding parameter
- **Function Return**: type of expression in `return` statement doesn't match the function's return type

## The Usual Arithmetic Conversions

The strategy behind arithmetic conversion is to convert operands to the "narrowest" type that will safely accomodate both values.
The operand with the narrower type is ***promoted*** to the type of the other parameter.

- ***The type of either operand is a floating type***:
    `float` -> `double` -> `long double`
- ***Neither operand type is a floating type***:
    `int` -> `unsigned int` -> `long int` -> `unsigned long int`

```C
char c;
short int s;
int i;
unsigned int u;
long int l;
unsigned long int ul;
float f;
double d;
long double ld;

i = i + c;      /* c is converted to int                */
i = i + s;      /* s is converted to int                */
u = u + i;      /* i is converted to unsigned int       */
l = l + u;      /* u is converted to long int           */
ul = ul + l;    /* l is converted to unsigned long int  */
f = f + ul;     /* ul is converted to float             */
d = d + f;      /* f is converted to double             */
ld = ld + d;    /* d is converted to long double        */
```

## Conversion During Assignment

**Rule**: Expression on right side of assignment is converted to the type of the variable on the left side.

```C
char c;
int i;
float f;
double d;

i = c;  /* c is converted to int    */
f = i;  /* i is converted to float  */
d = f;  /* f is converted to double */
```

Assigning a expression to a type that is narrower is problematic.

```C
int i;

i = 842.97;     /* i is now 842 */
i = -842.97     /* i is now -842 */
```

## Implicit Conversions in C99

C99 has additional types (`_Bool`, `long long` types, extended integer types, and complex types).

### Integer Conversion Ranks

1. `long long int`, `unsigned long long int`
2. `long int`, `unsigned long int`
3. `int`, `unsigned int`
4. `short int`, `unsigned short int`
5. `char`, `signed char`, `unsigned char`
6. `_Bool`

In place of C89's integral promotions, C99 has "integer promotions", which involve converting any type whose rank is less than `int` and `unsigned int` to `int` (provided that all values of the type can be represented using `int`) or else to `unsigned int`.

- ***The type of either operand is a floating type***:
  - `float` -> `double` -> `long double`
- ***Neither operand type is a floating type***:
    First perform integer promotion on both operands. If both operand types are the same, process ends. Else:
  - Signed operands convert to signed rank of greater operand, same for unsigned.
  - If unsigned operand rank >= signed operand, convert to unsigned operand rank.
  - If type of signed operand can represent all values of the type of the unsigned operand, convert unsigned to the type of the signed operand.
  - Otherwise, convert both operands to the unsigned type corresponding to the type of the signed operand.

## Casting

Explicit type conversion:
`( type-name ) expression`

Ex:

```C
float f, frac_part;
frac_part = f - (int) f;
```

Document type conversions that would happen anyway:
`i = (int) f;   /* f is converted to int */`

Overrule compiler

```C
float quotient;
int dividend, divisor;

quotient = dividend / divisor;
```

As written above, the result of division--and integer--will be converted to a `float` before being stored in `quotient`.
We want `dividend` and `divisor` converted to `float` *before* the division:
`quotient = (float) dividend / divisor;`
`divisor` doesn't need a cast, since casting `dividend` to `float` forces the compiler to convert `divisor` to `float` also.

Avoid overflow:

```C
long i;
int j = 1000;

i = j * j;  /* overflow may occur */
```

`j * j` is 1,000,000 and `i` is `long`, but the result of `j * j` is an `int`, which can't represent 1,000,000.
Instead:
`i = (long) j * j;`
The first `j` is converted to `long`, so by implicit, usual arithmetic conversion the second `j` is also converted to `long`.

`i = (long) (j * j);    /*** WRONG ***/`
Overflow would occur before the cast.
