# 10.4 Scope

The same identifier may have several different meanings, determined by scope that it lives in.

When a declaration inside a block names an identifier that's already visible (because it has file scope or it's declared in an eclosing block), the new declaration temporarily "hides" the old one, and the identifier takes on new meaning. At the end of the block, the identifier regains its old meaning.

Here's a (somewhat extreme) example, where `i` has four different meanings:


```c
int i;              /* Declaration 1 */

void f(int i)       /* Declaration 2 */
{
    i = 1;          // refers to 2
}

void g(void)
{
    int i = 2;      /* Declaration 3 */

    if (i > 0) {    // refers to 3
        int i;      /* Delcaration 4 */

        i = 3;      // refers to 4
    }

    i = 4;          // refers to 3
}

void h(void)
{
    i = 5;          // refers to 1
}
```

- In Declaration 1, `i` is a variable with static storage duration and file scope.

- In Declaration 2, `i` is a parameter with block scope.

- In Declaration 3, `i` is an automatic variable with block scope.

- In Declaration 4, `i` is also automatic and has block scope.

`i` is used five times. C's scope rules allow us to determine the meaning of `i` in each case.

- The `i = 1` assignment refers to the parameter in Declaration 2, not the variable in Declaration 1, since Declaration 2 hides Declaration 1.

- The `i > 0` test refers to the variable in Declaration 3, since Declaration 3 hides Declaration 1 and Declaration 2 is out of scope.

- The `i = 3` assigment refers to the variable in Declaration 4, which hides Declaration 3.

- The `i = 4` assignment refers to the variable in Declaration 3. It can't refer to Declaration 4, which is out of scope.

- The `i = 5` assignment refers to the variable in Declaration 1.