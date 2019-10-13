/* Sums a series of numbers (using double variables) */

#include <stdio.h>

int main(void)
{
    double n, sum = 0.0l;

    printf("This program sums a series of double values.\n");
    printf("Enter numbers (0 to terminate): ");

    scanf("%lf", &n);
    while (n != 0.0l)
    {
        sum += n;
        scanf("%lf", &n);
    }
    printf("The sum is: %lf\n", sum);

    return 0;
}