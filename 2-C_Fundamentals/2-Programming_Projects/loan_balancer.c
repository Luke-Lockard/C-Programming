/* Calculates remaining balance on a loan after the first,
 * second, and third monthly payments;
 */

#include <stdio.h>

int main(void)
{
    float balance, rate, monthly_rate, monthly_payment;

    printf("Enter amount of loan: ");
    scanf("%f", &balance);
    printf("Enter interest rate: ");
    scanf("%f", &rate);
    printf("Enter monthly payment: ");
    scanf("%f", &monthly_payment);

    monthly_rate = (rate / 100) / 12;

    balance = balance * (1 + monthly_rate) - monthly_payment;
    printf("Balance remaining after first payment: %.2f\n", balance);

    balance = balance * (1 + monthly_rate) - monthly_payment;
    printf("Balance remaining after second payment: %.2f\n", balance);

    balance = balance * (1 + monthly_rate) - monthly_payment;
    printf("Balance remaining after third payment: %.2f\n", balance);

    return 0;
}