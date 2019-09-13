# 7.5 Type Definitions

In Section 5.2 we used the `#define` directive to create a macro that could be used as a boolean type:

```C
#define BOOL int;
```

A better way using ***type definition***:

```C
typedef int Bool;
```

Name of the type being defined comes last.
Capitalizing first letter of a type name (`Bool`) is a convention some C programmers employ (not required).
`Bool` is now a type name that the compiler recognizes--in variable declarations, cast expressions, and elsewhere.

```C
Bool flag;  /* same as int flag; */
```

## Advantages of Type Definitions

Make programs more understandable.

Ex: Suppose variables `cash_in` and `cash_out` will be used to store dollar amounts.

```C
typedef float Dollars;

Dollars cash_in, cash_out;
```

Better than writing:

```C
float cash_in, cash_out;
```

Easily modify both variables to type double by changing the type definition.

```C
typedef double Dollars;
```

Without the type definition, we would need to locate all `float` variables that store dollar amounts and change their declarations

## Type Definitions and Portability

One problem with moving a program from one computer to another is that types may have different ranges on different machines.

```C
i = 100000;
```

is fine on a machine with 32-bit integers, but will fail on a machine with 16 bit integers.

>For greater portability, consider using `typedef` to define new names for integer types

Suppose we have a program that needs variables capable of storing product quantities int the range 0-50,000.

```C
typedef int Quantity;

Quantity q;
```

When we want to transport the program to a machine with shorter integers, change the definition of `Quantity`:

```C
typedef long Quanitity;
```

This doesn't solve all the problems, since calls of `printf` and `scanf` that use `Quantity` variables will need to change `%d` to `%ld`.

C library uses `typedef` to create types that can vary from one C implementation to another; these types often end with `_t`, such as `ptrdiff_t`, `size_t`, and `wchar_t`.

```C
typedef long int ptrdiff_t;
typedef unsigned long int size_t;
typedef int wchar_t;
```

### C99

In C99, the `<stdint.h>` header uses `typedef` to define names for integer types with a particular number of bits.

Ex: `int32_t` is a signed integer with exactly 32 bits.
