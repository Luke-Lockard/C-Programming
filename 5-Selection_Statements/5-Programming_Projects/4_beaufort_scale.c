/* Asks user to enter a wind speed (in knots), then displays the corresponding description from a simplified version of the Beaufort Scale */

#include <stdio.h>

int main(void)
{
    int wind_speed;

    printf("Enter a wind speed (knots): ");
    scanf("%d", &wind_speed);

    if (wind_speed > 63) printf("Hurricane\n");
    else if (wind_speed > 48) printf("Storm\n");
    else if (wind_speed > 28) printf("Gale\n");
    else if (wind_speed > 4) printf("Breeze\n");
    else if (wind_speed > 1) printf("Light air\n");
    else printf("Calm\n");

    return 0;
}