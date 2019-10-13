/* Prints a table of compound interest */

#include <stdio.h>

#define NUM_RATES ((int) (sizeof(value) / sizeof(value[0])))
#define INITIAL_BALANCE 100.00

int main(void)
{
    int i, low_rate, num_years, year, month;
    double value[5];

    printf("Enter interest rate: ");
    scanf("%d", &low_rate);
    printf("Enter number of years: ");
    scanf("%d", &num_years);

    printf("\nYears");
    for (i = 0; i < NUM_RATES; i++) {
        printf("%9d%%", low_rate + i);
        value[i] = INITIAL_BALANCE;
    }
    printf("\n");

    for (year = 1; year <= num_years; year++) { // for each year
        printf("%3d    ", year);
        for (i = 0; i < NUM_RATES; i++) {   // for each rate
            for (month = 0; month < 12; month++) {   // for each month
                // compound the interest by the rate (in percent) 
                value[i] += (low_rate + i) / 100.0 * value[i];
            }
            printf("%10.2f", value[i]);
        }
        printf("\n");
    }

    return 0;
}