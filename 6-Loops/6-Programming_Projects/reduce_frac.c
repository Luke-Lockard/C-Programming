/* Reduces fraction to lowest terms */

#include <stdio.h>

int main(void)
{
    int num, denom, i, j, temp;

    printf("Enter a fraction: ");
    scanf("%d/%d", &num, &denom);

    i = num, j = denom;

    while (i > 0)
    {
        temp = j % i;
        j = i;
        i = temp;
    }

    printf("In lowest terms: %d/%d\n", num / j, denom / j);

    return 0;
}