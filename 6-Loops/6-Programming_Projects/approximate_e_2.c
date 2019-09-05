/* Approximates e by computing the value of 1 + 1/1! + 1/2! + 1/3! + ... + 1/n!
 * n contines to grow until the term 1/n! becomes smaller than a small 
 * (floating point) number entered by the user
 */

#include <stdio.h>

int main(void)
{
    float small_num, e = 1, denom = 1, term;

    printf("Enter a small decimal number to set as the limit on the term 1/n!: ");
    scanf("%f", &small_num);

    for (int i = 1; ; i++)
    {
        denom *= i;
        // printf("%f + 1.0f / %f\n", e, denom);

        term = 1.0f / denom;
        if (term < small_num)
            break;

        e += (1.0f / denom);
    }
    printf("\n");
    printf("e approximates to: %f\n", e);

    return 0;
}