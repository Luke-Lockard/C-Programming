/* Checks numbers for repeating digits.
 * v3 -- prints a table showing how many times each digit appears in the number
 */

#include <stdbool.h>    /* C99 only */
#include <stdio.h>

int main(void)
{
    int digit_seen[10] = {0};
    int digit;
    long n;

    printf("Enter a number: ");
    scanf("%ld", &n);

    while (n > 0) {
        digit = n % 10;
        digit_seen[digit]++;
        n /= 10;
    }

    printf("Digit:\t\t");
    for (digit = 0; digit < 10; digit++)
        printf("%3d", digit);
    printf("\nOccurances:\t");
    for (digit = 0; digit < 10; digit++)
        printf("%3d", digit_seen[digit]);
    printf("\n");
    return 0;
}