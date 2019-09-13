# 2.6 Defining Names for Constants

When a program contains constants, it's often a good idea to give them names.

You can use a feature called a ***macro definition*** to do so.

```c
#define INCHES_PER_POUND 166
```

`#define` is a preprocessing directive, just like `#include`.

The preprocessor replaces each macro by the value that it represents.

```c
weight = (volume + INCHES_PER_POUND - 1) / INCHES_PER_POUND;
```

will become

```c
weight = (volume + 166 - 1) / 166;
```

The value of a macro can be an expression:

```c
#define RECIPROCAL_OF_PI (1.0f / 3.14159f)
```

If it contains operators, the expression should be enclosed in parentheses.

Uppercase macro names is a convention that has been followed for decades.
