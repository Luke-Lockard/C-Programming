/* Reverses a two digit number */

#include <stdio.h>

int main(void)
{
    int i, reverse = 0;

    printf("Enter a number: ");
    scanf("%d", &i);

    do {
        reverse = reverse * 10 + i % 10;
        i /= 10;
    } while (i > 0);
    
    printf("The reversal is: %d\n", reverse);

    return 0;
}