/* Evaluates an expression.
 * Operands are floating-point numbers
 * Operators are +, -, *, and /
 * Expression is evaluated left to right, no operator takes precedence over any other operator.
 */

#include <stdio.h>

int main(void)
{
    char operator;
    float operand, result;

    printf("Enter an expression: ");

    // Get first operand, which is currently the result.
    scanf("%f", &result);

    while ((operator = getchar()) != '\n') {
        scanf("%f", &operand);

        switch (operator) {
            case '+':
                result += operand;
                break;
            case'-':
                result -= operand;
                break;
            case '*':
                result *= operand;
                break;
            case '/':
                result /= operand;
                break;
        }
    }

    printf("Result: %f\n", result);

    return 0;
}