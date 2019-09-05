/* Compares any number of given dates and says which comes first */

#include <stdio.h>

int main(void)
{
    int m, d, y, earliest_date_m = 0, earliest_date_d = 0, earliest_date_y = 0;

    for(;;) {
        printf("Enter a date (mm/dd/yy): ");
        scanf("%d/%d/%d", &m, &d, &y);

        if (m == 0 && d == 0 && y == 0) 
            break;

        if (earliest_date_d == 0 || earliest_date_m == 0 || earliest_date_y == 0)
            earliest_date_d = d, earliest_date_m = m, earliest_date_y = y;

        if (y < earliest_date_y)
        {
            earliest_date_d = d, earliest_date_m = m, earliest_date_y = y;
        }
        else if (y == earliest_date_y)
        { // same year
            if (m < earliest_date_m)
            {
                earliest_date_d = d, earliest_date_m = m, earliest_date_y = y;
            }
            else if (m == earliest_date_m)
            { // same month
                if (d < earliest_date_d)
                {
                    earliest_date_d = d, earliest_date_m = m, earliest_date_y = y;
                }
            }
        }
    }

    printf("%d/%d/%.2d is the earliest date\n", earliest_date_m, earliest_date_d, earliest_date_y);

    return 0;
}