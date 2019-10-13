/* 
 * Translates an alphabetic phone number into numeric form.
 * v2 - program labels its output
 */

#include <stdio.h>

#define N 15

int main(void)
{
    char ch;
    char phone_num[N];
    int i = 0;

    printf("Enter phone number: ");
    
    while ((ch = getchar()) != '\n') {
        switch(ch) {
            case 'A': case 'B': case 'C':
                phone_num[i] = '2';
                // putchar('2');
                break;
            case 'D': case 'E': case 'F':
                phone_num[i] = '3';
                // putchar('3');
                break;
            case 'G': case 'H': case 'I':
                phone_num[i] = '4';
                // putchar('4');
                break;
            case 'J': case 'K': case 'L':
                phone_num[i] = '5';
                // putchar('5');
                break;
            case 'M': case 'N': case 'O':
                phone_num[i] = '6';
                // putchar('6');
                break;
            case 'P': case 'R': case 'S':
                phone_num[i] = '7';
                // putchar('7');
                break;
            case 'T': case 'U': case 'V':
                phone_num[i] = '8';
                // putchar('8');
                break;
            case 'W': case 'X': case 'Y':
                phone_num[i] = '9';
                // putchar('9');
                break;
            default:
                phone_num[i] = ch;
                // putchar(ch);
                break;
        }
        i++;
    }

    printf("In numeric form: ");
    for (i = 0; i < N; i++)
        putchar(phone_num[i]);
    printf("\n");
    
    return 0;
}