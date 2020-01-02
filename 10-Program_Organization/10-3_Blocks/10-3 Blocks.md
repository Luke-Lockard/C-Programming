# 10.3 Blocks

In section 5.2, we encountered compound statements of the form

`{ statements }`

C allows compound statements to contain declarations as well:

***block***     `{ declarations statements }`

We'll use the term ***block*** to describe such a compound statment. Here's an example of a block:

```c
if (i > j) {
    /* swap values of i and j */
    int temp = i;
    i = j;
    j = temp;
}
```

By default, a variable declared in a block has automatic storage duration: allocated when block is entered and deallocated when the block is exited.

The variable has block scope: it can't be referenced outside of the block.

A variable that belongs to a block can be declared `static` to give it static storage duration.

Putting temporary variables in blocks has two advantages:

1. It avoids clutturing the declarations at the beginning of a function body with variables that are only used briefly.

2. It reduces name conflicts. In our example, `temp` can be used elsewhere in the same function for different purposes.

***`C99`***

C99 allows variables to be declared anywhere within a block, just as it allows variables to be declared anywhere within a function.