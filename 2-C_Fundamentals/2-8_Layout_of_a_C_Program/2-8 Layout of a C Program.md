# 2.8 Layout of a C Program

We can think of a C program as a series of ***tokens***: groups of characters that can't be split up without changing their meaning.

```c
printf("Height: %d\n", height);
```

consists of 7 tokens:

1. `printf`
2. `(`
3. `"Height: %d\n"`
4. `,`
5. `height`
6. `)`
7. `;`

Space between tokens is only required when necessary to separate those tokens:

```c
/* Converts a Fahrenheit temperature to Celsius */
#include <stdio.h>
#define FREEZING_PT 32.0f
#define SCALE_FACTOR (5.0f/9.0f)
int main(void){float fahrenheit,celcius;printf("Enter Fahrenheit temperature: ");scanf("%f", &fahrenheit);celsius=(fahrenheit-FREEZING_PT)*SCALE_FACTOR;printf("Celsius equivalent: %.1f\n", celsius);return 0;}
```

- *Statements can be divided* over any number of lines.
  - ```c
    printf("Dimensional weight (pounds): %d\n",
    (volume + INCHES_PER_POUND - 1) / INCHES_PER_POUND);
    ```

- *Space between tokens* makes it easier to read.
  - ```c
    volume = height * lenth * width;
    ```

- *Indentation* can make nesting easier to spot.
- *Blank lines* can divide a program into logical units.
