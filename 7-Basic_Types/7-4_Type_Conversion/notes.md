## Intro

The compiler handles *implicit conversions* automatically.
C also allows the programmer to perform *explicit conversions*, using the cast operator.

Implicit conversions are performed when:
- **Arithmetic**: the operands in an arithmetic expressions don't have the same type
- **Assignment**: the type of the expression on the right side of an assignment doesn't match the type of the variable on the left side
- **Function Parameters**: type of argument in a function call doesn't match the type of the corresponding parameter
- **Function Return**: type of expression in `return` statement doesn't match the function's return type


## The Usual Arithmetic Conversions

The strategy behind arithmetic conversion is to convert operands to the "narrowest" type that will safely accomodate both values.
The operand with the narrower type is ***promoted*** to the type of the other parameter.

- ***The type of either operand is a floating type***:
    `float` -> `double` -> `long double`
- *** Neither operand type is a floating type***:
    `int` -> `unsigned int` -> `long int` -> `unsigned long int`


```
char c;
short int s;
int i;
unsigned int u;
long int l;
unsigned long int ul;
float f;
double d;
long double ld;

i = i + c;      /* c is converted to int                */
i = i + s;      /* s is converted to int                */
u = u + i;      /* i is converted to unsigned int       */
l = l + u;      /* u is converted to long int           */
ul = ul + l;    /* l is converted to unsigned long int  */
f = f + ul;     /* ul is converted to float             */
d = d + f;      /* f is converted to double             */
ld = ld + d;    /* d is converted to long double        */
```


## Conversion during assignment

**Rule**: Expression on right side of assignment is converted to the type of the variable on the left side.