# 9.4 The `return` Statement

A non-`void` function must use the `return` statement to specify what value it will return.

```c
return expression ;
```

If the type of the expression in a return statement doesn't match the function's return type, the expression will be implicitly converted to the return type.

`return` statments may appear in functions whose return type is `void`, provided no expression is given:

```c
return;     /* return in a void function */
```

A return statement can be used to return from a function early:

```c
void print_int(int i)
{
    if (i < 0)
        return;
    printf("%d", i);
}
```

If a non-`void` function reaches the end of its body - fails to execute a `return` statement - the behavior of the program is undefined if it attempts to use the value returned by the function. Some compilers will issue a warning such as *"control reaches end of non-void function"* if they detect the possibility of a non-`void` function "falling off" the end of its body.
