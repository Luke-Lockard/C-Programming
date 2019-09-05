/* Converts a numerical grade to a letter grade */

#include <stdio.h>

int main(void) {
    int numerical_grade, tens, ones;

    printf("Enter a numerical grade: ");
    scanf("%d", &numerical_grade);

    tens = numerical_grade / 10;
    ones = numerical_grade % 10;

    if (numerical_grade > 100 || numerical_grade < 0) {
        printf("ERROR: Numerical grade is out of range (0 - 100).\n");
        return 0;
    }

    switch (tens)
    {
    case 10:
    case 9:
        printf("A\n");
        break;
    case 8:
        printf("B\n");
        break;
    case 7:
        printf("C\n");
        break;
    case 6:
        printf("D\n");
        break;
    default:
        printf("F\n");
        break;
    }

    return 0;
}