/*
 * Reverse Polish Notation calculator 
 * In this notation, operators are placed after their operands instead of 
 * between their operands.
 * 
 * Use a stack. When an operand is encounterd, push it onto the stack.
 * When an operator is encountered, pop its operands off the stack, perform the 
 * operation, then push the result onto the stack.
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define STACK_SIZE 100

/* external variables */
int contents[STACK_SIZE];
int top = 0;

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
    
    char ch;
    int operand1, operand2, result;

    for (;;) {
        make_empty();

        printf("Enter an RPN expression: ");
        for (;;) {
            scanf(" %c", &ch);

            if (ch == '=') break;

            switch (ch)
            {
                case 'q':
                    exit(EXIT_SUCCESS);
                    break;
                case '+':
                    operand2 = pop();
                    operand1 = pop();
                    result = operand1 + operand2;
                    push(result);
                    break;
                case '-':
                    operand2 = pop();
                    operand1 = pop();
                    result = operand1 - operand2;
                    push(result);
                    break;
                case '*':
                    operand2 = pop();
                    operand1 = pop();
                    result = operand1 * operand2;
                    push(result);
                    break;
                case '/':
                    operand2 = pop();
                    operand1 = pop();
                    result = operand1 / operand2;
                    push(result);
                    break;
                case '0':
                    push(0);
                    break;
                case '1':
                    push(1);
                    break;
                case '2':
                    push(2);
                    break;
                case '3':
                    push(3);
                    break;
                case '4':
                    push(4);
                    break;
                case '5':
                    push(5);
                    break;
                case '6':
                    push(6);
                    break;
                case '7':
                    push(7);
                    break;
                case '8':
                    push(8);
                    break;
                case '9':
                    push(9);
                    break;
                default:
                    break;
            }
        }

        printf("Value of expression: %d\n", pop());
        
    }
    

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
    if (is_empty())
    {
        stack_underflow();
        return '0';
    }
    else
        return contents[--top];
}

void stack_overflow(void)
{
    printf("Expression is too complex\n");
    exit(EXIT_SUCCESS);
}

void stack_underflow(void)
{
    printf("Not enough operands in expression\n");
    exit(EXIT_SUCCESS);
}