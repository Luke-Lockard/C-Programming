/* 
 * Prints an n x n magic square (a square arrangement of the numbers 1, 2, ...,
 * n^2 in which the sums of the rows, columns, and diagonals are all the same).
 * The user will specify the value of n.
 * 
 * Store the magic square in a two-dimensional array.
 * Start by placing the number 1 in the middle of row 0. Place each of the
 * remaining numbers 2, 3, ..., n^2 by moving up one row and over one column.
 * Any attempt to go outside the  bounds of the array should "wrap around" to
 * the opposite side of the array.
 * If row is -1, store in row n - 1.
 * If column is n, store in column 0.
 * 
 * If a particular array element is already occupied, put the number directly
 * below the previously stored number.
 * 
 * If your compiler supports variable length arrays, declare the array to have
 * n rows and n columns. If not, declare it to have 99 rows and 99 columns.
 */

#include <stdio.h>


int main(void)
{
    int i, j, next_i, next_j, k, n;

    printf("This program creates a magic square of a specified size.\nThe size must be an odd number between 1 and 99.\nEnter size of magic square: ");
    scanf("%d", &n);

    int magic_square[n][n];

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++)
            magic_square[i][j] = 0;
    }

    // printf("Starter:\n");
    // for (int x = 0; x < n; x++) {
    //     for (int y = 0; y < n; y++)
    //         printf("%5d", magic_square[x][y]);
    //     printf("\n");
    // }
    // printf("\n");

    i = 0, j = n / 2;
    for (k = 1; k <= (n * n); k++) {
        
        magic_square[i][j] = k;

        next_i = i - 1;
        next_j = j + 1;
        if (next_i < 0) next_i = n - 1;
        if (next_j >= n) next_j = 0;

        if (magic_square[next_i][next_j] != 0) {
            i++;
            if (i >= n) i = 0;
        } else {
            i--;
            j++;
            if (i < 0) i = n - 1;
            if (j >= n) j = 0;
        }
    }

    // printf("Iteration %d: [%d][%d]\n", k, i, j);
    for (int x = 0; x < n; x++)
    {
        for (int y = 0; y < n; y++)
            printf("%5d", magic_square[x][y]);
        printf("\n");
    }

    return 0;
}