# 7.2 Floating Types

C provides three ***floating types***:

- `float`: Single-precision floating-point

- `double`: Double-precision floating-point

- `long double`: Extended-precision floating-point

C standard doesn't provide how much precision the `float`, `double`, and `long double` types provide, since different computers may store floating-point numbers in different ways.

Most modern computers follow the IEEE Floating-Point Standard

---

### ***The IEEE Floating-Point Standard***

Single precision - 32 bits

Double precision - 64 bits

Numbers stored in scientific notation, having three parts: a ***sign***, an ***exponent***, and a ***fraction***.

Number of bits reserved for exponent determines how large (or small) numbers can be.

Number of bits reserved for fraction determines the precision.

Single-precision: exponent is 8 bits, fraction is 23 bits, max value of 3.40 * 10^38, with precision of about 6 decimal digits.

---

The `long double` type is usually 80 bits or 128 bits, varying by machine.

### Floating Type Characteristics (IEEE Standard)

| Type | Smallest Positive Value | Largest Value | Precision |
| -- | -- | -- | -- |
| `float` | 1.17549 x 10^-38 | 3.40282 x 10^38 | 6 digits |
| `double` | 2.22507 x 10^-308 | 1.79769 x 10^308 | 15 digits |

`<float.h>` has macros that define the characteristics of floating types.

C99 has the ***real floating types*** `float`, `double`, and `long double`, and ***complex types*** `float_Complex`, `double_Complex`, and `long double_Complex`.

---

## Floating Constants

Floating constants can be written in a variety of ways. These are all valid ways to write the number 57.0:

`57.0 57. 57.0e0 5.7e1 5.7e+1 .57e2 570.e-1`

Must contain a decimal point and/or an exponent. An exponent must be proceeded by the letter `E` or `e`. An optional `-` or `+` may come after the `e`/`E`.

Floating constants stored as `double` by default.

To indicate only single precision, put `F` or `f` at the end of the constant. To indicate a `long double`, put `l` or `L` at the end.

---

## Reading and Writing Floating-Point Numbers

Conversion specifications `%e`, `%f`, and `%g` are used for reading and writing single-precision floating-point numbers. (Refer to 3.1)

`double` and `long double` require slightly different conversions:

- When *reading* a value of type `double`, put the letter `l` in front of `e`, `f`, or `g`:
  - ```c
    double d;

    scanf("%lf", &d);
    ```
  - *Note:* Only use `l` in a `scanf` format string, not a `printf` string. In `printf`, `e`, `f`, and `g` conversions can be used for `float` or `double`. (C99 legalizes the use of `%le`, `%lf`, and `%lg` but it has no effect.)

- When reading or writing a value of type `long double`, put the letter `L` in front of `e`, `f`, or `g`:
  - ```c
    long double ld;

    scanf("%Lf", &ld);
    printf("%Lf", ld);
    ```
