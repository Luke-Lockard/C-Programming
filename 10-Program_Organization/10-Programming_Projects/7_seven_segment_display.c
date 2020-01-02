/* 
 * Prompts user for a number and then displays the number using characters to
 * simulate the effect of a seven-segment display
 * 
 * Ignore all characters other than numbers
 * Ignore numbers after MAX_DIGITS
 * 
 *     0
 *     _
 *  5 |_| 1  6 is the middle
 *  4 |_| 2
 *     3
 */

#include <stdio.h>
#include <stdlib.h>

#define MAX_DIGITS 10

const int segments[10][7] = {
    {1, 1, 1, 1, 1, 1, 0},  // 0
    {0, 1, 1, 0, 0, 0, 0},  // 1
    {1, 1, 0, 1, 1, 0, 1},  // 2
    {1, 1, 1, 1, 0, 0, 1},  // 3
    {0, 1, 1, 0, 0, 1, 1},  // 4
    {1, 0, 1, 1, 0, 1, 1},  // 5
    {1, 0, 1, 1, 1, 1, 1},  // 6
    {1, 1, 1, 0, 0, 0, 0},  // 7
    {1, 1, 1, 1, 1, 1, 1},  // 8
    {1, 1, 1, 1, 0, 1, 1}   // 9
};
char digits[4][MAX_DIGITS * 4];

void clear_digits_array(void);
void process_digit(int digit, int position);
void print_digits_array(void);

int main(void) 
{
    char ch;
    int digit, position;

    for (;;) 
    {

        clear_digits_array();

        printf("Enter a number up to %d digits long: ", MAX_DIGITS);

        position = 0;
        while ((ch = getchar()) != '\n') 
        {
            if (position >= MAX_DIGITS) continue;

            switch (ch)
            {
            case 'q':
                exit(EXIT_SUCCESS);
                break;
            case '1':
                process_digit(1, position++);
                break;
            case '2':
                process_digit(2, position++);
                break;
            case '3':
                process_digit(3, position++);
                break;
            case '4':
                process_digit(4, position++);
                break;
            case '5':
                process_digit(5, position++);
                break;
            case '6':
                process_digit(6, position++);
                break;
            case '7':
                process_digit(7, position++);
                break;
            case '8':
                process_digit(8, position++);
                break;
            case '9':
                process_digit(9, position++);
                break;
            case '0':
                process_digit(0, position++);
                break;
            default:
                break;
            }
        }

        print_digits_array();
    }

    return 0;
}

/**
 * Store blank characters into all elements of the digits array
 */
void clear_digits_array(void)
{
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < MAX_DIGITS * 4; j++)
            digits[i][j] = ' ';
}

/**
 * Store the seven-segment representation of digit into a specified position in
 * the digits array (position range from 0 to MAX_DIGITS - 1)
 */
void process_digit(int digit, int position)
{
    // get the 7 segment representation of the digit
    //int segment[7];
    // memcpy(segments[digit], segment, sizeof(segments[digit]));

    // if segment is on, place the appropriate character
    if (segments[digit][0])
        digits[0][position * 4 + 1] = '_';

    if (segments[digit][1])
        digits[1][position * 4 + 2] = '|';

    if (segments[digit][2])
        digits[2][position * 4 + 2] = '|';

    if (segments[digit][3])
        digits[2][position * 4 + 1] = '_';

    if (segments[digit][4])
        digits[2][position * 4] = '|';

    if (segments[digit][5])
        digits[1][position * 4] = '|';

    if (segments[digit][6])
        digits[1][position * 4 + 1] = '_';
}

/**
 * Display the rows of the digits array, each on a single line
 */
void print_digits_array(void)
{
    for (int i = 0; i < 4; i ++) 
    {
        for (int j = 0; j < MAX_DIGITS * 4; j++)
            printf("%c", digits[i][j]);
        printf("\n");
    }

    printf("\n");
}