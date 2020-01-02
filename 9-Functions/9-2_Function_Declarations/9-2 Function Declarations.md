# 9.2 Function Declarations

In the programs in 9.1, the definitions of functions came before the point at which they were called. C doesn't require this, but the compiler will have issues.

If the definition of a function comes after the function call, when the compiler sees the function call, it doesn't know what the function returns or what parameters it takes. So it creates an ***implicit declaration*** of the function, which assumes that it returns type `int` (the default for functions). It also does the default argument promotions for the parameters.

When the compiler encounters the function definition, if it's return type is different, it will give an error message.

A ***function declaration*** can solve this problem. It gives the compiler an idea of the function so it won't do ***implicit declaration***:

```
return-type function-name (parameters) ;
```

Ex:

```c
#include <stdio.h>

double average(double a, double b); /* DECLARATION */

int main(void)
{
    double x, y, z;

    printf("Enter three numbers: ");
    scanf("%lf%lf%lf", &x, &y, &z);
    printf("Average of %g and %g: %g\n", x, y, average(x, y));
    printf("Average of %g and %g: %g\n", y, z, average(y, z));
    printf("Average of %g and %g: %g\n", x, z, average(x, z));

    return 0;
}

double average(double a, double b)  /* DEFINITION */
{
    return (a + b) / 2;
}
```

This type of function declaration is a ***function prototype*** (different from older style where parentheses left empty).

The function prototype doesn't have to specify the *names* of the parameters, as long as the *types* are present:

```c
double average(double, double);
```

Sometimes there are legitimate reasons to do so.

---

### C99

C99 adopted the rule that a function declaration or definition must precede the function call. Will throw an error otherwise.