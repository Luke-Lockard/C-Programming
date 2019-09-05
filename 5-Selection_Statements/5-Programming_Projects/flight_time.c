/* Gives closest departure time of flight given a 24-hour time by user */

#include <stdio.h>

int main(void) {
    int hours, minutes, min_since_midnight,
        //  depart_hr, depart_min, depart_period, arrive_hr, arrive_min, arrive_period;
        depart_time, depart_period, arrival_time;

    // departure times converted to minutes since midnight
    int 
    dp1 = 8 * 60, 
    dp2 = 9 * 60 + 43,
    dp3 = 11 * 60 + 19,
    dp4 = 12 * 60 + 47,
    dp5 = 14 * 60,
    dp6 = 15 * 60 + 45,
    dp7 = 19 * 60,
    dp8 = 21 * 60 + 45;

    printf("Enter a 24-hour time: ");
    scanf("%d:%d", &hours, &minutes);

    // Entered time converted to minutes since midnight
    min_since_midnight = hours * 60 + minutes;

    if (min_since_midnight <= dp1)
    { // 8:00
        printf("Closest departure time is 8:00 a.m., arriving at 10:16 a.m.\n");
    }
    else if (min_since_midnight <= dp2)
    {
        printf("Closest departure time is 9:43 a.m., arriving at 11:52 a.m.\n");
    }
    else if (min_since_midnight <= dp3)
    {
        printf("Closest departure time is 11:19 a.m., arriving at 1:31 p.m.\n");
    }
    else if (min_since_midnight <= dp4)
    {
        printf("Closest departure time is 12:47 p.m., arriving at 3:00 p.m.\n");
    }
    else if (min_since_midnight <= dp5)
    {
        printf("Closest departure time is 2:00 p.m., arriving at 4:08 p.m.\n");
    }
    else if (min_since_midnight <= dp6)
    {
        printf("Closest departure time is 3:45 p.m., arriving at 5:55 p.m.\n");
    }
    else if (min_since_midnight <= dp7)
    {
        printf("Closest departure time is 7:00 p.m., arriving at 9:20 p.m.\n");
    }
    else
    {
        printf("Closest departure time is 9:45 p.m., arriving at 11:58 p.m.\n");
    }

    return 0;
}