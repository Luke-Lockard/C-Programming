/* 
 * Uses Newton's method to compute the square root of a positive floating-point
 * number.
 * Let x be the numbe entered by the user.
 * Newtons method requires an initial guess y for the square root of x (we'll
 * use y = 1).
 * Successive guesses are found by computing the average of y and x/y.
 * Have the program terminate when the absolute value of the difference between
 * the old value of y and the new value of y is less than the product of .00001 
 * and y.
 * Hint: Call the fabs function to find the absolute value of a double. (You'll
 * need to include the <math.h> header to use fabs.)
 */

#include <stdio.h>
#include <math.h>

int main(void)
{
    double x, y = 1, old_y;

    printf("Enter a positive number: ");
    scanf("%lf", &x);

    do {
        old_y = y;
        // y becomes avg of y and x/y
        y = (x/y + y) / 2;
    } while (fabs(old_y - y) > (0.00001 * y));
    
    printf("Square root: %lf\n", y);

    return 0;
}