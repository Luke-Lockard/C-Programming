/* 
 * Simulates the game of craps.
 * Played with two dice.
 * On the first roll, player wins if 7 or 11 rolled.
 * Player loses if sum is 2, 3, or 12.
 * Any other roll is called the "point" and the game continues.
 * On each subsequent roll, the player wins if they roll the point again.
 * Player loses by rolling a 7. Any other roll is ignored and the game 
 * continues.
 * At the end of the game, player is asked if they want to play again.
 * If the user enteres a response other than y or Y, the program will display
 * the number of wins and losses and then terminate.
 */

#include <stdio.h>
#include <stdbool.h>    /* C99 only */
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

int roll_dice(void);
bool play_game(void);

int main(void)
{
    srand((unsigned) time(NULL));

    int wins =  0, losses = 0;
    char ch;

    for (;;) {
        play_game() ? wins++ : losses++;

        printf("\nPlay again? ");
        scanf(" %c", &ch);
        ch = toupper(ch);

        if (ch != 'Y')
            break; 
    }
    
    printf("\nWins: %d\tLosses: %d\n", wins, losses);

    return 0;
}

int roll_dice(void)
{
    return (rand() % 6) + 1 + (rand() % 6) + 1;
}

bool play_game(void)
{
    int roll, point;

    roll = roll_dice();
    printf("\nYou rolled: %d\n", roll);

    if (roll == 7 || roll == 11){
        printf("You win!\n");
        return true;
    } else if (roll == 2 || roll == 3 || roll == 12) {
        printf("You lose!\n");
        return false;
    }

    point = roll;

    printf("Your point is %d\n", point);

    for (;;) {
        roll = roll_dice();
        printf("You rolled: %d\n", roll);
        
        if (roll == 7) {
            printf("You lose!\n");
            return false;
        }

        if (roll == point) {
            printf("You win!\n");
            return true;
        }
    }
    
    return false;
}