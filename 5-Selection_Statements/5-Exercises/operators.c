#include <stdio.h>

int main(void)
{
    // 1a
    int i = 2, j = 3;
    int k = i * j == 6; // k = ( (i * j) == 6 ) evaluates to true
    printf("%d\n", k);  // 1

    // 1b
    i = 5; j = 10; k = 1;
    printf("%d\n", k > i < j); // equivalent to (k < i) < j => (1 < 5) < 10 => 1 < 10 => 1

    // 1c
    i = 3; j = 2; k = 5;
    printf("%d\n", i < j == j > k); // (i < j) == (j > k) => 0 == 0 => 1

    // 1d
    i = 3; j = 4; k = 5;
    printf("%d\n\n", i % j + i < k); // ((i % j) + i) < k => (3 + 3) < 5 => 0


    // 2a
    i = 10; j = 5;
    printf("%d\n", !i < j); // !(i < j) => !0 => 1  OR  !i < j => 0 < j => 1 

    // 2b
    i = 2; j = 1;
    printf("%d\n", !!i + !j); // 1 + 0 => 1

    // 2c
    i = 5; j = 0; k = -5;
    printf("%d\n", i && j || k); // => 0 || -5 => 1

    // 2d
    i = 1; j = 2; k = 3;
    printf("%d\n\n", i < j || k); // 1 || -5 => 1


    // 3a
    i = 3; j = 4; k = 5;
    printf("%d, ", i < j || ++j < k); // Doesn't increment j before evaluating i < j => 1
    printf("%d %d %d\n", i, j, k);

    // 3b
    i = 7; j = 8; k = 9;
    printf("%d, ", i - 7 && j++ < k); // Doesn't increment j before evaluating i - 7 => 0
    printf("%d %d %d\n", i, j, k);

    // 3c
    i = 7; j = 8; k = 9;
    printf("%d, ", (i = j) || (j = k)); // Doesn't set j = k before evaluating (i = j) => 8 which evaluates to true (1)
    printf("%d %d %d\n", i, j, k);

    // 3d
    i = 1; j = 1; k = 1;
    printf("%d, ", ++i || ++j && ++k); // i gets incremented to 2, which evaluates the whole expression to true before j or k get incremented
    printf("%d %d %d\n", i, j, k);


    // 4
    

    return 0;
}