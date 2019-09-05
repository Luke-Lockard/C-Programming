/* Prints a one-month calendar. User specifies number of days and day of the week on which the month begins */

#include <stdio.h>

int main(void)
{
    int num_days, start_day;

    printf("Enter a number of days in month: ");
    scanf("%d", &num_days);
    printf("Enter starting day of the week (1=Sun, 7=Sat): ");
    scanf("%d", &start_day);

    for (int i = 1; i < start_day; i++) {
        printf("   ");
    }

    for (int i = 1, j = start_day; i <= num_days; i++, j++) {
        printf("%2d ", i);
        if (j == 7) {
            printf("\n");
            j = 0; // j is incremented to 1 at end of loop
        }
    }
    printf("\n");

    return 0;
}