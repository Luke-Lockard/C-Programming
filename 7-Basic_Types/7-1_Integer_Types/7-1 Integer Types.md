# 7.1 Integer Types

***integer types*** are whole numbers.

---

## ***Signed and Unsigned Integers***

Leftmost bit of a ***signed*** integer is the **sign bit*.

- 0 if number is positive or 0

- 1 if negative

The largets 16-bit signed integer in C is

`0111111111111111`

which has the value 32,767 (2^15 - 1).

The largest 32-bit signed integer is

`01111111111111111111111111111111`

which has the value 2,147,483,647 (2^31 - 1).

The leftmost bit of an ***unsigned*** integer is part of the magnitude of the number.

The largest 16-bit unsigned integer is 65,535 (2^16 - 1) and the largest 32-bit unsigned integer is 4,294,967,295 (2^32 - 1).

Integer values are signed by default.

Unsigned variables have to be declared with `unsigned`.

Unsigned numbers are primarily used for systems programming and low-level, machine-dependent applications.

---

The `int` type is usually 32 bits, but may be 16 bits on older CPUs.

C also has ***long*** and ***short*** integer types, with ***signed*** and ***unsigned*** versions of each.

The `signed` declaration isn't necessary, except for clarification.

***Integer Types on a 64-bit Maachine***

| Type | Smallest Value | Largest Value |
| --- | --- | --- |
| `short int` | -32,768 | 32,768 |
| `unsigned short int` | 0 | 65,535 |
| `int` | -2,147,483,648 | 2,147,483,647 |
| `unsigned int` | 0 | 4,294,967,295 |
| `long int` | -9,223,372,036,854,775,808 | 9,233,372,036,854,775,808 |
| `unsigned long int` | 0 | 18,446,744,073,709,551,615 |

On a 16-bit machine, `int` is the same as `short int` (16 bits), and `long int` is 32 bits (a 32 or 64-bit machine's `int`).

On a 32-bit machine, a `long int` is the same as an `int` (32 bits).

These ranges aren't mandated by the C standard and may vary from one compiler to another.

One way to determine the ranges of the integer types for a particular implementation is to check the `<limits.h>` header, which is part of the standard library. This header defines macros that represent the smallest and largest values of each integer type.

---

## Integer Types in C99

C99 provides two additional standard integer types, `long long int` and `unsigned long long int`.

These types are *required* to be 64 bits wide.

The `short int`, `int`, `long int` and `long long int` (along with the `char` type) are the ***standard signed integer types*** in C99.

The `unsigned short int`, `unsigned int`, `unsigned long int`, and `unsigned long long int` (along with the `unsigned char` type and the `_Bool` type) are the ***standard unsigned integer types***.

In addition to standard integer types, C99 standard allows implementation-defined ***extended integer types***, both signed and unsigned. A compiler might provide signed and unsigned 128-bit integer types.

---

## Integer Constants

***constants*** -- numbers that appear in the text of a program, not numbers that are read, writtin, or computed.

C allows integer constants to be written in decimal (base 10), octal (base 8), or hexadecimal (base 16).

---

### ***Octal and Hexadecimal Numbers***

Octal is written with digits 0 through 7. Each position in a octal represents a power of 8.

Hexadecimal is written with digits 0 through 9 and letters A through F, which stand for 10 through 15. Each position in a hex number represents a power of 16.

---

- ***Decimal*** contian digits between 0 and 9 and cannot start with a zero.

- ***Octal*** contains only digits between 0 and 7 and *must* begin with a zero.

- ***Hexadecimal*** contains digits between 0 and 9 and letters between `a` and `f`, and always begin with `0x`.
  - Letters may be upper or lowercase: `0xff`, `0xfF`, `0xFf`, `0xFF`, `0Xff`, `0XFf`, `0XfF`, `0XFF`

Numbers can switch from one notation to the other and even be mixed in expressions: `10 + 015 + 0x20` has the value 55 (decimal).

For *decimal* integer constants the compiler will store it as an `int`, then if it is too large as a `long int`, and `unsigned long int` as a last resort.

For *octal* and *hexadecimal* numbers the compiler will start with `int` and move up, includeing `unsigned` types, to `unsigned long int` until it finds one capable of representing the constant.

To force the compiler to treat a constant as a long integer, follow it with the letter `L` or `l`:

```c
15L     0377L   0xfffL
```

To indicate a constant as unsigned, follow it with `U` or `u`:

```c
15U     0377U   0x7fffU
```

`L` and `U` may be used incombination with each other:

```c
0xffffffffUL
```

The order of `L` and `U` doesn't matter, nor does their case.

---

## Integer Constants in C99

Integer constants that end in `LL` or `ll` (the case of the letters must match), have type `long long int`.

Adding `U` or `u` before or after the `LL` or `ll` denotes a constant of type `unsigned long long int`.

When C99 determines the type of a constant it includes `long long` for decimal and `unsigned long long` for octal and hexidecimal in the list of possible types.

There's also provision for a constant to have an extended integer type.

---

## Integer Overflow

When the result of arithmetic operations on integers is too large to be represented by their type, ***overflow*** occurs, as the extra bits are lost.

With *signed* integers, the behavior is undefined.

With *unsigned* the result will be the correct answer modulo 2^*n*, where *n* is the number of bits used to store the result.

---

## Reading and Writing Integers

Reading and writing unsigned, short, and long integers requires several new conversion specifiers:

- Use `u`, `o`, and `x` when reading or writing *unsigned* integers. `u` is decimal, `o` is octal, and `x` is hexidecmial:
  - ```c
    unsigned int u;

    scanf("%u", &u);    /* reads  u in base 10 */
    printf("%u", u);    /* writes u in base 10 */
    scanf("%o", &u);    /* reads  u in base  8 */
    printf("%o", u);    /* writes u in base  8 */
    scanf("%x", &u);    /* reads  u in base 16 */
    printf("%x", u);    /* writes u in base 16 */
    ```

- For *short*, put the letter `h` in front of `d`, `o`, `u`, or `x`:
  - ```c
    short s;

    scanf("%hd", &s);
    printf("%hd", s);
    ```

- For *long*, put the letter `l` in from of `d`, `o`, `u`, or `x`:
  - ```c
    long l;
    scanf("%ld", &l);
    printf("%ld", l);
    ```

- For *long long* (C99 only), put `ll` in front of `d`, `o`, `u`, or `x`:
  - ```c
    long long ll;

    scanf("%lld", &ll);
    printf("%lld", &ll);
    ```
