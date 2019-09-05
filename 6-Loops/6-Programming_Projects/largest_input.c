/* Finds largest in a series of numers entered by user */

#include <stdio.h>

int main(void)
{
    float i, largest = 0;

    while (i != 0)
    {
        printf("Enter a number: ");
        scanf("%f", &i);
        if (i > largest)
            largest = i;
    }

    printf("\nThe largest number entered was: %f\n", largest);

    return 0;
}