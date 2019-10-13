/* Gives closest departure time of flight given a 24-hour time by user */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define DEPARTURE_TIMES_SIZE (int) (sizeof(departure_times) / sizeof(departure_times[0]))
#define ARRIVAL_TIMES_SIZE (int) (sizeof(arrival_times) / sizeof(arrival_times[0]))

int main(void) {
    int hours, minutes, min_since_midnight,
        depart_time, closest_time, difference, temp,
        dep_hours, dep_minutes,
        arr_hours, arr_minutes;
    char dep_period, arr_period;

    // departure times converted to minutes since midnight
    int departure_times[] = {
        8 * 60, 
        9 * 60 + 43,
        11 * 60 + 19,
        12 * 60 + 47,
        14 * 60,
        15 * 60 + 45,
        19 * 60,
        21 * 60 + 45
    };

    // arrival times converted to minutes since midnight
    int arrival_times[] = {
        10 * 60 + 16,
        11 * 60 + 52,
        13 * 60 + 31,
        15 * 60,
        16 * 60 + 8,
        17 * 60 + 55,
        21 * 60 + 20,
        23 * 60 + 58
    };

    printf("Enter a 24-hour time: ");
    scanf("%d:%d", &hours, &minutes);

    // Entered time converted to minutes since midnight
    min_since_midnight = hours * 60 + minutes;

    difference = 1000;
    for (depart_time = 0; depart_time < DEPARTURE_TIMES_SIZE; depart_time++) {
        temp = abs(departure_times[depart_time] - min_since_midnight);
        // printf("temp: %d\n", temp);
        if (temp < difference) {
            difference = temp;
            closest_time = depart_time;
        } else if (temp > difference) {
            break;
        }
    }

    temp = departure_times[closest_time];
    dep_hours = temp / 60;
    dep_minutes = temp % 60;
    dep_period = dep_hours >= 12 ? 'P' : 'A';
    dep_hours = dep_hours > 12 ? dep_hours - 12 : dep_hours;
    
    temp = arrival_times[closest_time];
    arr_hours = temp / 60;
    arr_minutes = temp % 60;
    arr_period = arr_hours >= 12 ? 'P' : 'A';
    arr_hours = arr_hours > 12 ? arr_hours - 12 : arr_hours;

    printf("Closest departure time is %d:%.2d %c.M. , arriving at %d:%.2d %c.M.\n", dep_hours, dep_minutes, dep_period, arr_hours, arr_minutes, arr_period);

    return 0;
}