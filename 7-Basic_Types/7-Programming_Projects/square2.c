/* Prints a table of squares using a for statement */
/* When i is type int, i * i fails when n is: 46341 */
/* When i is type short, i * i fails when n is: 182 */
/* When i is type long, i * i fails when n is: 3038646415? */

#include <stdio.h>

int main(void)
{
    // int i, n;
    short i, n;
    // long int i, n;

    printf("This program prints a table of squares.\n");
    printf("Enter number of entries in table: ");
    // scanf("%d", &n);
    scanf("%hd", &n);
    // scanf("%ld", &n);

    // for short int
    printf("%10hd%10hd\n", n, n * n);

    // for int
    /*
    for (i = 1; i <= n; i++) {
        printf("%15d%20d\n", i, i * i);
    }
    */

    // for long int
    // printf("%20ld%25ld\n", n, n * n);

    return 0;
}