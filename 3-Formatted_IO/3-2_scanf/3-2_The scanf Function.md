# 3.2 The `scanf` Function

`scanf` reads input according to a particular format.

```c
int i, j;
float x, y;

scanf("%d%d%f%f", &i, &j, &x, &y);
```

Like `printf`, make sure the number of conversion specifiers matches the number of input variables, and that each conversion specifier is appropriate for the corresponding input variable.

The `&` symbol normally precedes each variable in a `scanf` call.

---

### ***!!! PITFALL WARNING !!!***

Forgetting the `&` symbol can cause the program to crash or have other unpredictable results. It is not always required, but make sure if it is, that you use it.

---

`scanf` isn't usually used by professional C programmers, since it is an unforgiving way to read input and can lead to problems. However, we will use it for the early chapters.

## How `scanf` works

`scanf` is essentially a "pattern-matching" function that tries to match up groups of input characters with conversion specifications.

1. Starts at the left of the string, skipping white space until it finds an item.

2. Encounters an item & tries to match it to the current conversion specification

3. Reads that item until it encounters a character that doesn't match

4. If it read successfully, continues to next conversion specification

5. If it did not read successfully, it returns immediately without looking at the rest of the input data.

When `scanf` encounters a character that can't be part of the current item, the character is "put back" to be read again during the scanning of the next input item or during the next call of `scanf`.

So if bad input stops a call of `scanf` to terminate, the next `scanf` call will read the rest of the first input, which could lead to errors.

## Ordinary Characters in Format Strings

- ***White-space characters***. In `scanf`, any number of white space characters in the format string means skip zero or more white space characters. It will not force a white space character into the input.

- ***Other characters***. `scanf` compares the character with the next input character and tries to match it. If it doesn't match, it terminates.

## Confusing `printf` with `scanf`

Don't put `&` in front of variables in a call of `printf`:

```c
printf("%d %d\n", &i, &j);  /*** WRONG ***/
```

Don't include unecessary characters in the format string of a `scanf` call, because if the input doesn't match, the call will terminate.
