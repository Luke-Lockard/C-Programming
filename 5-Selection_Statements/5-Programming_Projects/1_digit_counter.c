/* Calculates how many digits a number contains (assumes the number has no more than 4 digits) */

#include <stdio.h>

int main(void)
{
    int number;

    printf("Enter a number: ");
    scanf("%d", &number);

    printf("The number has ");
    if (number > 999)
        printf(" 4 digits\n");
    else if (number > 99)
        printf(" 3 digits\n");
    else if (number > 9)
        printf(" 2 digits\n");
    else
        printf(" 1 digit\n");

    return 0;
}