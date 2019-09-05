/* Reverse a 3 digit number */

#include <stdio.h>

int main(void)
{
    int i, d1, d2, d3;

    printf("Enter a three-digit number: ");
    scanf("%d", &i);

    d1 = i / 100;
    d2 = i % 100 / 10;
    d3 = i % 100 % 10;

    printf("The reversal is: %d\n", d3 * 100 + d2 * 10 + d1);

    return 0;
}