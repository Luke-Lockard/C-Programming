/* Tests whether two words are anagrams (permutations of the same letters) */

#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

#define N 26

int main(void)
{
    int letters[N] = {0};
    char ch;
    bool is_anagram = true;

    printf("Enter first word: ");

    while ((ch = getchar()) != '\n') {
        if (isalpha(ch))
            letters[tolower(ch) - 'a']++;
    }

    printf("Enter second word: ");
    
    while ((ch = getchar()) != '\n') {
        if (isalpha(ch))
            letters[tolower(ch) - 'a']--;
    }

    for (int i = 0; i < N; i++) {
        if (letters[i] != 0) {
            is_anagram = false;
            break;
        }
    }

    if (is_anagram)
        printf("The words are anagrams.\n");
    else
        printf("The words are not anagrams.\n");

    return 0;
}
