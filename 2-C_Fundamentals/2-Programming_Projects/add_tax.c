/* Calculates price given dollar & cents amount with 5% tax */

#include <stdio.h>

#define TAX .05f

int main(void)
{
    float amount, with_tax;

    printf("Enter an amount of dollars & cents: ");
    scanf("%f", &amount);

    with_tax = amount * (1 + TAX);

    printf("With tax added: %.2f\n", with_tax);


    return 0;
}