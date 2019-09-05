/* Given a dollar amount, shows how to pay
 * that amount using the smallest number of
 * $20, $10, $5, and $1 bills.
 */

#include <stdio.h>

int main(void)
{
    int dollar_amount, remaining, twenties, tens, fives, ones;

    printf("Enter a dollar amount: ");
    scanf("%d", &dollar_amount);

    twenties = dollar_amount / 20;
    remaining = dollar_amount - (20 * twenties);
    tens = remaining / 10;
    remaining = remaining - (10 * tens);
    fives = remaining / 5;
    remaining = remaining - (5 * fives);
    ones = remaining;

    printf("$20 bills: %d\n", twenties);
    printf("$10 bills: %d\n", tens);
    printf(" $5 bills: %d\n", fives);
    printf(" $1 bills: %d\n", ones);

    return 0;
}