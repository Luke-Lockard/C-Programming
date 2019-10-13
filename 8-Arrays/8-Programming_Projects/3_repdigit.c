/* Checks numbers for repeating digits */

#include <stdbool.h>    /* C99 only */
#include <stdio.h>

int main(void)
{
    bool digit_seen[10] = {false};
    int digit;
    long n;

    while(true) {
        printf("Enter a number: ");
        scanf("%ld", &n);

        if (n <= 0)
            break;

        while (n > 0) {
            digit = n % 10;
            if (digit_seen[digit])
                break;
            digit_seen[digit] = true;
            n /= 10;
        }

        // clear digit_seen[]
        for (int i = 0; i < 10; i++)
            digit_seen[i] = false;

        if (n > 0)
            printf("Repeated digit\n");
        else
            printf("No repeated digit\n");
    }

    return 0;
}