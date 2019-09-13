# 2.4 Variables and Assignment

***Variables*** store data temporarily during program execution.

## Types

Every variable has a ***type***, which specifies what kind of data it will hold.

C has many types, but we will only look at `int` and `float` right now.

`int` (short for integer) holds whole numbers.

`float` (short for *floating-point*) can store numbers with digits after the decimal point.

## Declarations

Variables must be ***declared***.

To declare a variable, first specify the type, then the name:

```c
int height;
float profit;
```

If several variables have the same type, their declarations can be combined.

```c
int height, length, width, volume;
float profit, loss;
```

## Assignment

A variable can be given value by means of an *assignment*.

```c
height = 8;
length = 12;
width = 10;
```

The numbers `8`, `12`, and `10` are said to be ***constants***.

A variable must be declared before it can be assigned.

```c
int height;
height = 8;
```

```c
height = 8; /*** WRONG ***/
int height;
```

It's best to append the letter `f` (for "float") to a constant that contains a decimal point if the number is assigned to a `float` variable.

```c
profit = 2150.48f
```

In general, the right side of an assigment can be an ***expression***, involving constants, variables, and operators.

```c
volume = height * length * width;
```

## Printing the Value of a Variable

```c
printf("Height: %d\n", height);
```

`%d` is a placeholder for where the value of `height` is to be filled in during the printing.

`%d` works only for `int` variables. `%f` is for `float`.

By default, `%f` displays a number with 6 digits after the decimal point. To force `%f` to display *p* digits after the decimal point, put *.p* between `%` and `f`. EX: to print the line

```c
Profit: $21250.48
```

do

```c
printf("Profit: $%.2f\n", profit);
```

There's no limit to the number of variables that can be printed in a single call of `printf`.

```c
printf("Height: %d Length: %d\n", height, length);
```

## Initialization

Some variables are automatically set to zero when a program begins to execute, but most are not. An unassigned variable without a default value is said to be ***uninitialized***.

---

### !!! PITFALL WARNING

Attempting to access the value of an uninitialized variable may yeild unpredictable results, like random numbers or causing the program to crash.

---

Any number of variables can be initialized in the same declaration:

```c
int height = 8, length = 12, width = 10;
```

In the following example, only the width is initialized.

```c
int height, length, width = 10;
```

## Printing Expressions

`printf` can display the value of any numeric expression.

```c
volume = height * length * width;
printf("%d\n", volume);
```

could be replaced by

```c
printf("%d\n", height * length * width);
```
