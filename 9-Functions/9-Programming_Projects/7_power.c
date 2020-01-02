/* 
 * Computes value of x to the n, with x and n given by user.
 * 
 * If n is a power of 2, x^n can be computed by squaring.
 * 
 * If n is even, use the formula x^n = (x^(n/2))^2.
 * 
 * If n is odd, use the formula x^n = x * x^(n-1).
 */

#include <stdio.h>

int power(int x, int n);

int main(void)
{
    int x, n;

    printf("Enter value for x: ");
    scanf("%d", &x);
    printf("Enter value for n: ");
    scanf("%d", &n);

    printf("x to the power of n is %d\n", power(x, n));

    return 0;
}

int power(int x, int n)
{
    if (n == 0) {
        return 1;
    }

    if (n % 2 == 0) {
        return power(x, n / 2) * power(x, n / 2);
    } else {
        return x * power(x, n - 1);
    }
}