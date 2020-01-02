# 10.5 Organizing a C Program

For now, assume that a program fits into a single file. Chapter 15 shows how to organize a program that's split over several files.

So far we've seen a program that may contain the following:

- Preprocessing directives such as `#include` and `#define`

- Type definitions

- Declarations of external variables

- Function prototypes

- Function definitions

C only imposes a few rules on the order of these items: A preprocessing directive doesn't take effect until the line on which it appears. A type name can't be used until it's been defined. A variable can't be used until it's declared.

Although C isn't as picky about functions, it's strongly recommended that every function be defined or declared prior to its first call. (C99 makes this a requirement anyway.)

There are several ways to organize a program so that these rules are obeyed.

Here's one possible ordering:

- `#include` directives

- `#define` directives

- Type definitions

- Declarations of external variables

- Prototypes for functions other than `main`

- Definition of `main`

- Definitions of other functions

---

## `Program` Classifying a Poker Hand

Program will read & classify a poker hand.

Each card in hand has both a suit and a rank.

Aces high.

Program will read a hand of five cards, then classify the poker hand.

- straight flush

- four-of-a-kind

- full house

- flush

- straight

- three-of-a-kind

- tow pairs

- pair

- high card

If a hand falls into two or more categories, the program will pick the best one.

If the user enters an illegal card or the same card twice, the program will ignore the care, issue an error message, then request another card.

Entering 0 instead of a card will cause the program to terminate.

From this description of the program, we see that it has three tasks:

- Read a hand of five cards.

- Analyze the hand for pairs, straights, and so forth.

- Print the classification of the hand.

So we'll divide the program into three functions - `read_cards`, `analyze_hand`, and `print_result`.

`main` does nothing but call these functions in a continuous loop.

The functions need to share information, so we will use external variables. `read_cards` will store information about the hand into several external variables, `analyze_hand` will then examine these variables, storing its finding into other external variables for the benefit of `print_result`.

We can sketch an outline of the program:

```c
/* #include directives go here */

/* #define directives go here */

/* declarations of external variables go here */

/* prototypes */
void read_cards(void);
void analyze_hand(void);
void print_result(void);

/**********************************************************
 * main: Calls read_cards, analyze_hand, and print_result *
 *       repeatedly.                                      *
 **********************************************************/
int main(void)
{
    for(;;) {
        read_cards();
        analyze_hand();
        print_result();
    }
}

/**********************************************************
 * read_cards: Reads the cards into external variables;   *
 *             checks for bad cards and duplicate cards.  *
 **********************************************************/
void read_cards(void)
{

}

/**********************************************************
 * analyze_hand: Determines whether the hand contains a   *
 *               straight, a flush, four-of-a-kind        *
 *               and/or three-of-a-kind; determines the   *
 *               number of pairs; stores the result into  *
 *               external variables.                      *
 **********************************************************/
void analyze_hand(void)
{

}

/**********************************************************
 * print_result: Notifies the user of the result, using   *
 *               the external variables set by            *
 *               analyze_hand.                            *
 **********************************************************/
void print_result(void)
{

}
```

`analyze_hand` will need to know how many cards are in each rank and each suit. Suggests use of two arrays, `num_in_rank` and `num_in_suit`.

Need a third array `card_exists`, so that `read_cards` can detect duplicate cards. If `card_exists[r][s]` is `true`, the card already exists.

Both `read_cards` and `analyze_hand` will need access to `num_in_rank` and `num_in_suit` arrays, so they will be external variables.

The `card_exists` array is used only by `read_cards`, so it can be local to that function.

See `poker.c` for the complete program.