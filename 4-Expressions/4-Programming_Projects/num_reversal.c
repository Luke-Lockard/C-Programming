/* Reverses a two digit number */

#include <stdio.h>

int main(void)
{
    int i, d1, d2;

    printf("Enter a two-digit number: ");
    scanf("%d", &i);

    d1 = i / 10;
    d2 = i % 10;

    printf("The reversal is: %d\n", d2 * 10 + d1);

    return 0;
}