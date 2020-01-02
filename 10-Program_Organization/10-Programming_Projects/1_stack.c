/* 
 * Implements a stack that takes characters.
 * Main method uses stack to reads series of parenthese and/or braces from the
 * user and indicates whether or not they are properly nested.
 */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define STACK_SIZE 100

/* external variables */
int contents[STACK_SIZE];
int top = 0;
bool is_properly_nested = true;

/* prototypes */
void make_empty(void);
bool is_empty(void);
bool is_full(void);
void push(char c);
char pop(void);
void stack_overflow(void);
void stack_underflow(void);

int main(void)
{
    char ch, popped;

    printf("Enter a series of parenthese and/or braces: ");
    // read in each char until the user hits enter
    while ((ch = getchar()) != '\n') {
        // if left parentheses or brace, push onto stack
        if (ch == '(' || ch == '{')
            push(ch);
        // if right parentheses or brace, pop the stack and check if the item popped is a matching parentheses or brace
        else
        {
            // pop() will call stack_underflow() if stack is ever empty when called
            // if stack_underflow is ever called, not nested properly
            popped = pop();
            // If not a match, not nested properly
            if ((ch == '(' && popped != ')') || (ch == '{' && popped != '}'))
                is_properly_nested = false;
        }
    }

    // when the '\n' character is reached, if the stack isn't empty, the parenthese/braces aren't matched.
    if (!is_empty())
        is_properly_nested = false;

    if (is_properly_nested)
        printf("Parentheses/braces are nested properly\n");
    else
        printf("Parentheses/braces are NOT nested properly\n");

    return 0;
}

void make_empty(void)
{
    top = 0;
}

bool is_empty(void)
{
    return top == 0;
}

bool is_full(void)
{
    return top == STACK_SIZE;
}

void push(char c)
{
    if (is_full())
        stack_overflow();
    else
        contents[top++] = c;
}

char pop(void)
{
    if (is_empty()) {
        stack_underflow();
        return '0';
    }
    else
        return contents[--top];
}

void stack_overflow(void)
{
    printf("Stack overflow\n");
    exit(EXIT_SUCCESS);
}

void stack_underflow(void)
{
    is_properly_nested = false;
}