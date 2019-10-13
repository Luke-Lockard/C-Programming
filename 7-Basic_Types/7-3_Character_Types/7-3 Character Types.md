# 7.3 Character Types

The only remaining basic type is `char`, the character type.

Values of type `char` depend on the character set of the machine.

---

### ***Character Sets***

***ASCII** (American Standard Code for Information Interchange), a 7-bit code for representin 128 characters, is the most popular today.

0 to 9 are represented by 0110000 - 0111001, and uppercase A to Z represented by 1000001 - 1011010.

---

A variable of type `char` can be assigned to any single character:

```c
char ch;

ch = 'a';       /* lower-case a */
ch = 'A';       /* upper-case A */
ch = '0';       /* zero         */
ch = ' ';       /* space        */
```

Notice that character constants are enclosed in single quotes, not double quotes.

---

## Operations on Characters

*C treats characters as small integers*

In ASCII, characters range from 0000000 to 1111111, or 0 to 127. '`a`' has the value 97, '`A`' has the value 65, '`0`' has the value 48, and '` `' has the value 32.

Character constants actually have `int` type rather than `char`.

When a character appears in a computation, C uses its integer value:

```c
char ch;
int i;

i = 'a';        /* i is now 97   */
ch = 65;        /* ch is now 'A' */
ch = ch + 1;    /* ch is now 'B' */
ch++;           /* ch is now 'C' */
```

Characters can be compared, just like numbers. This `if` statement checks whether `ch` contains a lowercase letter; if so, it converts `ch` to upper case.

```c
if ('a' <= ch && ch < = 'z')
    ch = ch - 'a' + 'A';
```

Comparisons are done using the integer value of the characters. These values depend on the character set in use, so these comparisons may not be portable.

---

## Signed and Unsigned Characters

`char` exists in both `signed` and `unsigned` versions.

Signed normally has values -128 to 127, and unsigned has 0 to 255.

C standard doesn't specify if char is signed or unsigned; and compilers may treat them either way (some even allowing you to choose).

Most of the time, we don't care if `char` is signed or unsigned. If you're using a `char` to store a small integer, you might, so C allows the use of `signed` and `unsigned` to modify `char`:

```c
signed char sch;
unsigned char uch;
```

### **Portability Tip**

*Don't assume that `char` is either signed or unsigned by default. If it matters, use `signed char` or `unsigned char` instead of `char`.*

---

## Arithmetic Types

Integer types and floating types are collectively known as ***arithmetic types***.

### C89 arithmetic types

- Integral types
  - `char`
  - Signed integer types (`signed char`, `short int`, `int`, `long int`)
  - Unsigned integer tyeps (`unsigned char`, `unsigned short int`, `unsigned int`, `unsigned long int`)
  - Enumerated types

- Floating types (`float`, `double`, `long double`)

### C99 arithmetic types

- Integer types
  - `char`
  - Signed integer types, both standard (`signed char`, `short int`, `int`, `long int`, `long long int`) and extended
  - Unsigned integer types, both standard (`unsigned char`, `unsigned short int`, `unsigned int`, `unsigned long int`, `unsigned long long int`, `_Bool`) and extended
  - Enumerated types

- Floating types
  - Real floating types (`float`, `double`, `long double`)
  - Complex types (`float_Complex`, `double_Complex`, `long double_Complex`)

---

## Escape Sequences

Two types of escape sequences: ***character escapes*** and ***numeric escapes***.

### Complete set of Character Escapes

| Name | Escape Sequence |
| -- | -- |
| Alert (bell) | `\a` |
| Backspace | `\b` |
| Form feed | `\f` |
| New line | `\n` |
| Carriage return | `\r` |
| Horizontal tab | `\t` |
| Vertical tab | `\v` |
| Backslash | `\\` |
| Question mark | `\?` |
| Single quote | `\'` |
| Double quote | `\"` |

These are not all the escape sequences, just the most common. There are many more, but the best way to express them is with a numerical escape; using the ASCII number to reference the escape sequence,

Numeric sequences use the octal or hexadecimal value.

- An ***octal escape sequence*** consists of the `\` character followed by an octal number with at most three digits (unsigned, max is 377 octal). Ex: `\33` or `\033`. Octal numbers in escape sequences don't need a 0 in front like octal constants do.

- A ***hexadecimal escape sequence*** consists of `\x` followed by a hexadecimal number. No limit for the number of digits, but it must represent an unsigned character, so it can't exceed `FF` if characters are 8 bits long.

When used as a character constant, an escape sequence must be inclosed in single quotes.

Using `#define` to give them names is a good idea:

```c
#define ESC '\33`       /* ASCII escape character */
```

---

## Character-Handling Functions

Earlier in this section, we made an `if` statement that converts a lower-case letter to upper-case:

```c
if ('a' <= ch && ch <= 'z')
    ch = ch - 'a' + 'A';
```

A faster method -- and more portable -- is to call C's `toupper` library function:

```c
ch = toupper(ch);   /* converts ch to upper case */
```

Programs that call `toupper` need to have

```c
#include <ctype.h>
```

---

## Reading and Writing Characters using `scanf` and `printf`

The `%c` conversion specification allows `scanf` and `printf` to read and write single characters:

```c
char ch;

scanf("%c", &ch);   /* reads a single character */
printf("%c", ch);   /* writes a single character */
```

`scanf` doesn't skip white space before reading a character, as space is a character. It will read the space as the character into `ch`.

To force it to skip white space, put a space in the format string before `%c`:

```c
scanf(" %c", &ch);  /* skips white space, then reads ch */
```

Recall from Section 3.2 that a black in `scanf` means "skip zero or more white-space characters".

To detect the end of an input line, check to see if the character just read is the new-line character. The following loop will read and ignore all reamaining characters in the current input line:

```c
do {
    scanf("%c", &ch);
} while (ch != '\n');
```

---

## Reading and Writing Characters using `getchar` and `putchar`

`putchar` writes a single character:

```c
putchar(ch);
```

`getchar` reads and returns one character.

```c
ch = getchar();     /* reads a character and stores it in ch */
```

`getchar` actually returns an `int` value intead of `char`.

Like `scanf`, `getchar` doesn't skip white-space characters as it reads.

`getchar` and `putchar` are much faster than `printf` and `scanf`. They are much simpler, as `printf` and `scanf` are designed to read an write many kinds of data in a variety of formats.

`getchar` and `putchar` are usually implemented as macros for additional speed.

Here is the previos `scanf` loop that skips the rest of an input line, rewritten with `getchar`:

```c
do {
    ch = getchar();
}   while (ch != '\n');
```

Moving the call of `getchar` into the controlling expression allows us to condense the loop:

```c
while ((ch = getchar()) != '\n')
    ;
```

Actually, we don't need `ch`, and can compare the output of `getchar` directly:

### idiom

```c
while (getchar() != '\n')   /* skips rest of line */
    ;
```

This skips an infinite number of blank characters:

### idiom

```c
while ((ch = getchar()) == ' ')     /* skips blanks */
    ;
```

When the loop terminates, `ch` will contain the first nonblank character that `getchar` encountered.

---

### !!!PITFALL WARNING!!!

Be careful mixing `getchar` and `scanf` in a program, since `scanf` will leave behind characters that it has peeked but not read, including `\n`. `getchar` will fetch the first leftover characters, which man not be what the programmer has in mind.

```c
printf("Enter an integer: ");
scanf("%d", &i);
printf("Enter a command: ");
command = getchar();
```

---
