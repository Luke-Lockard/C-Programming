# 2.7 Identifiers

Names for variables, functions, macros, and other entities are called ***identifiers***.

In C, an identifier may contain letters, digits, and underscores, but must begin with a letter or underscore.

Legal:

```c
times10 get_next_char _done
```

Not legal:

```c
10times get-next-char
```

C is ***case-sensitive***. So the following are all different identifiers:

```c
job joB jOb jOB Job JOb JOB
```

## There are some common conventions

Use only lowercase letters in identifiers (other than macros), with underscores inserted when necessary for legibility:

```c
symbol_table current_page name_and_address
```

Camel case:

```c
symbolTable currentPage nameAndAddress
```

C places no limit on the maximum length of an identifier. Don't be afraid to use long, descriptive names.

## Keywords

These ***keywords*** have special significance to C compilers and therefore can't be used as identifiers. Five keywords were added in C99.

| Keywords | | | |
| ----------- | ----------- | ----------- | ----------- |
| `auto` | `enum` | `restrict`* | `unsigned` |
| `break` | `extern` | `return` | `void` |
| `case` | `float` | `short` | `volitile` |
| `char` | `for` | `signed` | `while` |
| `const` | `goto` | `sizeof` | `_Bool`* |
| `continue` | `if` | `static` | `_Complex`* |
| `default` | `inline`* | `struct` | `_Imaginary`* |
| `do` | `int` | `switch` | |
| `double` | `long` | `typedef` | |
| `else` | `register` | `union` | |

\* C99 only

Keywords must appear in programs exactly as shown, with all lowercase letters.

---

### !!! PITFALL WARNING

Some compilers treat additional words as keywords! Identifiers that belong to the standard library are restricted as well. Identifiers that begin with an underscore are also restricted.

---
