/* Computes the value of a word by summing the values of its letters */

#include <stdio.h>
#include <ctype.h>

int main(void)
{
    char ch;
    int score = 0;

    printf("Enter a word: ");

    while ((ch = toupper(getchar())) != '\n') {
        switch(ch) {
            case 'A': case 'E': case 'I': case 'L':
            case 'N': case 'O': case 'R': case 'S':
            case 'T': case 'U':
                score += 1;
                break;
            case 'D': case 'G':
                score += 2;
                break;
            case 'B': case 'C': case 'M': case 'P':
                score += 3;
                break;
            case 'F': case 'H': case 'V': case 'W': case 'Y':
                score += 4;
                break;
            case 'K':
                score += 5;
                break;
            case 'J': case 'X':
                score += 8;
                break;
            case 'Q': case 'Z':
                score += 10;
                break;
        }
    }

    printf("Scrabble value: %d\n", score);

    return 0;
}