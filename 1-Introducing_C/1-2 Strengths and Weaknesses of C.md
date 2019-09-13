# 1.2 Strengths and Weaknesses of C

- ***C is a low-level language.*** Suitable for systems programming, C provides access to machine level concepts (bytes and addresses) that other languages try to hide. Operations closely correspond to computer's built-in instructions, making it very fast.
- ***C is a small language.*** Limited set of features compared to other languages. To keep it small, C relies of a "library" of standard functions.
- ***C is a permissive language.*** Allows a wider degree of latitude, and doesn't mandate detailed error-checking.

## Strengths

- ***Efficiency.*** C programs can run quickly and in limited amount of memory.
- ***Portability.*** C is standardized, and compilers are small and easily written, making hem widely available.
- ***Power.*** C's large collection of data types and operators make it possible to accomplish a lot with less code.
- ***Flexibility.*** Used in all kinds of applications. Few restrictions on its features. Allows operations that would be illegal in other languages.
- ***Standard library.*** Contains hundreds of functions for I/O, string handling, storage allocation, etc.
- ***Integration with UNIX.*** C is powerful in combination with UNIX (including popular variant known as Linux).

## Weaknesses

- ***C programs can be error-prone.*** C's flexibility allows the programmer to make mistakes. C compilers won't detect these issues, creating pitfalls for the unwary.
- ***C programs can be difficult to understand.*** C has features that aren't found in other languages. They can be combined in many ways, which can make it hard for those other than the original programmer to understand.
- ***C programs can be difficult to modify.*** Large programs can be hard to change if not designed with maintenance in mind. C does not provide classes and packages used by other languages to divide a large program into managable pieces.

## Effective Use of C

- ***Learn how to avoid C pitfalls.***
- ***Use software tools to make programming more reliable.*** `lint` can subject a program to a more extensive error analysis than most C compilers. Debuggers are also useful.
- ***Take advantage of existing code libraries.*** Many libraries (collections of functions) have been written that you can include in your own programs. Libraries for common tasks, including user-interface development, graphics, communications, database management, and networking are readily available.
- ***Adopt a sense of coding conventions.*** Well chosen conventions keep a program uniform, easier to read, and easier to modify.
- ***Avoid "tricks" and overly complex code.*** There may be several ways to accomplish the same task. The shortest solutions can often be the hardest to comprehend.
- ***Stick to the standard.*** Most compilers provide language features and functions that aren't part of C89 or C99. For portability, it's best to avoid nonstandard features unless absolutely necessary.
