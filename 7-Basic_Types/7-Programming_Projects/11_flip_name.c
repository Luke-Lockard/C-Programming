/* Takes a first name and last name entered by user
 * and displays the last name, comma, first iniial,
 * followed by a period.
 * User's input may contain extra spaces before the 
 * first name, between the first and last name, and 
 * after the last name.
 */

#include <stdio.h>

int main(void)
{
    char first_initial, ch;

    printf("Enter a first and last name: ");
    while ((first_initial = getchar()) == ' ') /* skips blanks */
        ;

    while((ch = getchar()) != ' ') /* skips rest of first name */
        ;

    while ((ch = getchar()) == ' ') /* skips blanks */
        ;

    /* Print last name */
    putchar(ch);
    while ((ch = getchar()) != ' ' && ch != '\n')
        putchar(ch);

    // print comma, first initial and period
    printf(", %c.\n", first_initial);

    return 0;

}