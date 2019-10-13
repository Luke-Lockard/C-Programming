/* "B1FF" filter reads a message entered by the user and translates it into
 * B1FF speak.
 * Convert message to upper-case,
 * substitute digits for certain letters
 * (A -> 4, B -> 8, E -> 3, I -> 1, O -> 0, S -> 5),
 * then append 10 or so exclamation marks.
 * Hint: store the original message in an array of characters, then go back
 * through the array, translating a printing characters one by one.
 */

#include <stdio.h>
#include <ctype.h>

#define N 100

int main(void)
{
    char message[N];  // assume the message is less than 100 characters long
    char ch;
    int index = 0;

    printf("Enter message: ");

    while ((ch = getchar()) != '\n') {
        message[index] = toupper(ch);
        index++;
    }

    // put the '\n' in the end (after last character) of the message array
    message[index] = ch;

    printf("In B1FF-speak: ");

    for (index = 0; index < N; index++) {
        ch = message[index];
        switch (ch) {
            case 'A': putchar('4'); break;
            case 'B': putchar('8'); break;
            case 'E': putchar('3'); break;
            case 'I': putchar('1'); break;
            case 'O': putchar('0'); break;
            case 'S': putchar('5'); break; 
            case '\n': goto END; break;
            default: putchar(ch); break;
        }
    }

    END:
    printf("!!!!!!!!!!!!\n");

    return 0;
}