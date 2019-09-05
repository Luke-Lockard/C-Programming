/* Computes the volume of a sphere given the radius */

#include <stdio.h>

#define pi 3.14159f

int main(void)
{
    int radius;
    float volume;

    printf("Enter radius of sphere (meters): ");
    scanf("%d", &radius);

    volume = (4.0f / 3.0f) * pi * (radius * radius * radius);

    printf("Volume: (cubic meters) %.2f\n", volume);

    return 0;
}