/* Approximates e by computing the value of 1 + 1/1! + 1/2! + 1/3! + ... + 1/n! where n is an integer entered by the user */

#include <stdio.h>

int main(void)
{
    int n;
    float e = 1, denom = 1;

    printf("Enter a number n: ");
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        denom *= i;
        printf("%f + 1.0f / %f\n", e, denom);
        e += (1.0f / denom);
    }
    printf("\n");
    printf("e approximates to: %f\n", e);

    return 0;
}