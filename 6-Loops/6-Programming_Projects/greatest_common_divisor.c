/* Given two integers, calculates & displays their greatest common divisor */

#include <stdio.h>

int main(void)
{
    int i, j, temp;

    printf("Enter two integers: ");
    scanf("%d %d", &i, &j);

    while (i > 0) {
        temp = j % i;
        j = i;
        i = temp;
    }

    printf("Greatest common divisor: %d\n", j);

    return 0;
}