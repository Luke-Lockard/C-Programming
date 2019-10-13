/* 
 * Reverses the words in a sentence.
 * 
 * Hint: use a loop to read the characters one by one and store them in a
 * one-dimensional char array. Have the loop stop at a period, question mark,
 * or exclamation point (the t"terminating character"), which is saved in a
 * separate char variable. Then use a second loop to search backward through
 * the array for the beginning of the last word. Print the last word, then
 * search backward for the next-to-last word. Repeat until the beginning of the
 * array is reached. Finally, print the terminating character.
 */

#include <stdio.h>

#define N 100

int main(void)
{
    char sentence[N];
    char ch, terminating_ch;
    int i = 0, j, end_word;

    printf("Enter a sentence: ");

    while ((ch = getchar()) != '\n') {
        if (ch == '.' || ch == '?' || ch == '!') {
            terminating_ch = ch;
            break;
        }

        sentence[i] = ch;
        i++;
    }
    

    // add a ' ' at end of sentence in array
    sentence[i] = ' ';

    // printf("End ch: '%c'\n", sentence[i]);

    // for (int x = 0; x < N; x++)
    //     printf("%c", sentence[x]);
    // printf("\n");

    end_word = i;
    while (i >= -1) {
        if (sentence[i] == ' ' || i == -1) {
            for (j = i + 1; j < end_word; j++) {
                printf("%c", sentence[j]);
            }
            if (i != -1) printf(" ");
            end_word = i;
        }
        i--;
    }
    printf("%c\n", terminating_ch);

    return 0;
}