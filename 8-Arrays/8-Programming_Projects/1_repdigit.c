/* Checks numbers for repeating digits. v2 -- show which digits, if any, were repeated */

#include <stdbool.h>    /* C99 only */
#include <stdio.h>

int main(void)
{
    int digit_seen[10] = {0};
    int digit;
    long n;
    bool repeat = false;

    printf("Enter a number: ");
    scanf("%ld", &n);

    while (n > 0) {
        digit = n % 10;
        digit_seen[digit]++;
        if (digit_seen[digit] > 1)
            repeat = true;
        n /= 10;
    }

    if (repeat) {
        printf("Repeated digit(s):");
        for (digit = 0; digit < 10; digit++) {
            if (digit_seen[digit] > 1)
                printf(" %d", digit);
        }
        printf("\n");
    }
    else {
        printf("No repeated digit\n");
    }

    return 0;
}