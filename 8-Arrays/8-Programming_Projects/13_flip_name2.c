/* Takes a first name and last name entered by user
 * and displays the last name, comma, first iniial,
 * followed by a period.
 * User's input may contain extra spaces before the 
 * first name, between the first and last name, and 
 * after the last name.
 * 
 * v2 - program labels its output (using arrays to accomplish this)
 */

#include <stdio.h>

int main(void)
{
    char first_initial, ch;
    int i;
    char last_name[20];

    printf("Enter a first and last name: ");
    while ((first_initial = getchar()) == ' ') /* skips blanks */
        ;

    while((ch = getchar()) != ' ') /* skips rest of first name */
        ;

    while ((ch = getchar()) == ' ') /* skips blanks */
        ;

    i = 0;
    last_name[i] = ch;
    i++;
    while ((ch = getchar()) != ' ' && ch != '\n' && i < 20) {
        last_name[i] = ch;
        i++;
    }
    last_name[i] = ch;

    for (i = 0; i < 20 && last_name[i] != '\n'; i++) {
        printf("%c", last_name[i]);
    }

    // print comma, first initial and period
    printf(", %c.\n", first_initial);

    return 0;

}