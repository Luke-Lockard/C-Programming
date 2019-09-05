/* Calculates remaining balance on a loan after the first,
 * second, and third monthly payments;
 */

#include <stdio.h>

int main(void)
{
    float balance, rate, monthly_rate, monthly_payment;
    int months;

    printf("Enter amount of loan: ");
    scanf("%f", &balance);
    printf("Enter interest rate: ");
    scanf("%f", &rate);
    printf("Enter monthly payment: ");
    scanf("%f", &monthly_payment);
    printf("Enter number of payments: ");
    scanf("%d", &months);

    monthly_rate = (rate / 100) / 12;

    for (int i = 0; i < months; i++) {
        balance = balance * (1 + monthly_rate) - monthly_payment;
        printf("Balance remaining after %d payment: $%.2f\n", i + 1, balance);
    }

    return 0;
}