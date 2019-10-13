/*
 * Computes the factorial of a positive integer.
 * Largest value of n where the program correctly computes n! when n is a
 * short: 7, factorial is 5,040
 * int: 12, factorial is 479,001,600
 * long: 20, factorial is 2,432,902,008,176,640,000
 * long long: same as long
 * float: 13, factorial is 6,227,020,800
 * double: 22, factorial is 1,124,000,727,777,607,680,000
 * long double: over 25..
 */

#include <stdio.h>

int main(void)
{
    // short n, factorial;
    // int n, factorial;
    // long n, factorial;
    // long long n, factorial;
    // float n, factorial;
    // double n, factorial;
    long double n, factorial;

    printf("Enter a positive integer: ");
    // scanf("%hd", &n);
    // scanf("%d", &n);
    // scanf("%ld", &n);
    // scanf("%lld", &n);
    // scanf("%f", &n);
    // scanf("%lf", &n);
    scanf("%Lf", &n);

    factorial = n;
    // short i;
    // int i;
    // long i;
    // long long i;
    // float i;
    // double i;
    long double i;
    for (i = n - 1; i > 0; i--) {
        factorial *= i;
    }

    // printf("Factorial of %hd: %hd\n", n, factorial);
    // printf("Factorial of %d: %d\n", n, factorial);
    // printf("Factorial of %ld: %ld\n", n, factorial);
    // printf("Factorial of %lld: %lld\n", n, factorial);
    // printf("Factorial of %f: %f\n", n, factorial);
    // printf("Factorial of %lf: %lf\n", n, factorial);
    printf("Factorial of %Lf: %Lf\n", n, factorial);

    return 0;
}