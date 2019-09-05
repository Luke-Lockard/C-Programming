/* Asks user for value for x, then displays he tvalue of
 * the following polynomial:
 *      3x^5 + 2x^4 - 5x^3 - x^2 + 7x - 6
 */

#include <stdio.h>

int main(void)
{
    int x, result;

    printf("Enter a value for x (int): ");
    scanf("%d", &x);

    /*
    result = 3 * (x * x * x * x * x) +
             2 * (x * x * x * x) -
             5 * (x * x * x) -
             (x * x) +
             7 * x - 6;
    */

    // Horner's Rule
    result = ((((3 * x + 2) * x - 5) * x - 1) * x + 7) * x - 6;
    
    printf("Result: %d\n", result);

    return 0;
}