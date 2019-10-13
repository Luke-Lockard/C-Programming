/* Adds, subtracts, multiplies, or divides two fractions */

#include <stdio.h>

int main(void)
{
    int num1, denom1, num2, denom2, result_num, result_denom;
    char operator;

    printf("Enter fraction equation (x/x+x/x). Use +, -, *, or /: ");
    scanf("%d/%d%c%d/%d", &num1, &denom1, &operator, &num2, &denom2);

    // happens in every case
    result_denom = denom1 * denom2;

    switch (operator) {
        case '+':
            result_num = num1 * denom2 + num2 * denom1;
            printf("The sum is %d/%d\n", result_num, result_denom);
            break;
        case '-':
            result_num = num1 * denom2 - num2 * denom1;
            printf("The difference is %d/%d\n", result_num, result_denom);
            break;
        case '*':
            result_num = num1 * denom2 * num2 * denom1;
            printf("The product is %d/%d\n", result_num, result_denom);
            break;
        case '/':
            result_num = (num1 * denom2) / (num2 * denom1);
            printf("The quotient is %d/%d\n", result_num, result_denom);
            break;
    }

    return 0;
}