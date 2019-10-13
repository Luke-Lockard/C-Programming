/* Gives closest departure time of flight given a 24-hour time by user */

#include <stdio.h>

int main(void)
{
    int hours, minutes, min_since_midnight,
        //  depart_hr, depart_min, depart_period, arrive_hr, arrive_min, arrive_period;
        depart_time, depart_period, arrival_time;
    char ch1, ch2;

    // departure times converted to minutes since midnight
    int dp1 = 8 * 60,       //  8:00 am
        dp2 = 9 * 60 + 43,  //  9:43 am
        dp3 = 11 * 60 + 19, // 11:19 am
        dp4 = 12 * 60 + 47, // 12:47 pm
        dp5 = 14 * 60,      //  2:00 pm
        dp6 = 15 * 60 + 45, //  3:45 pm
        dp7 = 19 * 60,      //  7:00 pm
        dp8 = 21 * 60 + 45; //  9:45 pm


    printf("Enter a 12-hour time, with AM or PM: ");
    scanf("%d:%d %c%c", &hours, &minutes, &ch1, &ch2);

    // Entered time converted to minutes since midnight
    if (ch1 == 'P' || ch1 == 'p')
    {
        min_since_midnight = (hours + 12) * 60 + minutes;
    } else {
        min_since_midnight = hours * 60 + minutes;
    }

    if (min_since_midnight <= dp1) // 8:00
    { 
        printf("Closest departure time is 8:00 a.m., arriving at 10:16 a.m.\n");
    }
    else if (min_since_midnight <= dp2) //  9:43 am
    {
        printf("Closest departure time is 9:43 a.m., arriving at 11:52 a.m.\n");
    }
    else if (min_since_midnight <= dp3) // 11:19 am
    {
        printf("Closest departure time is 11:19 a.m., arriving at 1:31 p.m.\n");
    }
    else if (min_since_midnight <= dp4) // 12:47 pm
    {
        printf("Closest departure time is 12:47 p.m., arriving at 3:00 p.m.\n");
    }
    else if (min_since_midnight <= dp5) //  2:00 pm
    {
        printf("Closest departure time is 2:00 p.m., arriving at 4:08 p.m.\n");
    }
    else if (min_since_midnight <= dp6) //  3:45 pm
    {
        printf("Closest departure time is 3:45 p.m., arriving at 5:55 p.m.\n");
    }
    else if (min_since_midnight <= dp7) //  7:00 pm
    {
        printf("Closest departure time is 7:00 p.m., arriving at 9:20 p.m.\n");
    }
    else //  9:45 pm
    {
        printf("Closest departure time is 9:45 p.m., arriving at 11:58 p.m.\n");
    }

    return 0;
}