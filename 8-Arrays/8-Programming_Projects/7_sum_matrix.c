/* Reads a 5 x 5 array, then prints row sums and column sums */

#include <stdio.h>

#define ROWS 5
#define COLS 5

int main(void)
{
    int a[ROWS][COLS];
    int row, col, sum;

    for (row = 0; row < ROWS; row++) {
        printf("Enter row %d: ", row + 1);
        scanf("%d %d %d %d %d", &a[row][0], &a[row][1], &a[row][2], &a[row][3], &a[row][4]);
    }
    
    printf("\nRow totals: ");
    for (row = 0; row < ROWS; row++) {
        sum = 0;
        for (col = 0; col < COLS; col++) {
            sum += a[row][col];
        }
        printf(" %d", sum);
    }
    
    printf("\nColumn totals: ");
    for (col = 0; col < COLS; col++) {
        sum = 0;
        for (row = 0; row < ROWS; row++) {
            sum += a[row][col];
        }
        printf(" %d", sum);
    }
    printf("\n");
    
    return 0;
}