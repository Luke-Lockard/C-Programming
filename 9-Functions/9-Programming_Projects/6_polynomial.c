/* 
 * Computes the value of the following polynomial
 * 3x^5 + 2x^4 - 5x^3 - x^2 - 7x - 6
 */

#include <stdio.h>
#include <math.h>

int solve(int x);

int main(void)
{
    int x;

    printf("Enter a value for x: ");
    scanf("%d", &x);

    printf("The value of the polynomial is %d\n", solve(x));

    return 0;
}

int solve(int x)
{
    return 3 * pow(x, 5) + 2 * pow(x, 4) - 5 * pow(x, 3) - pow(x, 2) + 7 * x - 6;
}