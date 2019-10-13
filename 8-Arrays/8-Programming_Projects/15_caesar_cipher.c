/* 
 * Encrypts a message using a Caesar cipher.
 * User enters message to be encrypted and the shift amount.
 */

#include <stdio.h>
#include <ctype.h>

#define N 80

int main(void)
{
    char message[N];
    char ch;
    int shift_amnt, i;

    printf("Enter message to be encrypted: ");

    for (i = 0; i < N; i++) {
        ch = getchar();
        message[i] = ch;
        if (ch == '\n')
            break;
    }

    printf("Enter shift amoung (1-25): ");
    scanf("%d", &shift_amnt);

    printf("Encrypted message: ");
    for (i = 0; i < N; i++) {
        ch = message[i];
        if (ch == '\n')
            break;
        // if (ch >= 'A' && ch <= 'Z')
        if (isupper(ch))
            putchar(((ch - 'A') + shift_amnt) % 26 + 'A');
        // else if (ch >= 'a' && ch <= 'z')
        else if (islower(ch))
            putchar(((ch - 'a') + shift_amnt) % 26 + 'a');
        else
            putchar(ch);
    }
    printf("\n");

    return 0;
}