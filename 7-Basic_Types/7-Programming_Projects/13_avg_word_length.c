/* Calculates the average word length for a sentence.
 * Punctuation considered to be part of the word it's attached to.
 * Display average length to one decimal place.
 */

#include <stdio.h>

int main(void)
{
    float avg;
    int char_count = 0, word_count = 0;
    char ch;

    printf("Enter a sentence: ");

    while ((ch = getchar()) != '\n') {
        if (ch == ' ') {
            word_count++;
            printf("%c\tword count, %d\n", ch, word_count);
        } else {
            char_count++;
            printf("%c\t\t\tchar count: %d\n", ch, char_count);
        }
        
    }
    word_count++;   // account for last word.

    avg = (float) char_count / word_count;

    printf("Average word length: %.1f\n", avg);

    return 0;
}