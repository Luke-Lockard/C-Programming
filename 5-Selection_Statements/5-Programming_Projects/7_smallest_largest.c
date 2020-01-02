/* Finds largest and smallest of four integers */

#include <stdio.h>

int main(void) {
    int i1, i2, i3, i4, small1, large1, small2, large2, smallest, largest;

    printf("Enter four integers: ");
    scanf("%d %d %d %d", &i1, &i2, &i3, &i4);

    if (i1 > i2) {
        large1 = i1;
        small1 = i2;
    } else {
        large1 = i2;
        small1 = i1;
    }

    if (i3 > i4) {
        large2 = i3;
        small2 = i4;
    } else {
        large2 = i4;
        small2 = i3;
    }

    if (large1 > large2) {
        printf("Largest: %d\n", large1);
    } else {
        printf("Largest: %d\n", large2);
    }

    if (small1 < small2) {
        printf("Smallest: %d\n", small1);
    } else {
        printf("Smallest: %d\n", small2);
    }

    return 0;
}