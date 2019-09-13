# 2.1 Writing a Simple Program

## Compiling and Linking

Converting a C program into a form that the machine can execute usually involves three steps:

- ***Preprocessing.*** The ***preprocessor*** executes the ***directives*** (begin with `#`), adding things to the program and making modifications.
- ***Compiling.*** The compiler translates the modified program into machine instructions (***object code***).
- ***Linking.*** A ***linker*** combines the object code with any additional code needed to yeild a complete executable program.

This process is often automated.

Under UNIX, the C compiler is usually named `cc`. To compile a program, enter the following command in a terminal or command line window:

```bash
% cc <file>.c
```

`cc` leaves the executable program in a file called `a.out` by default. The `-o` option allows us to name the executable file:

```bash
% cc -o <name> <file>.c
```

---

## ***The GCC Compiler***

The GCC compiler is one of the most popular C compilers. Supplied with Linux and available for other platforms as well.

```bash
% gcc -o <name> <file>.c
```

---

## Integrated Development Environments

An IDE is a software package that allows us to edit, compile, link, execute, and even debug a program without leaving the environment.

An IDE can make it easier to error check and write large programs.