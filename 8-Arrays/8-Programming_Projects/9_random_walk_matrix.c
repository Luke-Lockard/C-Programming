/*
 * Generates "random walk" across 10 x 10 array.
 * All characters initially '.'
 * Program randomly "walks" from element to element (up, down, left, right) one 
 * element at a time, never visiting the same element twice.
 * Visited elements marked 'A' to 'Z'.
 * Walk terminates at 'Z' or when it cannot move to another element (blocked by
 * edge and/or previously visited elements).
 * 
 * Hint: use the srand and rand functions to generate random numbers. Look at
 * the random number's remainder when divided by 4, and use remainder (0, 1, 2,
 * 3) to pick direction of the next move.
 * Before performing a move, check that (a) it won't go outside the array, and 
 * (b) doesn't go to an element that has already been assigned. If either
 * condition is violated, try moving in another direction. If all 4 directions
 * are blocked, program must terminate.
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define NUM_ROWS 10
#define NUM_COLS 10
#define TRAIL_SIZE (int) (sizeof(trail) / sizeof(trail[0]))

int main(void)
{
    char board[NUM_ROWS][NUM_COLS];
    /*
     = {
        {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
        {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
        {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
        {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
        {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
        {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
        {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
        {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
        {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
        {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'}
    };
    */
    char trail[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
    printf("TRAIL_SIZE: %d\n", TRAIL_SIZE);

    bool direction_open[] = {true, true, true, true};

    int x = 0, y = 0, move = 0, direction, tries;
    bool direction_found = false;

    int row, col;
    // Initialize board
    for (row = 0; row < NUM_ROWS; row++)
        for (col = 0; col < NUM_COLS; col++)
            board[row][col] = '.';

    srand((unsigned) time(NULL));

    while (move < TRAIL_SIZE) {
        board[y][x] = trail[move]; // mark trail
        move++;

        direction = rand() % 4; // pick random direction

        tries = 0;

        while (tries < 4) {
            // test direction
            switch (direction) {
                case 0: // left
                    if (x - 1 >= 0 && board[y][x - 1] == '.') {
                        x--;
                        goto NEXT;
                    } else {
                        tries++;
                        direction = (direction + 1) % 4;   // try next direction
                    }
                    break;
                case 1: // up
                    if (y - 1 >= 0 && board[y - 1][x] == '.') {
                        y--;
                        goto NEXT;
                    } else {
                        tries++;
                        direction = (direction + 1) % 4;   // try next direction
                    }
                    break;
                case 2: // right
                    if (x + 1 < 10 && board[y][x + 1] == '.') {
                        x++;
                        goto NEXT;
                    } else {
                        tries++;
                        direction = (direction + 1) % 4;   // try next direction
                    }
                    break;
                case 3: // down
                    if (y + 1 < 10 && board[y + 1][x] == '.') {
                        y++;
                        goto NEXT;
                    } else {
                        tries++;
                        direction = (direction + 1) % 4;   // try next direction
                    }
                    break;
            }
        }

        NEXT:
        if (tries == 4)
            goto END;

        /*
        printf("Move: %d\n", move);
        for (row = 0; row < NUM_ROWS; row++) {
            for (col = 0; col < NUM_COLS; col++)
                printf("%c ", board[row][col]);
            printf("\n");
        }
        printf("\n");
        */
    }

    END:
    // printf("Final result:\n");
    for (row = 0; row < NUM_ROWS; row++) {
        for (col = 0; col < NUM_COLS; col++)
            printf("%c ", board[row][col]);
        printf("\n");
    }
   
   return 0;
}