/* 
 * Asks user for series of integers, which it stores in an array. Then sorts
 * them with a function selection_sort.
 *
 * Selection Sort:
 * 1. Search the array to find the largest element, then move it to the last
 * position in the array.
 * 2. Call itself recursively to sort the first n - 1 elements of the array. 
*/

#include <stdio.h>

#define N 10

void selection_sort(int a[], int n);

int main(void)
{
    int a[N], i;

    printf("Enter a series of %d integers: ", N);
    for (i = 0; i < N; i++)
        scanf("%d", &a[i]);

    selection_sort(a, N);

    printf("In sorted order: ");
    for (i = 0; i < N; i++)
        printf("%d ", a[i]);
    printf("\n");

    return 0;
}

void selection_sort(int a[], int n)
{
    int largest = a[0], index = 0, i;

    for (i = 0; i < n; i++) {
        // printf("i: %d, a[i]: %d\n", i, a[i]);

        if (a[i] > largest) {
            largest = a[i];
            index = i;
            // printf("largest: %d, index: %d\n", largest, index);
        }
    }

    a[index] = a[n - 1];
    a[n - 1] = largest;

    // printf("a[%d]: %d\n\n", n - 1, a[n - 1]);

    if (n > 2)
        selection_sort(a, n - 1);
}