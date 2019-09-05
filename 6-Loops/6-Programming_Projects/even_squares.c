/* Given a number n, prints all even squares between 1 and n */

#include <stdio.h>

int main(void)
{
    int n;

    printf("Enter a number: ");
    scanf("%d", &n);

    int i, square;
    for (i = 2, square = i * i; square < n; i++) {
        printf("%d\n", square);
    }

    return 0;
}