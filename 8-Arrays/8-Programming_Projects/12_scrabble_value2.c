/* Computes the value of a word by summing the values of its letters */

#include <stdio.h>
#include <ctype.h>

int main(void)
{
    char ch;
    int score = 0;
    
    int values[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

    printf("Enter a word: ");

    while ((ch = toupper(getchar())) != '\n') {
        score += values[ch - 'A'];
    }

    printf("Scrabble value: %d\n", score);

    return 0;
}