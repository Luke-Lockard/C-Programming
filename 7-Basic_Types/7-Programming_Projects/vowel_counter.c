/* Counts the number of vowels in a sentece */

#include <stdio.h>
#include <ctype.h>

int main(void)
{
    char ch;
    int num_vowels = 0;

    printf("Enter a sentence: ");
    while ((ch = tolower(getchar())) != '\n') {
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
            num_vowels++;
    }

    printf("Your sentence contains %d vowels.\n", num_vowels);

    return 0;
}