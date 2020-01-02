/* 
 * Tests whether two words are anagrams (permutations of the same letters)
 * 
 * Version 2
 * Use functions
 */

#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

#define N 26

void read_word(int counts[26]);
bool equal_array(int counts[26], int counts2[26]);

int main(void)
{
    int counts[N] = {0};
    int counts2[N] = {0};
    char ch;
    bool is_anagram = true;

    printf("Enter first word: ");

    read_word(counts);

    printf("Enter second word: ");
    
    read_word(counts2);

    if (equal_array(counts, counts2))
        printf("The words are anagrams.\n");
    else
        printf("The words are not anagrams.\n");

    return 0;
}

void read_word(int counts[26])
{
    char ch;

    while ((ch = getchar()) != '\n')
    {
        if (isalpha(ch))
            counts[tolower(ch) - 'a']++;
    }
}

bool equal_array(int counts1[26], int counts2[26])
{
    for (int i = 0; i < N; i++)
    {
        if (counts1[i] != counts2[i])
        {
            return false;
        }
    }

    return true;
}