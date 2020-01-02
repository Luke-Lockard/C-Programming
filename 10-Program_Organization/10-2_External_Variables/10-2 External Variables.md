# External Variables

Functions can communicate through ***external variables*** - variables that are declared outside the body of a function.

The properties of external variables (or ***global variables***, as they're sometimes called) are different from those of local variables.

- ***Static storage duration***. External variables have static storage duration.

- ***File scope***. An external variable has ***file scope***: it is visible from its point of declaration to the end of the enclosing file.
  - An external variable can be accessed (and potentially modified) by all functions that follow its declaration.

---

## Example: Using External Variables to Implement a Stack

***Stack***

- data structure

- operations on a stack are limited:
  - ***push*** - add an item to the top of the stack
  - ***pop*** - remove an item from the same end

- Examining or modifying an item that's not at the top of the stack is forbidden.

To implement in C:

- store items in an array, we'll call `contents`.

- separate integer named `top` marks the position of the stack.
  - Empty stack, `top` is 0.
  - To push an item on the stack, store it at the index of `top` and increment `top`.
  - Popping an item requires decrementing `top`, then using it as an index into `contents` to fetch the item that's popped.

Here's a program fragment that implements this. All five functions need access to `top`, and two functions need access to `contents`, so we'll make `contents` and `top` external.

```c
#include <stdbool.h>    /* C99 only */

#define STACK_SIZE 100

/* external variables */
int contents[STACK_SIZE];
int top = 0;

void make_empty(void)
{
    top = 0;
}

bool is_empty(void)
{
    return top == 0;
}

bool is_full(void)
{
    return top == STACK_SIZE;
}

void push(int i)
{
    if (is_full())
        stack_overflow();
    else
        contents[top++] = i;
}

int pop(void)
{
    if (is_empty())
        stack_underflow();
    else
        return contents[--top];
}
```

---

## Pros and Cons of External Variables

It's usually better for functions to communicate through parameters rather than by sharing external variables. Here's why:

- If the external variable is changed (ex, alter type), then every function that uses it could be affected.

- If an external variable is assigned an incorrect value, it may be difficult to identify the guilty function.

- Functions that rely on external variables are hard to reuse in other programs. A function that depends on an external variable isn't self-contained; to reuse the function, we'll have to drag along any external variables that it needs.

One common abuse of external variables is using the same external variable for different purposes in different functions. Could mislead someone later to think that the variables are related.

---

***PITFALL WARNING***

Making variables external when they should be local can lead to rather frustrating bugs.

Display a 10 x 10 arrangement of asterisks:

```c
int i;

void print_one_row(void)
{
    for (i = 1; i <= 10; i++)
        printf("*");
}

void print_all_rows(void)
{
    for (i = 1; i <= 10; i++) {
        print_one_row();
        printf("\n");
    }
}
```

Instead of printing 10 rows, `print_all_rows` prints only one row. When `print_one_row` returns after being called the first time, `i` will have the value 11.

---

## `Program` Guessing a Number

Simple game-playing program. Generates random number between 1 and 100, which the user attempts to guess in as few tries as possible.

Although `guess.c` works fine, it relies on an external variable. We made `secret_number` external so that both `choose_new_secret_number` and `read_guesses` could access it.

If we alter these functions a little bit, we should be able to move `secret_number` into the `main` function.

Modify `choose_new_secret_number` so that it returns the new number, and we'll rewrite `read_guesses` so that `secret_number` can be passed as an argument.