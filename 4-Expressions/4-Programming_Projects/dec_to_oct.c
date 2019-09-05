/* Converts a base 10 integer to octal (base 8) */

#include <stdio.h>

int main(void)
{
    int i, d1, d2, d3, d4, d5;

    printf("Enter a number betwee 0 and 32767: ");
    scanf("%d", &i);

    d5 = i % 8;
    i /= 8;
    d4 = i % 8;
    i /= 8;
    d3 = i % 8;
    i /= 8;
    d2 = i % 8;
    i /= 8;
    d1 = i % 8;

    printf("In octal, your number is: %d%d%d%d%d\n", d1, d2, d3, d4, d5);

    return 0;
}