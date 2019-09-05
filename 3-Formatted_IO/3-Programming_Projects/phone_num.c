/* Takes phone number in form (xxx) xxx-xxxx and displays in form xxx.xxx.xxxx */

#include <stdio.h>

int main(void)
{
    int area_code, three_digits, four_digits;

    printf("Enter phone number [(xxx) xxxx-xxxx]: ");
    scanf("(%d) %d-%d", &area_code, &three_digits, &four_digits);
    printf("You entered %.3d.%.3d.%.4d\n", area_code, three_digits, four_digits);
    
    return 0;
}