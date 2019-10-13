/* Converts 12-hour time to 24-hour time */

#include <stdio.h>

int main(void)
{
    int hours, minutes;
    char ch1, ch2;

    printf("Enter a 12-hour time: ");
    scanf("%d:%d %c%c", &hours, &minutes, &ch1, &ch2);

    if (ch1 == 'P' || ch1 == 'p')
        hours += 12;
    
    printf("Equivalent 24-hour time: %d:%d\n", hours, minutes);

    return 0;
}